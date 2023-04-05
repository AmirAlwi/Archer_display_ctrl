

/*
 *
 * Scoreboard
 *
 *
 * File Name           : Scoreboard.h
 * Date                : 24.04.2022
 * Font width          : 10
 * Font height         : 16
 * Font first char     : 48
 * Font last char      : 57
 * Font used chars     : 10
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef Scoreboard_H
#define Scoreboard_H

#define Scoreboard_WIDTH 10
#define Scoreboard_HEIGHT 16

const static uint8_t Scoreboard[] PROGMEM = {
    0x30, 0x86, // size
    0x14,       // width
    0x1F,       // height
    0x30,       // first char
    0x15,       // char count

    // char widths
    // 0x14, 0x06, 0x08, 0x08, 0x09, 0x08, 0x08, 0x08, 0x08, 0x08,
    // 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,  //16 width
    0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14,  // 20 width Number 48-57
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //blank
    0x17, 0x17, 0x17, 0x17, //ABCD

    // font data
    0x00, 0xC0, 0xF0, 0xFC, 0xFE, 0x3E, 0x1E, 0x1F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1F, 0x1E, 0x3E, 0xFE, 0xFC, 0xF0, 0xC0, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFE, 0x3F, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x01, 0x0F, 0x1F, 0x3F, 0x3E, 0x7C, 0x7C, 0x78, 0x78, 0x78, 0x78, 0x7C, 0x3C, 0x3E, 0x3F, 0x1F, 0x07, 0x01, 0x00, //char 0
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xE0, 0xF0, 0x78, 0xFC, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, // char 1
    0xC0, 0xF0, 0xF8, 0xFC, 0x7E, 0x3E, 0x1F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1F, 0x3E, 0x7E, 0xFC, 0xF8, 0xF0, 0xC0, 0x01, 0x01, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF8, 0xFF, 0x7F, 0x3F, 0x0F, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0x78, 0x3C, 0x3E, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x78, 0x7E, 0x7F, 0x7F, 0x7F, 0x7B, 0x79, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, //char 2
    0xC0, 0xF0, 0xF8, 0xFC, 0x7E, 0x3E, 0x1F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1E, 0x3E, 0xFE, 0xFC, 0xF8, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0xF0, 0xF8, 0xF8, 0xFC, 0xDF, 0xCF, 0x8F, 0x83, 0x00, 0x00, 0xC0, 0xC0, 0xE0, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x07, 0x0F, 0x1F, 0x3F, 0x3E, 0x7C, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x3C, 0x3E, 0x1F, 0x1F, 0x0F, 0x03, 0x00, //char 3
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xF0, 0xF8, 0xFE, 0x7F, 0x1F, 0x0F, 0x03, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFE, 0xFF, 0xFF, 0xF7, 0xF1, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xF0, 0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x00, 0x00, 0x00, 0x00, //char 4
    0x00, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x00,  0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0x70, 0x38, 0x38, 0x3C, 0x3C, 0x3C, 0x3C, 0x7C, 0x78, 0xF8, 0xF0, 0xE0, 0xC0, 0x00,  0xC0, 0xC0, 0xC0, 0xC1, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0xFF, 0xFF, 0xFF, 0xFF,  0x01, 0x07, 0x0F, 0x1F, 0x3F, 0x3E, 0x7C, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x3C, 0x3E, 0x1F, 0x0F, 0x07, 0x03, 0x00, //char 5
    0x80, 0xE0, 0xF8, 0xFC, 0x7C, 0x3E, 0x1E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1F, 0x1E, 0x7E, 0xFC, 0xFC, 0xF0, 0xC0, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0xF0, 0x70, 0x78, 0x78, 0x78, 0x78, 0x78, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0xFF, 0xFF, 0xFF, 0xFE, 0x01, 0x07, 0x0F, 0x1F, 0x3E, 0x3C, 0x3C, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x3C, 0x3E, 0x3F, 0x1F, 0x0F, 0x03, 0x00, //char 6
    0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x8F, 0xCF, 0xEF, 0xFF, 0x7F, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0xFC, 0xFE, 0x3F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0xFF, 0xFF, 0x3F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C, 0x7F, 0x7F, 0x7F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //char 7
    0x00, 0xE0, 0xF8, 0xFC, 0xFE, 0x3E, 0x1F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1E, 0x3E, 0xFE, 0xFC, 0xF8, 0xE0, 0x00, 0x00, 0x03, 0x0F, 0x9F, 0xDF, 0xFC, 0xF8, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF8, 0xFC, 0xDF, 0x9F, 0x0F, 0x03, 0x00, 0xF8, 0xFE, 0xFF, 0xFF, 0x07, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0xFF, 0xFF, 0xFE, 0xF8, 0x01, 0x07, 0x0F, 0x1F, 0x3F, 0x3C, 0x7C, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x7C, 0x3C, 0x3F, 0x1F, 0x0F, 0x07, 0x01, //char 8
    0x80, 0xF0, 0xF8, 0xFC, 0xFE, 0x3E, 0x1F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1E, 0x3E, 0x7C, 0xF8, 0xF0, 0xC0, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x80, 0x81, 0x83, 0x87, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0xE1, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x01, 0x07, 0x1F, 0x3F, 0x3E, 0x7C, 0x78, 0x78, 0x78, 0x78, 0x78, 0x7C, 0x3C, 0x3F, 0x1F, 0x0F, 0x07, 0x01, 0x00, //char 9
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xF8, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFE, 0xFF, 0xFF, 0x3F, 0x07, 0x00, 0x03, 0x1F, 0xFF, 0xFF, 0xFE, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xF8, 0xFF, 0xFF, 0x7F, 0x1F, 0x1D, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0x1D, 0x1F, 0x7F, 0xFF, 0xFF, 0xF8, 0x80, 0x00, 0x00, 0x60, 0x7C, 0x7F, 0x7F, 0x3F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3F, 0x7F, 0x7F, 0x7C, 0x60,//char A
    0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1E, 0xFE, 0xFC, 0xF8, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xF0, 0xF0, 0xFF, 0x7F, 0x3F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x07, 0x0F, 0xFF, 0xFE, 0xFC, 0xF8, 0x00, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x3E, 0x3F, 0x1F, 0x0F, 0x03, 0x00,//char B
    0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF8, 0xFC, 0x3E, 0x1E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1F, 0x1E, 0x3E, 0xFC, 0xFC, 0xF0, 0xE0, 0x80, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x01, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF0, 0x60, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x1F, 0x3E, 0x3C, 0x7C, 0x78, 0x78, 0x78, 0x78, 0x78, 0x7C, 0x3C, 0x3E, 0x1F, 0x0F, 0x07, 0x01, 0x00,//char C
    0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1E, 0x3E, 0x7E, 0xFC, 0xF8, 0xE0, 0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x78, 0x3C, 0x3C, 0x1F, 0x1F, 0x0F, 0x03, 0x00, 0x00,//char D

};

#endif
