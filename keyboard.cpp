/*******************************************************************************
							 INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include "keyboard.h"
 
 /*********************************************************************************
						GLOBAL FUNCTION DEFINITIONS
 ********************************************************************************/
void handleKeyInputs(bool keyPressed[KEYS], Flock* flock) {
	if (keyPressed[KEY_UP] == true) {

	}
	else if (keyPressed[KEY_DOWN] == true) {

	}
	else if (keyPressed[KEY_LEFT] == true) {

	}
	else if (keyPressed[KEY_RIGHT] == true) {

	}
	else if (keyPressed[KEY_1] == true) {

	}
	else if (keyPressed[KEY_2] == true) {

	}
	else if (keyPressed[KEY_Q] == true) {

	}
	else if (keyPressed[KEY_W] == true) {

	}
	return;
}


void handleKeyPress(ALLEGRO_EVENT &ev, bool keyPressed[KEYS], bool down, bool &ok) {
	bool press;
	if (down)
		press = true;
	else
		press = false;
	switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			keyPressed[KEY_UP] = press;		break;
		case ALLEGRO_KEY_DOWN:
			keyPressed[KEY_DOWN] = press;	break;
		case ALLEGRO_KEY_LEFT:
			keyPressed[KEY_LEFT] = press;	break;
		case ALLEGRO_KEY_RIGHT:
			keyPressed[KEY_RIGHT] = press;	break;
		case ALLEGRO_KEY_1:
			keyPressed[KEY_1] = press;		break;
		case ALLEGRO_KEY_2:
			keyPressed[KEY_2] = press;		break;
		case ALLEGRO_KEY_Q:
			keyPressed[KEY_Q] = press;		break;
		case ALLEGRO_KEY_W:
			keyPressed[KEY_W] = press;		break;
		case ALLEGRO_KEY_ESCAPE:
			if(press == false)
				ok = false;
	}
	return;
 }
