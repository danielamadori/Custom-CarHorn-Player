#include "Player.hpp"
#include "NonBlockingRtttl.h"

const char *rtttlDemo = "tetris:d=4,o=5,b=160:e6,8b,8c6,8d6,16e6,16d6,8c6,8b,a,8a,8c6,e6,8d6,8c6,b,8b,8c6,d6,e6,c6,a,2a";

//Clacson Corriera
unsigned short melody0[4] = {NOTE_G5, NOTE_F5, NOTE_E5, NOTE_F5};
unsigned short melodyDuration0[4] = {8,8,8,8};

//Tetris
unsigned short melody1[20] = {NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, 0, NOTE_C5,NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4};
unsigned short melodyDuration1[20] = {4,8,8,4,8,8,4,8,8,4,8,8,4,8,8,4,4,4,4,2};

//Hazard (Dixie)
unsigned short melody2[12] = {NOTE_G5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5};
unsigned short melodyDuration2[12] = {8, 8, 4, 4, 8, 8, 8, 8, 4, 4, 4, 4};

//Seven Nation Army
unsigned short melody3[7] = {NOTE_F5, NOTE_F5, NOTE_GS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_C5};
unsigned short melodyDuration3[7] = {6, 16, 12, 12, 16, 4, 4};

//Campioni del mondo
unsigned short melody4[10] = {NOTE_C5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_F5};
unsigned short melodyDuration4[10] = {8, 8, 4, 8, 8, 4, 8, 3, 8, 3};

//Bevo Bevo
unsigned short melody5[26] = {NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_F5};
unsigned short melodyDuration5[26] = {8, 4, 8, 4, 8, 8, 8, 8, 8, 4, 16, 16, 8, 4, 16, 16, 16, 8, 4, 16, 16, 8, 8, 8, 8, 4};

//Maza la vecia
unsigned short melody6[7] = {NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_B5, NOTE_C6};
unsigned short melodyDuration6[7] = {8, 16, 8, 8, 4, 8, 8};

//Gne gne gne
unsigned short melody7[7] = {NOTE_G5, NOTE_G5, NOTE_E5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_E5};
unsigned short melodyDuration7[7] = {8, 8, 8, 8, 8, 8, 4};

//Koala
unsigned short melody8[32] = {NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4};
unsigned short melodyDuration8[32] = {16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16};


/*### Testing ###*/

/*
//Rumore
unsigned short melody9[1] = {NOTE_A6};
unsigned short melodyDuration9[1] = {1};

//La Cucaracha
unsigned short melody10[19] = {NOTE_E5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5};
unsigned short melodyDuration10[19] = {6, 6, 6, 6, 3, 3, 12, 6, 6, 6, 6, 3, 3, 12, 6, 6, 6, 6, 3};

//Freaks
unsigned short melody11[10] = {NOTE_G4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_E4};
unsigned short melodyDuration11[10] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8};

//Astronomia
unsigned short melody12[64] = {
    NOTE_G4, NOTE_G4, NOTE_G4, NOTE_DS5, NOTE_B4, NOTE_AS4, NOTE_A4, 
    NOTE_G4, NOTE_G4, NOTE_G4, NOTE_DS5, NOTE_B4, NOTE_AS4, NOTE_A4, 
    NOTE_G4, NOTE_G4, NOTE_G4, NOTE_DS5, NOTE_B4, NOTE_AS4, NOTE_A4, NOTE_G4,
    NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_DS5, NOTE_B4, NOTE_G4,
    NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_DS5, NOTE_B4, NOTE_G4,
    NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_DS5, NOTE_B4, NOTE_G4,
    NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_DS5, NOTE_B4, NOTE_G4,
    NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_DS5, NOTE_B4, NOTE_G4
};
unsigned short melodyDuration12[64] = {
    4, 4, 4, 4, 4, 4, 8,
    4, 4, 4, 4, 4, 4, 8,
    4, 4, 4, 4, 4, 4, 8, 8,
    4, 4, 4, 4, 4, 4, 4, 8,
    4, 4, 4, 4, 4, 4, 4, 8,
    4, 4, 4, 4, 4, 4, 4, 8,
    4, 4, 4, 4, 4, 4, 4, 8,
    4, 4, 4, 4, 4, 4, 4, 8
};

//Crazy Frog
unsigned short melody13[34] = {
  NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_FS5, NOTE_D5, NOTE_FS5, NOTE_G5, 
  NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_FS5, NOTE_D5, NOTE_FS5, NOTE_G5, 
  NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_FS5, NOTE_D5, NOTE_FS5, NOTE_G5, 
  NOTE_B5, NOTE_A5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5
};

unsigned short melodyDuration13[34] = {
  8, 8, 4, 4, 4, 8, 8, 8, 
  8, 8, 4, 4, 4, 8, 8, 8, 
  8, 8, 4, 4, 4, 8, 8, 8, 
  8, 8, 8, 8, 4, 4, 4, 4, 8
};

//20th Century Fox
unsigned short melody14[21] = {
    NOTE_G4, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_E5, NOTE_C5,
    NOTE_A4, NOTE_G4, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_F4, NOTE_D5, NOTE_B4, NOTE_G4, NOTE_F4
};

unsigned short melodyDuration14[21] = {
    8, 8, 8, 4, 8, 8, 8,
    4, 8, 8, 8, 4, 8, 8,
    8, 8, 8, 4, 8, 8, 4
};


//He's a Pirate
unsigned short melody15[51] = {
    NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4,
    NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_A4, NOTE_D5, NOTE_D5, NOTE_D5,
    NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_D6,
    NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_F6, NOTE_A6, NOTE_D7,
    NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D7
};

unsigned short melodyDuration15[51] = {
    8, 8, 8, 8, 4, 4, 8, 8, 8, 8,
    8, 8, 8, 8, 4, 4, 8, 8, 8, 8,
    8, 8, 8, 8, 4, 4, 8, 8, 8, 8,
    8, 8, 8, 8, 4, 4, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 4, 4
};

//The Next Episode
unsigned short melody16[14] = {
  NOTE_B4, NOTE_GS4, NOTE_B4, NOTE_GS4, NOTE_B4, NOTE_GS4, NOTE_D5, NOTE_D5,
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5
};
unsigned short melodyDuration16[14] = {
  4, 4, 4, 4, 4, 4, 8, 8,
  4, 4, 4, 4, 4, 4
};

//Circus Theme Song
unsigned short melody17[14] = {NOTE_G5, NOTE_G5, NOTE_G5, NOTE_C6, NOTE_E6, NOTE_E6, NOTE_D7, NOTE_D7, NOTE_C6, NOTE_E6, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5};
unsigned short melodyDuration17[14] = {8, 8, 8, 8, 8, 4, 8, 8, 8, 4, 8, 8, 8, 4};

/*
//Tequila
unsigned short melody18[24] = {
  NOTE_D5, NOTE_FS5, NOTE_A5, NOTE_D6, NOTE_REST, NOTE_D6, NOTE_FS6, NOTE_A6,
  NOTE_D7, NOTE_REST, NOTE_D7, NOTE_FS7, NOTE_A7, NOTE_A7, NOTE_GS7, NOTE_FS7,
  NOTE_E7, NOTE_E7, NOTE_FS7, NOTE_FS7, NOTE_GS7, NOTE_A7, NOTE_D7, NOTE_REST
};

unsigned short melodyDuration18[24] = {
  4, 8, 8, 4, 4, 4, 8, 8,
  4, 4, 4, 8, 8, 8, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4
};*/

/*### \Testing ###*/


Player player;

void Player::play(unsigned short actionNumber){
	melodies[actionNumber % MELODY_NUMBER]->play(pauseBetweenNotes);
}

short Player::preview(unsigned short actionNumber){
        return melodies[actionNumber % MELODY_NUMBER]->preview(pauseBetweenNotes);
}

Melody* Player::getMelody(unsigned short i){
	if(i >= MELODY_NUMBER)
		i = MELODY_NUMBER-1;
	
        return melodies[i];
}

void Player::playRtttl(const char *song){
        rtttl::begin(HORN, song);
        while(!rtttl::done()){
                rtttl::play();
        }
}

void Player::setup(void){
	//1.30
	melodies[0] = new Melody("Clacson Corriera", 1000, 4, melody0, melodyDuration0);
	//1.30 
	melodies[1] = new Melody("Tetris", 1000, 20, melody1, melodyDuration1);
	//800, 1.30
	melodies[2] = new Melody("Hazard (Dixie)", 800, 12, melody2, melodyDuration2);
	//3200, 1.20
	melodies[3] = new Melody("Seven Nation Army", 3200, 7, melody3, melodyDuration3);
	//2400, 1.30
	melodies[4] = new Melody("Campioni del mondo", 2400, 10, melody4, melodyDuration4);
	//2400, 1.20
	melodies[5] = new Melody("Bevo Bevo", 2400, 26, melody5, melodyDuration5);
	//1400, 1.30
	melodies[6] = new Melody("Maza la vecia", 1400, 7, melody6, melodyDuration6);
	//1000, 1.30
	melodies[7] = new Melody("Gne gne gne", 1000, 7, melody7, melodyDuration7);
	//800, 1.30
	melodies[8] = new Melody("Koala", 800, 32, melody8, melodyDuration8);
	
    /*
    //6000, 1.30
	melodies[9] = new Melody("Rumore", 50, 1, melody9, melodyDuration9);

	melodies[10] = new Melody("La Cucaracha", 3000, 19, melody10, melodyDuration10);
	melodies[11] = new Melody("Freaks", 1500, 10, melody11, melodyDuration11);
	melodies[12] = new Melody("Astronomia", 2000, 64, melody12, melodyDuration12);
	melodies[13] = new Melody("Crazy Frog", 4000, 34, melody13, melodyDuration13);
	melodies[14] = new Melody("20th Century Fox Intro", 4000, 21, melody14, melodyDuration14);
	melodies[15] = new Melody("He's a Pirate", 5400, 51, melody15, melodyDuration15);
	melodies[16] = new Melody("The Next Episode Intro", 4000, 14, melody16, melodyDuration16);
	melodies[17] = new Melody("Circus Theme", 3000, 14, melody17, melodyDuration17);
  	//melodies[18] = new Melody("Tequila", 3200, 24, melody18, melodyDuration18);
	*/
}