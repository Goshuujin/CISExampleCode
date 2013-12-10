/*
*  Program Name: FinalBoxDavidAV2.h
*  Written By: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/

#ifndef FinalBoxDavidA_H
#define FinalBoxDavidA_H

#include <iostream>
#include "finalFractionDavidA.h"
#include "finalPointDavidA.h"
#include "finalRectangleDavidA.h"

using namespace std;

class FinalBoxDavidA : public FinalRectangleDavidA {
public:

	FinalBoxDavidA(void);
	~FinalBoxDavidA(void);
	FinalBoxDavidA(FinalPointDavidA&, FinalPointDavidA&, FinalFractionDavidA&);
	FinalBoxDavidA(FinalPointDavidA&, FinalPointDavidA&, int);
	FinalBoxDavidA(const FinalRectangleDavidA&, const FinalFractionDavidA&);
	FinalBoxDavidA(const FinalBoxDavidA&);
	FinalBoxDavidA& operator=(const FinalBoxDavidA&);
	FinalFractionDavidA getArea(void) const;
	FinalFractionDavidA getVolume(void) const;
	FinalFractionDavidA getHeight(void) const;
	void setHeight(const FinalFractionDavidA& value);
	ostream& printOut(ostream&) const;

private:
	FinalFractionDavidA* height;
};

#endif