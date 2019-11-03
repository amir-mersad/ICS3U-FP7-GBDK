// Copyright (c) 2019 Amirmahdi Mersad All rights reserved
//
// Created by Amir Mersad
// Created on November 2019
// This program makes white sound

#include <gb/gb.h>
#include <stdio.h>


void main() {
    // these registers must be in this specific order!
    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;
    while (1) {
        UBYTE joypad_state = joypad();

        if (joypad_state) {
            // bit 5-0 Sound length
            // 0001 1111 is 0x1F the maximum length
            NR41_REG = 0x1F;

            // volume envelope
            // 1111 0001 is 0xF1, start at full volume, fade down, 1 envelope
             // sweep  (decimal)
            NR42_REG = 0xF1;

            // 0011 0000 is 0x30, shift clock frequency 3, step 0, dividing
             // ratio 0
            NR43_REG = 0x30;

            // 1100 0000, start sound, not continuous
            NR44_REG = 0xC0;

            delay(1000);
        }
    }
}
