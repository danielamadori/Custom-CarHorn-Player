#include "Player.hpp"

static const char indiana[] PROGMEM = "Indiana:d=4,o=5,b=250:e,8p,8f,8g,8p,1c6,8p.,d,8p,8e,1f,p.,g,8p,8a,8b,8p,1f6,p,a,8p,8b,2c6,2d6,2e6,e,8p,8f,8g,8p,1c6,p,d6,8p,8e6,1f.6,g,8p,8g,e.6,8p,d6,8p,8g,e.6,8p,d6,8p,8g,f.6,8p,e6,8p,8d6,2c6";

Player player;

void Player::play(unsigned short actionNumber){
    melodies[actionNumber % MELODY_NUMBER]->play();
}

Melody* Player::getMelody(unsigned short i){
    if(i >= MELODY_NUMBER)
        i = MELODY_NUMBER-1;
    return melodies[i];
}

void Player::setup(void){
    melodies[0] = new Melody("Indiana", indiana);
}
