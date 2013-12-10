/*
*  Program Name: utilDavidA.cpp
*  Written by: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 6 Ex 1
*/

#ifndef UTILDAVIDA_H
#define UTILDAVIDA_H
#include "finalRectangleDavidA.h"
#include "finalCircleDavidA.h"
#include "finalBoxDavidA.h"
#include "finalCylinderDavidA.h"

void infoOut(void);
void getSmallestAreaDavidA(ShapeDavidA**&, int, string, int);
void getSmallestVolumeDavidA(ShapeDavidA**&, int, string, int);
void displayAreaDavidA(ShapeDavidA**&, int, string, int);
void displayVolumeDavidA(ShapeDavidA**&, int, string, int);
void swap(ShapeDavidA*&, ShapeDavidA*&);
void printObj(ShapeDavidA**, int, string, int);

#endif