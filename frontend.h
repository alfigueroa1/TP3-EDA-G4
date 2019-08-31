#pragma once
/***************************************************************************//**
  @file     +frontend.h+
  @brief    +Contiene funciones para el funcionamiento del frontend visual.+
  @author   +Grupo 4. TP3.+
 ******************************************************************************/
 /*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define WORLD_H		70
#define WORLD_W		100
#define UPPER_H		70
#define LOWER_H		70
#define SCREEN_H	(WORLD_H + UPPER_H + LOWER_H)
#define SCREEN_W	WORLD_W

#define FPS	60
 /*******************************************************************************
  * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
  ******************************************************************************/
/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/
bool initializeFrontend(void);