#include "Melody.hpp"

Melody::Melody(String name, unsigned short totalDuration, unsigned short length, unsigned short* notes, unsigned short* notesDuration){
        this->name = name;
        this->totalDuration = totalDuration;
        this->length = length;
        this->notes = notes;
        this->notesDuration = notesDuration;

        freqs = new float[length];
        durations = new float[length];
        for(unsigned short i = 0; i < length; ++i){
                freqs[i] = (float)notes[i];
                durations[i] = 4.0f / notesDuration[i];
        }

        int tempo = 240000 / totalDuration;
        player = new MusicPlayer(HORN, tempo, 0.2f, freqs, durations, length);
}
	
void Melody::play(unsigned short pauseBetweenNotes){
        if(player)
                player->playBlocking();
}

short Melody::preview(unsigned short pauseBetweenNotes){
        MusicPlayer buzzerPlayer(BUZZER, 240000 / totalDuration, 0.2f, freqs, durations, length);
        buzzerPlayer.playBlocking();
        return 2;
}

String Melody::getName(void){
	return name;
}