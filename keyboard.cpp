/*******************************************************************************
							 INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include "keyboard.h"
#include "bird.h"
 
 /*********************************************************************************
						GLOBAL FUNCTION DEFINITIONS
 ********************************************************************************/
void handleKeyInputs(bool keyPressed[KEYS], Flock* flock) {
	if (keyPressed[KEY_UP] == true) {
		(flock->getBird())->updateSpeed(flock->getBird(), flock->getBirdCount(), 1);
	}
	else if (keyPressed[KEY_DOWN] == true) {
		(flock->getBird())->updateSpeed(flock->getBird(), flock->getBirdCount(), -1);
	}
	else if (keyPressed[KEY_RIGHT] == true) {
		if (flock->getEyeSight() + JIGGLE_INC <= MAX_SIGHT)
			flock->setEyeSight(flock->getEyeSight() + SIGHT_INC);
		else
			flock->setEyeSight(MAX_SIGHT);
	}
	else if (keyPressed[KEY_LEFT] == true) {
		if (flock->getEyeSight() - JIGGLE_INC >= 0)
			flock->setEyeSight(flock->getEyeSight() - SIGHT_INC);
		else
			flock->setEyeSight(0.0);
	}
	else if (keyPressed[KEY_1] == true) {
		flock->setMode(MODE1);
	}
	else if (keyPressed[KEY_2] == true) {
		flock->setMode(MODE2);
	}
	else if (keyPressed[KEY_W] == true) {
		if(flock->getRandomJiggleLimit()+JIGGLE_INC <= MAX_JIGGLE)
			flock->setRandomJiggleLimit(flock->getRandomJiggleLimit() + JIGGLE_INC);
		else
			flock->setRandomJiggleLimit(MAX_JIGGLE);
	}
	else if (keyPressed[KEY_Q] == true) {
		if (flock->getRandomJiggleLimit() - JIGGLE_INC >= 0)
			flock->setRandomJiggleLimit(flock->getRandomJiggleLimit() - JIGGLE_INC);
		else
			flock->setRandomJiggleLimit(0.0);
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
