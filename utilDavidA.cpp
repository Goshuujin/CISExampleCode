/*
*  Program Name: utilDavidA.cpp
*  Written by: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/


#include <iostream>
#include "finalFractionDavidA.h"
#include "finalCircleDavidA.h"
#include "finalRectangleDavidA.h"
#include "utilDavidA.h"
#include "finalBoxDavidA.h"
#include "finalCylinderDavidA.h"

using namespace std;

void infoOut() {

	cout << "Class Information --" 
		<< "\n  CIS 25 - C++ Programming"
		<< "\n  Laney College"
		<< "\n\nAssignment Information --"
		<< "\n  Assignment Number:  Final"
		<< "\n  Written By:         David Allen"
		<< "\n  Due Date:           12/13/2013"
		<< "\n\n"
		<< endl;

	return;
}

void swap(ShapeDavidA*& obj1, ShapeDavidA*& obj2) {
	ShapeDavidA* temp;

	temp = obj1;
	obj1 = obj2;
	obj2 = temp;

	return;
}

void printObj(ShapeDavidA** objAry, int size, string name, int single) {
	for (int i = 0; i < size; i++) {
		if (((*(objAry + i))->getName() == name) || (name == "all")) {
			cout << (**(objAry + i)) << endl;
			if (single)
				i = size;
		}
	}

	return;
}

void getSmallestAreaDavidA(ShapeDavidA**& objAry, int size, string pString, int single) {
	bool finished = false;

	while (!finished) {
		finished = true;
		for (int i = 0; i < size - 1; i++) {
			if (((*(objAry + i))->getArea()) > ((*(objAry + i + 1))->getArea())) {
				swap((*(objAry + i)), (*(objAry + i + 1)));
				finished = false;
			}
		}
	}
	
	printObj(objAry, size, pString, single);

	return;
}

void getSmallestVolumeDavidA(ShapeDavidA**& objAry, int size, string pString, int single) {
	bool finished = false;

	while (!finished) {
		finished = true;
		for (int i = 0; i < size - 1; i++) {
			if (((*(objAry + i))->getVolume()) > ((*(objAry + i + 1))->getVolume())) {
				swap((*(objAry + i)), (*(objAry + i + 1)));
				finished = false;
			}
		}
	}

	for (int i = size - 1; i > 0; i--) {
		if ((*(objAry + i))->getVolume() == 0){
			swap((*(objAry + i + 1)), (*(objAry)));
			i = -1;
		}
	}

	printObj(objAry, size, pString, single);

	return;
}

void displayAreaDavidA(ShapeDavidA**& objAry, int size, string pString, int single) {
	bool finished = false;

	while (!finished) {
		finished = true;
		for (int i = 0; i < size - 1; i++) {
			if (((*(objAry + i))->getArea()) > ((*(objAry + i + 1))->getArea())) {
				swap((*(objAry + i)), (*(objAry + i + 1)));
				finished = false;
			}
		}
	}
	
	printObj(objAry, size, pString, single);

	return;
}

void displayVolumeDavidA(ShapeDavidA**& objAry, int size, string pString, int single) {
	bool finished = false;

	while (!finished) {
		finished = true;
		for (int i = 0; i < size - 1; i++) {
			if (((*(objAry + i))->getVolume()) > ((*(objAry + i + 1))->getVolume())) {
				swap((*(objAry + i)), (*(objAry + i + 1)));
				finished = false;
			}
		}
	}
	
	printObj(objAry, size, pString, single);

	return;
}