#include "Melody.hpp"

static Rtttl rtttl;

Melody::Melody(String name, const char *score){
    this->name = name;
    this->score = score;
}

void Melody::play(void){
    rtttl.begin(HORN);
    rtttl.play_P(score);
}

void Melody::preview(void){
    rtttl.begin(BUZZER);
    rtttl.play_P(score);
}

String Melody::getName(void){
    return name;
}
