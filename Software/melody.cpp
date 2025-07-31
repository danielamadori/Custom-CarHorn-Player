#include "Melody.hpp"

static const struct NoteMap{unsigned short value; const char *name;} noteMap[] = {
        {NOTE_A4, "a4"}, {NOTE_A5, "a5"}, {NOTE_A6, "a6"}, {NOTE_A7, "a7"},
        {NOTE_AS4, "a#4"}, {NOTE_AS5, "a#5"}, {NOTE_B4, "b4"}, {NOTE_B5, "b5"},
        {NOTE_C4, "c4"}, {NOTE_C5, "c5"}, {NOTE_C6, "c6"},
        {NOTE_CS4, "c#4"}, {NOTE_CS5, "c#5"}, {NOTE_D4, "d4"},
        {NOTE_D5, "d5"}, {NOTE_D6, "d6"}, {NOTE_D7, "d7"},
        {NOTE_DS4, "d#4"}, {NOTE_DS5, "d#5"}, {NOTE_E4, "e4"},
        {NOTE_E5, "e5"}, {NOTE_E6, "e6"}, {NOTE_E7, "e7"},
        {NOTE_F4, "f4"}, {NOTE_F5, "f5"}, {NOTE_F6, "f6"},
        {NOTE_FS5, "f#5"}, {NOTE_FS6, "f#6"}, {NOTE_FS7, "f#7"},
        {NOTE_G4, "g4"}, {NOTE_G5, "g5"}, {NOTE_GS4, "g#4"},
        {NOTE_GS5, "g#5"}, {NOTE_GS7, "g#7"}, {0, "p"}
};

static const char* noteName(unsigned short note){
        for(unsigned int i=0;i<sizeof(noteMap)/sizeof(noteMap[0]);++i){
                if(noteMap[i].value==note) return noteMap[i].name;
        }
        return "p";
}

static String toRtttl(const String &name, unsigned short totalDuration, unsigned short length, unsigned short *notes, unsigned short *durations){
        String res = name + ":d=4,o=5,b=" + String(240000/totalDuration) + ":";
        for(unsigned short i=0;i<length;i++){
                res += String(durations[i]) + noteName(notes[i]);
                if(i < length-1) res += ",";
        }
        return res;
}

Melody::Melody(String name, unsigned short totalDuration, unsigned short length, unsigned short* notes, unsigned short* notesDuration){
        this->name = name;
        this->totalDuration = totalDuration;
        this->length = length;
        this->notes = notes;
        this->notesDuration = notesDuration;
        this->rtttl = toRtttl(name, totalDuration, length, notes, notesDuration);
}
	
void Melody::play(unsigned short pauseBetweenNotes){
        rtttl::begin(HORN, rtttl.c_str());
        while(!rtttl::done()){
                rtttl::play();
        }
}

short Melody::preview(unsigned short pauseBetweenNotes){
        rtttl::begin(BUZZER, rtttl.c_str());
        while(!hornButton()){
                if(rtttl::done())
                        return 2;
                if(encoder.clickListener())
                        return 0;
                if(encoder.valueListener()){
                        Serial.println("Cambio canzione");
                        return 1;
                }
                rtttl::play();
        }
        return 2;
}

String Melody::getName(void){
	return name;
}