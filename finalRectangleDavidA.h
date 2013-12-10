/*
*  Program Name: FinalRectangleDavidA.h
*  Written By: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/

#ifndef FINALRECTANGLEDAVIDA_H
#define FINALRECTANGLEDAVIDA_H

#include "finalFractionDavidA.h"
#include "finalPointDavidA.h"
#include "shapeDavidA.h"
#include <iostream>

class FinalRectangleDavidA : public virtual ShapeDavidA {
public:

	FinalRectangleDavidA(void);
	~FinalRectangleDavidA(void);
	FinalRectangleDavidA(const FinalRectangleDavidA&);
	FinalRectangleDavidA(const FinalPointDavidA&, const FinalPointDavidA&);
	FinalRectangleDavidA(const FinalFractionDavidA&, const FinalFractionDavidA&);
	virtual FinalRectangleDavidA& operator=(const FinalRectangleDavidA&);
	FinalFractionDavidA getArea(void) const;
	FinalFractionDavidA getVolume(void) const;
	FinalFractionDavidA getLength(void) const;
	FinalFractionDavidA getWidth(void) const;
	FinalPointDavidA getUpRight(void) const;
	FinalPointDavidA getLowLeft(void) const;
	void setUpRight(const FinalPointDavidA&);
	void setLowLeft(const FinalPointDavidA&);
	ostream& printOut(ostream&) const;

protected:
	FinalPointDavidA* upRight;
	FinalPointDavidA* lowLeft;
};

#endif