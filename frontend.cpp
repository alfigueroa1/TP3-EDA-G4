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
#include "keyboard.h"
/*******************************************************************************
                  CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define PI	3.14159265

 /*******************************************************************************
* ENUMERATIONS AND STRUCTURES AND TYPEDEFS
******************************************************************************/
enum {CROW};
/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
static bool init_drawables(ALLEGRO_BITMAP* drawList[DRAWABLES]);
static void destroy_drawables(ALLEGRO_BITMAP* drawList[DRAWABLES]);
static void drawHUD(Flock* flock, ALLEGRO_FONT* font);
/*********************************************************************************
						  GLOBAL FUNCTION DEFINITIONS
 ********************************************************************************/
bool handleBirdGraph(Flock* flock) {
	//uint birdCount = flock.getBirdCount();
	//Bird* bird = flock.getBird();

	bool ok = true;
	
	ALLEGRO_DISPLAY* display = NULL;							//Se crean los elementos necesarios para que funcione Allegro
	ALLEGRO_BITMAP* drawList[DRAWABLES];
	ALLEGRO_FONT* font = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	bool redraw = true, once = true;
	bool keyPressed[KEYS] = { false, false, false, false, false, false, false, false };

	font = al_load_ttf_font("BebasNeue_Regular.ttf", 20, 0);
	if (!font) {
		printf("Failed to load font!\n");
		ok = false;
	}
	timer = al_create_timer(1.0 / FPS);								//Se inicializan y cargan los elementos
	display = al_create_display(SCREEN_W, SCREEN_H);
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
			//poner las consecuencias del teclado
			handleKeyInputs(keyPressed, flock);
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			handleKeyPress(ev, keyPressed, true, ok);
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			handleKeyPress(ev, keyPressed, false, ok);
		}
		if (redraw && al_is_event_queue_empty(event_queue) && once) {
			redraw = false;

			/****** Dibujar en pantalla ac� ******/

			al_clear_to_color(al_map_rgb(100, 100, 255));

			drawHUD(flock, font);
			//drawBirds()

			//simStep();
			al_flip_display();																//se grafica la pantalla
		}
	}

	al_destroy_timer(timer);
	al_destroy_display(display);
	destroy_drawables(drawList);
	al_destroy_event_queue(event_queue);

	return ok;

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

/*********************************************************************************
						  LOCAL FUNCTION DEFINITIONS
 ********************************************************************************/
static bool init_drawables(ALLEGRO_BITMAP* drawList[DRAWABLES]) {
	bool r = true;
	//cargo todas las imagenes
	drawList[CROW] = al_load_bitmap("crow.png");
	if (drawList[CROW] == NULL) {
		fprintf(stderr, "failed to load CROW!\n");
		al_destroy_bitmap(drawList[CROW]);
		r = false;
	}
	return r;
}

static void destroy_drawables(ALLEGRO_BITMAP* drawList[DRAWABLES]) {
	for (uint i = 0; i < DRAWABLES; i++)
		al_destroy_bitmap(drawList[i]);
	return;
}

void handleKeyboard() {
	
	return;
}

static void drawBirds(ALLEGRO_BITMAP* drawList[DRAWABLES], Bird* bird, uint birdCount, uint rSize) {
	for (uint i = 0; i < birdCount; i++) {
		//al_draw_bitmap(drawList[CROW], bird->getX(), bird->getY, 0);
		//al_draw_rotated_bitmap(drawList[CROW], CROW_CENTER, CROW_CENTER, bird->getX(), bird->getY, (bird->getCurrentDir()*PI/180.0), 0);
	}
	return;
}

static void drawHUD(Flock* flock, ALLEGRO_FONT* font) {
	

	al_draw_filled_rectangle(0, 0, WORLD_W, UPPER_H, al_map_rgb(0, 0, 0));		//Dibuja el rectangulo negro superior
	al_draw_filled_rectangle(0, WORLD_H - LOWER_H, WORLD_W, WORLD_H, al_map_rgb(0, 0, 0));		//Dibuja el rectangulo negro inferior
	al_flip_display();

	al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, "Bird Count:");
	al_draw_text(font, al_map_rgb(255, 255, 255), 0, 20, 0, "Mode:");
	al_draw_text(font, al_map_rgb(255, 255, 255), 0, 40, 0, "Speed (Mode 1 Only):");
	al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W/2, 0, 0, "Random Jiggle Limit:");
	al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 20, 0, "Eye Sight:");

	al_draw_text(font, al_map_rgb(255, 255, 255), 0, WORLD_H - LOWER_H, 0, "Controls:");
	al_draw_text(font, al_map_rgb(255, 255, 255), 40, WORLD_H - LOWER_H, 0, "-1 or 2 for MODE:");
	al_draw_text(font, al_map_rgb(255, 255, 255), 40, WORLD_H - LOWER_H +20, 0, "UP: Speed Up");
	al_draw_text(font, al_map_rgb(255, 255, 255), 40, WORLD_H - LOWER_H +40, 0, "DOWN: Speed Down");
	al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 0, 0, "LEFT: Eye Sight Down");
	al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 20, 0, "RIGHT: Eye Sight Up");
	al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 40, 0, "Q: Random Jiggle Down");
	al_draw_text(font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 60, 0, "W: Random Jiggle Up");



	return;
}