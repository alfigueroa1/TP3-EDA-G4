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

#include "flock.h"
#include "bird.h"
#include "types.h"
#include "frontend.h"
/*******************************************************************************
                  CONSTANT AND MACRO DEFINITIONS USING #DEFINE

 ******************************************************************************/

 
 /*******************************************************************************
* ENUMERATIONS AND STRUCTURES AND TYPEDEFS
******************************************************************************/
enum {CROW};

/*********************************************************************************
						  GLOBAL FUNCTION DEFINITIONS
 ********************************************************************************/
int handleSimGraph(Flock* flock) {
	uint birdCount = getBirdCount(flock);
	Bird* bird = getBird(flock);
	tileType* Piso = getSimFloor(sim);

	bool ok = true;
	uint displayWidth, displayHeight;

	if (width > height) {																//El tama�o y forma de la pantalla se adaptan a la cantidad de baldosas
		displayWidth = (uint)DISP_MAX_SIZE;
		displayHeight = (uint)((double)height / (double)width * DISP_MAX_SIZE);
	}
	else {
		displayWidth = (uint)((double)width / (double)height * DISP_MAX_SIZE);
		displayHeight = (uint)DISP_MAX_SIZE;
	}

	ALLEGRO_DISPLAY* display = NULL;							//Se crean los elementos necesarios para que funcione Allegro
	ALLEGRO_BITMAP* drawList[DRAWABLES];
	ALLEGRO_FONT* font = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	bool redraw = true, once = true;

	if (!al_init()) {											//Se inicializan los addons de Allegro
		ok = false;
		printf("Failed to initialize Allegro!\n");
	}
	if (!al_init_image_addon()) {
		ok = false;
		printf("Failed to initialize Image Addon!\n");
	}

	timer = al_create_timer(1.0 / FPS);								//Se inicializan y cargan los elementos
	display = al_create_display(displayWidth, displayHeight);
	if (!init_drawables(drawList)) {
		ok = false;
		printf("Failed to initialize Bitmaps!\n");
	}

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);

	while (ok)
	{
		ALLEGRO_EVENT ev;													//se fija si el usuario quiere cerrar el display
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue) && once) {
			redraw = false;

			/****** Dibujar en pantalla ac� ******/

			al_clear_to_color(al_map_rgb(0, 0, 0));

			drawFloor(drawList, Piso, width, height, displayWidth, displayHeight);			//dibuja el piso
			drawRobots(drawList, Roomba, robotCount, displayWidth / width);					//dibuja los robots

			if (isSimOver(sim) == true) {													//si los robots terminaron de limpiar, muestra el cartel que indica esto
				printf("Simulacion completa luego de %d ticks\n", getSimTicks(sim));
				if (displayWidth > displayHeight) {											//el cartel se adapta a la forma de la pantalla
					al_draw_scaled_bitmap(drawList[ALL_CLEAN], 0, 0, 276, 306, displayWidth / 2 - (displayHeight - AXIS) / 2, displayHeight / 2 - (displayHeight - AXIS) / 2, displayHeight - AXIS, displayHeight - AXIS, 0);
				}
				else {
					al_draw_scaled_bitmap(drawList[ALL_CLEAN], 0, 0, 276, 306, AXIS / 2, displayHeight / 2 - (displayWidth - AXIS) / 2, displayWidth - AXIS, displayWidth - AXIS, 0);
				}
				once = false;
			}
			else {
				simulationStep(sim);														//si el piso sigue sucio, sigue limpiando
			}

			/******************************/

			al_flip_display();																//se grafica la pantalla
		}
	}

	destroySim(sim);																		//destruye todo

	al_destroy_timer(timer);
	al_destroy_display(display);
	destroy_drawables(drawList);
	al_destroy_event_queue(event_queue);

	return ok;

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

int init_drawables(ALLEGRO_BITMAP* drawList[DRAWABLES]) {
	int r = true;
	//cargo todas las imagenes
	drawList[CROW] = al_load_bitmap("crow.png");
	if (drawList[CROW] == NULL) {
		fprintf(stderr, "failed to load CROW!\n");
		al_destroy_bitmap(drawList[CROW]);
		r = false;
	}
	return r;
}

void handleKeyboard() {
	
	return;
}