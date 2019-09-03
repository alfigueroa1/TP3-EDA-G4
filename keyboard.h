#ifndef KEYBOARD_H
#define KEYBOARD_H

/***************************************************************************//**
  @file     +keyboard.h+
  @brief    +Contiene manejo y recepcion del teclado en Allegro+
  @author   +Grupo 4+
 ******************************************************************************/

/*******************************************************************************
 *				INCLUDE HEADER FILES
 ******************************************************************************/
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "flock.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define KEYS           8

/*******************************************************************************
* ENUMERATIONS AND STRUCTURES AND TYPEDEFS
*******************************************************************************/
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_1, KEY_2, KEY_Q, KEY_W, KEY_LEFT, KEY_RIGHT //arrow keys
};

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
void handleKeyInputs(bool keyPressed[KEYS], Flock* flock);
void handleKeyPress(ALLEGRO_EVENT& ev, bool keyPressed[KEYS], bool down, bool& ok);

#endif // KEYBOARD_H