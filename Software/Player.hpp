#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include "Melody.hpp"
#include "NonBlockingRtttl.h"

#define MELODY_NUMBER 9

class Player{
	unsigned short pauseBetweenNotes = 1.30;

	Melody *melodies[MELODY_NUMBER];

public:

	void setup(void);

	void play(unsigned short actionNumber);

	short preview(unsigned short actionNumber);

        Melody *getMelody(unsigned short i);

        void playRtttl(const char *song);
};

extern Player player;

#endif