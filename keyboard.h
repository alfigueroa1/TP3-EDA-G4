#pragma once
/***************************************************************************//**
  @file     +keyboard.h+
  @brief    +Contiene manejo y recepcion del teclado en Allegro+
  @author   +Grupo 2: Alejo Figueroa, Olivia de Vincenti, Pablo Gonzalez+
 ******************************************************************************/
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
 /*******************************************************************************
  * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
  ******************************************************************************/
#define SPACE           3
#define FPS             60.0
  /*******************************************************************************
   * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
   ******************************************************************************/
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_ENTER, KEY_SPACE, KEY_BACKSPACE //arrow keys
};
/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

void handle_keyboard(ALLEGRO_TIMER* timer, ALLEGRO_EVENT_QUEUE* event_queue);
