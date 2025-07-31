#ifndef PLAYER_H
#define PLAYER_H
#pragma once

#include "Melody.hpp"

#define MELODY_NUMBER 1

class Player{
       Melody *melodies[MELODY_NUMBER];

public:

	void setup(void);

	void play(unsigned short actionNumber);

       Melody *getMelody(unsigned short i);
};

extern Player player;

#endif