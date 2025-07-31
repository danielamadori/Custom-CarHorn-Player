#ifndef MELODY_H
#define MELODY_H
#pragma once

#include "Notes.hpp"
#include "Encoder.hpp"
#include "HornButton.hpp"
#include "lib/NonBlockingRTTTL/NonBlockingRtttl.h"

#define HORN 19
#define BUZZER 16

class Melody{
        unsigned short length, totalDuration;
        unsigned short *notes, *notesDuration;
        String rtttl;
	
	String name;

public:

	Melody(String name, unsigned short totalDuration, unsigned short length, unsigned short* notes, unsigned short* notesDuration);
	
	void play(unsigned short pauseBetweenNotes);

	short preview(unsigned short pauseBetweenNotes);

	String getName(void);

};

#endif