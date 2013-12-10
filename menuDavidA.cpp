/*
*  Program Name: menuDavidA.cpp
*  Written by: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/

#include <iostream>
#include "finalFractionDavidA.h"
#include "finalCircleDavidA.h"
#include "finalRectangleDavidA.h"
#include "utilDavidA.h"
#include "menuDavidA.h"
#include "finalBoxDavidA.h"
#include "finalCylinderDavidA.h"

using namespace std;

void menu() {
	ShapeDavidA **shapePtrAry = new ShapeDavidA*[8];

	for (int i = 0; i < 8; i++) {
		*(shapePtrAry + i) = NULL;
	}

	cout << "Starting at Line 50:" << endl; // Line 50 

	FinalFractionDavidA* fPtrA = new FinalFractionDavidA(4, 1); // Line 200 

	cout << *fPtrA << endl; // display the information of the above object 

	FinalFractionDavidA* fPtrB = new FinalFractionDavidA(3, 1); // Line 300 

	cout << *fPtrB << endl; // display the information of the above object 

	FinalFractionDavidA* fPtrC = new FinalFractionDavidA(2, 1); // Line 500 

	cout << *fPtrC << endl; // display the information of the above object 

	FinalFractionDavidA* fPtrD = new FinalFractionDavidA(9, 1); // Line 600 

	cout << *fPtrD << endl; // display the information of the above object 

	cout << "\nStarting at Line 1880:" << endl; // Line 1880 

	FinalCircleDavidA* cPtrA = new FinalCircleDavidA(*fPtrA); // Line 2000 

	cout << *cPtrA << endl; // display the information of the above object 

	FinalCircleDavidA* cPtrB = new FinalCircleDavidA(*fPtrB); // Line 2100 

	cout << *cPtrB << endl; // display the information of the above object 

	FinalCircleDavidA* cPtrC = new FinalCircleDavidA(*fPtrC); // Line 2200 

	cout << *cPtrC << endl; // display the information of the above object 

	cout << "\nStarting at Line 2680:" << endl; // Line 2680 

	FinalCylinderDavidA* cyPtrA = new FinalCylinderDavidA(*cPtrC, *fPtrC); // Line 3000 

	cout << *cyPtrA << endl; // display the information of the above object 

	FinalCylinderDavidA* cyPtrB = new FinalCylinderDavidA(*cPtrA, *fPtrA); // Line 3100 

	cout << *cyPtrB << endl; // display the information of the above object 

	FinalCylinderDavidA* cyPtrC = new FinalCylinderDavidA(*cPtrB, *fPtrB); // Line 3200 

	cout << *cyPtrC << endl; // display the information of the above object 

	cout << "\nStarting at Line 3300:" << endl; // Line 3300 

	FinalRectangleDavidA* rPtrA = new FinalRectangleDavidA(*fPtrA, *fPtrA); // Line 3400 

	cout << *rPtrA << endl; // display the information of the above object 

	FinalRectangleDavidA* rPtrB = new FinalRectangleDavidA(*fPtrB, *fPtrB); // Line 3500 

	cout << *rPtrB << endl; // display the information of the above object

	FinalRectangleDavidA* rPtrC = new FinalRectangleDavidA(*fPtrC, *fPtrC); // Line 3600 

	cout << *rPtrC << endl; // display the information of the above object 

	cout << "\nStarting at Line 3650:" << endl; // Line 3650 

	FinalBoxDavidA* boxPtrA = new FinalBoxDavidA(*rPtrA, *fPtrD); // Line 3700 

	cout << *boxPtrA << endl; // display the information of the above object 

	FinalBoxDavidA* boxPtrB = new FinalBoxDavidA(*rPtrB, *fPtrD); // Line 3800 

	cout << *boxPtrB << endl; // display the information of the above object 

	FinalBoxDavidA* boxPtrC = new FinalBoxDavidA(*rPtrC, *fPtrD); // Line 3700 

	cout << *boxPtrC << endl; // display the information of the above object 

	int option; // Line 3800 

	// Set up storage structures (for example, dynamic arrays)

	ShapeDavidA** allAry = new ShapeDavidA*[12];
	*(allAry + 0) = boxPtrA;
	*(allAry + 1) = boxPtrB;
	*(allAry + 2) = boxPtrC;
	*(allAry + 3) = rPtrA;
	*(allAry + 4) = rPtrB;
	*(allAry + 5) = rPtrC;
	*(allAry + 6) = cyPtrA;
	*(allAry + 7) = cyPtrB;
	*(allAry + 8) = cyPtrC;
	*(allAry + 9) = cPtrA;
	*(allAry + 10) = cPtrB;
	*(allAry + 11) = cPtrC;

	do { 

		printMenu(); 

		cout << "\nEnter the option: "; 

		cin >> option; 

		switch (option) { 

		case 1: // Line 4300 
			getSmallestAreaDavidA(allAry, 12, "all", 1);
			break;
		case 2: // Line 4400 
			getSmallestVolumeDavidA(allAry, 12, "all", 1);
			break;
		case 3: // Line 4500 
			displayAreaDavidA(allAry, 12, "Circle", 0);
			break;
		case 4: // Line 4600 
			displayAreaDavidA(allAry, 12, "Rectangle", 0);
			break;
		case 5: // Line 4700 
			displayVolumeDavidA(allAry, 12, "Cylinder", 0);
			break;
		case 6: // Line 4800 
			displayVolumeDavidA(allAry, 12, "Box", 0);
			break;
		case 7: // Line 4900 
			displayVolumeDavidA(allAry, 12, "all", 0);
			break;
		case 8: // Line 5000 
			cout << "\n\tThank you! Have fun! ..." << endl;
			break;
		default: // Line 5100 
			cout << "\n\tWrong Option! Please choose a correct option." << endl;
			break;
		}

	} while (option != 8); // Line 5200 

	for (int i = 0; i < 12; i++)
		delete (*(allAry + i));
	delete allAry;

	return; // Line 10000 
} 

void printMenu() { 

	cout << "\n**************************************************************" 
		<< "\n*                            MENU                            *" 
		<< "\n* 1. Get & Display Smallest Area (All Objects)               *" 
		<< "\n* 2. Get & Display Smallest volume (All Objects)             *" 
		<< "\n* 3. Display Areas from Smallest to Largest (All Circles)    *" 
		<< "\n* 4. Display Areas from Smallest to Largest (All Rectangles) *" 
		<< "\n* 5. Display Volumes from Smallest to Largest (All Cylinders)*" 
		<< "\n* 6. Display Volumes from Smallest to Largest (All Boxes)    *" 
		<< "\n* 7. Display Volumes from Smallest to Largest (All Objects)  *" 
		<< "\n* 8. Quit                                                    *" 
		<< "\n**************************************************************";

		return; 
}