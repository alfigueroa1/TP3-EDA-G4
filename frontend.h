#ifndef FRONTEND_H
#define FRONTEND_H

/***************************************************************************//**
  @file     +frontend.h+
  @brief    +Contiene funciones para el funcionamiento del frontend visual.+
  @author   +Grupo 4. TP3.+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include "flock.h"
#include "bird.h"
#include "types.h"

 /*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define UNIT		5

#define WORLD_H		70*UNIT
#define WORLD_W		100*UNIT
#define UPPER_H		100
#define LOWER_H		100
#define SCREEN_H	(WORLD_H + UPPER_H + LOWER_H)
#define SCREEN_W	WORLD_W

#define DRAWABLES 1

#define CROW_CENTER 15

#define FPS	60

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
bool handleBirdGraph(Flock* flock);
bool initializeFrontend(void);

#endif // !FRONTEND_H