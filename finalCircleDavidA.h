/*
*  Program Name: FinalCircleDavidA.h
*  Written By: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/

#ifndef FINALCIRCLEDAVIDA_H
#define FINALCIRCLEDAVIDA_H

#include "finalFractionDavidA.h"
#include "finalPointDavidA.h"
#include "shapeDavidA.h"
#include <iostream>

class FinalCircleDavidA : public virtual ShapeDavidA {
public:

	FinalCircleDavidA(void);
	~FinalCircleDavidA(void);
	FinalCircleDavidA(const FinalCircleDavidA&);
	FinalCircleDavidA(const FinalPointDavidA&, const FinalFractionDavidA&);
	FinalCircleDavidA(const FinalFractionDavidA&);
	FinalCircleDavidA& operator=(const FinalCircleDavidA&);
	FinalCircleDavidA operator+(const FinalCircleDavidA&);
	FinalFractionDavidA getArea(void) const;
	FinalFractionDavidA getVolume(void) const;
	FinalFractionDavidA getRad(void) const;
	FinalPointDavidA getCen(void) const;
	void setRad(const FinalFractionDavidA&);
	void setCen(const FinalPointDavidA&);
	void print(void) const;
	ostream& printOut(ostream&) const;

protected:
	FinalPointDavidA* cen;
	FinalFractionDavidA* rad;
	const FinalFractionDavidA PI;
};

#endif