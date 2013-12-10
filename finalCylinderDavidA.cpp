/*
*  Program Name: FinalCylinderDavidA.cpp
*  Written By: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/

#include <iostream>
#include "finalFractionDavidA.h"
#include "finalPointDavidA.h"
#include "finalCircleDavidA.h"
#include "finalCylinderDavidA.h"

using namespace std;

FinalCylinderDavidA::FinalCylinderDavidA(void) : ShapeDavidA("Cylinder"), FinalCircleDavidA() {
	height = new FinalFractionDavidA(1);
}

FinalCylinderDavidA::~FinalCylinderDavidA(void) {
	delete height;
}

FinalCylinderDavidA::FinalCylinderDavidA(const FinalCylinderDavidA& old) : ShapeDavidA("Cylinder"), FinalCircleDavidA(old) {
	height = new FinalFractionDavidA(old.getHeight());
}

FinalCylinderDavidA::FinalCylinderDavidA(const FinalPointDavidA& cen1, const FinalFractionDavidA& rad1, const FinalFractionDavidA& h) : ShapeDavidA("Cylinder"), FinalCircleDavidA(cen1, rad1) {
	height = new FinalFractionDavidA(h);
}

FinalCylinderDavidA::FinalCylinderDavidA(const FinalCircleDavidA& oldC, const FinalFractionDavidA& h) : ShapeDavidA("Cylinder"), FinalCircleDavidA(oldC) {
	height = new FinalFractionDavidA(h);
}

FinalCylinderDavidA& FinalCylinderDavidA::operator=(const FinalCylinderDavidA& old) {
	*height = old.getHeight();
	setCen(old.getCen());
	setRad(old.getRad());

	return *this;
}

FinalCylinderDavidA FinalCylinderDavidA::operator+(const FinalCylinderDavidA& old) {
	FinalFractionDavidA tempH, tempR;
	FinalPointDavidA tempP;

	if (getHeight() > old.getHeight())
		tempH = old.getHeight();
	else
		tempH = getHeight();

	if (getRad() > old.getRad())
		tempR = getRad();
	else
		tempR = old.getRad();

	tempP = FinalPointDavidA(FinalFractionDavidA((old.getCen().getX() + getCen().getX()) / 2), FinalFractionDavidA((old.getCen().getY() + getCen().getY()) / 2));

	return FinalCylinderDavidA(tempP, tempR, tempH);
}

FinalFractionDavidA FinalCylinderDavidA::getArea(void) const {
	return FinalFractionDavidA((PI * getRad() * getRad() * 2) + (PI * getHeight() * getRad() * 2));
}

FinalFractionDavidA FinalCylinderDavidA::getVolume(void) const {
	return FinalFractionDavidA(PI * getHeight() * getRad() * getRad());
}

FinalFractionDavidA FinalCylinderDavidA::getHeight(void) const {
	return *height;
}

void FinalCylinderDavidA::setHeight(const FinalFractionDavidA& value) {
	*height = value;

	return;
}

ostream& FinalCylinderDavidA::printOut(ostream& os) const {
	os << "Shape of " << getName() << ":" << endl
		<< "Radius of: " << getRad() << endl
		<< "Height of: " << getHeight() << endl
		<< "Center at: " << getCen() << endl
		<< "Area of  : " << getArea() << endl
		<< "Volume of: " << getVolume() << endl;

	return os;
}