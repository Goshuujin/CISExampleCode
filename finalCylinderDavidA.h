/*
*  Program Name: FinalCylinderDavidA.h
*  Written By: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/

#ifndef FINALCYLINDERDAVIDA_H
#define FINALCYLINDERDAVIDA_H

#include <iostream>
#include "finalFractionDavidA.h"
#include "finalPointDavidA.h"
#include "finalCircleDavidA.h"

using namespace std;

class FinalCylinderDavidA : public FinalCircleDavidA {
public:
	FinalCylinderDavidA(void);
	~FinalCylinderDavidA(void);
	FinalCylinderDavidA(const FinalCylinderDavidA&);
	FinalCylinderDavidA(const FinalPointDavidA&, const FinalFractionDavidA&, const FinalFractionDavidA&);
	FinalCylinderDavidA(const FinalCircleDavidA& oldC, const FinalFractionDavidA& h);
	FinalCylinderDavidA& operator=(const FinalCylinderDavidA&);
	FinalCylinderDavidA operator+(const FinalCylinderDavidA&);
	FinalFractionDavidA getArea(void) const;
	FinalFractionDavidA getVolume(void) const;
	FinalFractionDavidA getHeight(void) const;
	void setHeight(const FinalFractionDavidA& value);
	ostream& printOut(ostream&) const;

private:
	FinalFractionDavidA* height;
};

#endif