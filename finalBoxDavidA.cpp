/*
*  Program Name: FinalBoxDavidAV2.cpp
*  Written By: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/

#include <iostream>
#include "finalFractionDavidA.h"
#include "finalPointDavidA.h"
#include "finalRectangleDavidA.h"
#include "finalBoxDavidA.h"

using namespace std;

FinalBoxDavidA::FinalBoxDavidA(void) : ShapeDavidA("Box"), FinalRectangleDavidA() {
	height = new FinalFractionDavidA(1);
	}

FinalBoxDavidA::~FinalBoxDavidA(void) {
	delete height;
	}

FinalBoxDavidA::FinalBoxDavidA(FinalPointDavidA& uR, FinalPointDavidA& lL, FinalFractionDavidA& h) : ShapeDavidA("Box"), FinalRectangleDavidA(uR, lL) {
	height = new FinalFractionDavidA(h);
	}

FinalBoxDavidA::FinalBoxDavidA(FinalPointDavidA& uR, FinalPointDavidA& lL, int h) : ShapeDavidA("Box"), FinalRectangleDavidA(uR, lL) {
	height = new FinalFractionDavidA(h);
	}

FinalBoxDavidA::FinalBoxDavidA(const FinalRectangleDavidA& rec, const FinalFractionDavidA& h) : ShapeDavidA("Box"), FinalRectangleDavidA(rec) {
	height = new FinalFractionDavidA(h);
}

FinalBoxDavidA::FinalBoxDavidA(const FinalBoxDavidA& old) : ShapeDavidA(old), FinalRectangleDavidA(old) {
	height = new FinalFractionDavidA(old.getHeight());
}

FinalBoxDavidA& FinalBoxDavidA::operator=(const FinalBoxDavidA& old) {
	setUpRight(old.getUpRight()); 
	setLowLeft(old.getLowLeft()); 
	setHeight(old.getHeight());
	setName(old.getName());

	return *this;
}

FinalFractionDavidA FinalBoxDavidA::getArea() const {
	return FinalFractionDavidA(((getLength() * getWidth()) + (getLength() * getHeight()) + (getWidth() * getHeight())) * 2);
}

FinalFractionDavidA FinalBoxDavidA::getVolume() const {
	return FinalFractionDavidA(getLength() * getWidth() * getHeight());
}

FinalFractionDavidA FinalBoxDavidA::getHeight() const {
	return (*height);
}

void FinalBoxDavidA::setHeight(const FinalFractionDavidA& value) {
	*height = value;

	return;
}

ostream& FinalBoxDavidA::printOut(ostream& os) const {
	os << "Shape of " << getName() << ":" << endl
		<< "Upper Right point of: " << getUpRight() << endl
		<< "Lower Left point of : " << getLowLeft() << endl
		<< "Height of           : " << getHeight() << endl
		<< "Area of             : " << getArea() << endl
		<< "Volume of           : " << getVolume() << endl;

	return os;
}