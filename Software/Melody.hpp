#ifndef MELODY_H
#define MELODY_H
#pragma once

#include "lib/rtttl/rtttl.h"

#define HORN 19
#define BUZZER 16

class Melody{
        const char *score;
        String name;

public:

        Melody(String name, const char *score);

        void play(void);

        void preview(void);

	String getName(void);

};

#endif