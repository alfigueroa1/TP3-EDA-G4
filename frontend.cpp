/*******************************************************************************
                             INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "frontend.h"
/*******************************************************************************
                  CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

/*********************************************************************************
						  GLOBAL FUNCTION DEFINITIONS
 ********************************************************************************/
void frontend() {
	ALLEGRO_DISPLAY* display = NULL;
	//ALLEGRO_BITMAP **draw_list = malloc()
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue;

	timer = al_create_timer(1.0/FPS);
	if (timer == NULL) {
		printf("Failed to create TIMER\n");
		return;
	}
	event_queue = al_create_event_queue();
	if (event_queue == NULL) {
		printf("Failed to create EVENT QUEUE\n");
		al_destroy_timer(timer);
		return;
	}
	
	return;
}

void handle_keyboard() {
	bool key_pressed[7] = { FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE };
	ALLEGRO_EVENT ev;
	
	if (al_get_next_event(event_queue, &ev)) {
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (object_list[GAMESTATE_ID].state == PLAY_GAME) {
				if (key_pressed[KEY_UP])
					shoot((object_list + BULLET_ID), object_list + TANK_ID);
				if (key_pressed[KEY_LEFT])
					(object_list[TANK_ID].direction) = 'L';
				else if (key_pressed[KEY_RIGHT])
					(object_list[TANK_ID].direction) = 'R';
				else
					(object_list[TANK_ID].direction) = 'S';
				if (key_pressed[KEY_ENTER]) {
					object_list[GAMESTATE_ID].speed = KEY_ENTER; usleep(10000);
				}
				else
					object_list[GAMESTATE_ID].speed = -1;
			}
			if (object_list[GAMESTATE_ID].state != PLAY_GAME) {
				if (key_pressed[KEY_ENTER]) {
					object_list[GAMESTATE_ID].speed = KEY_ENTER; usleep(10000); /*object_list[GAMESTATE_ID].speed = -1;*/
				}
				else if (key_pressed[KEY_DOWN]) {
					object_list[GAMESTATE_ID].speed = KEY_DOWN;  usleep(10000);
				}
				else if (key_pressed[KEY_UP]) {
					object_list[GAMESTATE_ID].speed = KEY_UP;    usleep(10000);
				}
				else if (key_pressed[KEY_LEFT]) {
					object_list[GAMESTATE_ID].speed = KEY_LEFT;    usleep(10000);
				}
				else if (key_pressed[KEY_RIGHT]) {
					object_list[GAMESTATE_ID].speed = KEY_RIGHT;    usleep(10000);
				}
				else if (key_pressed[KEY_BACKSPACE]) {
					object_list[GAMESTATE_ID].speed = KEY_BACKSPACE;    usleep(10000);
				}
				else
					object_list[GAMESTATE_ID].speed = -1;
			}
			//object_list[GAMESTATE_ID].speed = -1;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key_pressed[KEY_UP] = TRUE;        break;
			case ALLEGRO_KEY_DOWN:
				key_pressed[KEY_DOWN] = TRUE;       break;
			case ALLEGRO_KEY_LEFT:
				key_pressed[KEY_LEFT] = TRUE;       break;
			case ALLEGRO_KEY_RIGHT:
				key_pressed[KEY_RIGHT] = TRUE;      break;
			case ALLEGRO_KEY_ENTER:
				key_pressed[KEY_ENTER] = TRUE;      break;
			case ALLEGRO_KEY_SPACE:
				key_pressed[KEY_SPACE] = TRUE;      break;
			case ALLEGRO_KEY_BACKSPACE:
				key_pressed[KEY_BACKSPACE] = TRUE;  break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key_pressed[KEY_UP] = FALSE;        break;
			case ALLEGRO_KEY_DOWN:
				key_pressed[KEY_DOWN] = FALSE;      break;
			case ALLEGRO_KEY_LEFT:
				key_pressed[KEY_LEFT] = FALSE;      break;
			case ALLEGRO_KEY_RIGHT:
				key_pressed[KEY_RIGHT] = FALSE;     break;
			case ALLEGRO_KEY_ENTER:
				key_pressed[KEY_ENTER] = FALSE;     break;
			case ALLEGRO_KEY_SPACE:
				key_pressed[KEY_SPACE] = FALSE;     break;
			case ALLEGRO_KEY_BACKSPACE:
				key_pressed[KEY_BACKSPACE] = FALSE; break;
			case ALLEGRO_KEY_ESCAPE:
				*system_running = FALSE;            break;
			}
		}
	}
	return;
}

bool initializeFrontend() {
	bool ret = 0;
	if (!al_init())
		printf("Failed to initialize Allegro\n");
	else if (!al_init_image_addon())
		printf("Failed to initialize Image Addon\n");
	else if (!al_install_keyboard())
		printf("Failed to initialize Keyboard Addon\n");
	else if (!al_init_font_addon())
		printf("Failed to initialize Font Addon\n");
	else
		ret = 1;
	return ret;
}

void handleKeyboard() {
	
	return;
}