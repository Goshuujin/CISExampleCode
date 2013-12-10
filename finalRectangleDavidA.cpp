/*
*  Program Name: FinalRectangleDavidA.cpp
*  Written By: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/

#include "finalRectangleDavidA.h"
#include "finalPointDavidA.h"
#include "finalFractionDavidA.h"
#include "shapeDavidA.h"
#include <iostream>

using namespace std;

FinalRectangleDavidA::FinalRectangleDavidA() : ShapeDavidA("Rectangle") {
	upRight = new FinalPointDavidA();
	lowLeft = new FinalPointDavidA();
}

FinalRectangleDavidA::~FinalRectangleDavidA() {
	delete upRight;
	delete lowLeft;
}

FinalRectangleDavidA::FinalRectangleDavidA(const FinalRectangleDavidA& old) : ShapeDavidA("Rectangle") {
	upRight = new FinalPointDavidA(old.getUpRight());
	lowLeft = new FinalPointDavidA(old.getLowLeft());
}

FinalRectangleDavidA::FinalRectangleDavidA(const FinalPointDavidA& upR, const FinalPointDavidA& lowL) : ShapeDavidA("Rectangle") {
	upRight = new FinalPointDavidA(upR);
	lowLeft = new FinalPointDavidA(lowL);
}

FinalRectangleDavidA::FinalRectangleDavidA(const FinalFractionDavidA& length, const FinalFractionDavidA& width) : ShapeDavidA("Rectangle") {
	upRight = new FinalPointDavidA(length, width);
	lowLeft = new FinalPointDavidA();
}

FinalRectangleDavidA& FinalRectangleDavidA::operator=(const FinalRectangleDavidA& old) {
	setUpRight(old.getUpRight());
	setLowLeft(old.getLowLeft());

	return *this;
}

FinalFractionDavidA FinalRectangleDavidA::getArea() const {
	FinalFractionDavidA temp((getUpRight().getX() - getLowLeft().getX()) * (getUpRight().getY() - getLowLeft().getY()));

	if (temp > 0)
		return temp;
	else
		return -temp;
}

FinalFractionDavidA FinalRectangleDavidA::getVolume() const {
	return FinalFractionDavidA(0);
}

FinalFractionDavidA FinalRectangleDavidA::getLength() const {
	if ((getUpRight().getX() - getLowLeft().getX()) > (getUpRight().getY() - getLowLeft().getY()))
		return (getUpRight().getX() - getLowLeft().getX());
	else
		return (getUpRight().getY() - getLowLeft().getY());
}

FinalFractionDavidA FinalRectangleDavidA::getWidth() const {
	if ((getUpRight().getX() - getLowLeft().getX()) < (getUpRight().getY() - getLowLeft().getY()))
		return (getUpRight().getX() - getLowLeft().getX());
	else
		return (getUpRight().getY() - getLowLeft().getY());
}

FinalPointDavidA FinalRectangleDavidA::getUpRight() const {
	return *upRight;
}

FinalPointDavidA FinalRectangleDavidA::getLowLeft() const {
	return *lowLeft;
}

void FinalRectangleDavidA::setUpRight(const FinalPointDavidA& old) {
	*upRight = old;

	return;
}
void FinalRectangleDavidA::setLowLeft(const FinalPointDavidA& old) {
	*lowLeft = old;

	return;
}

ostream& FinalRectangleDavidA::printOut(ostream& os) const {
	os << "Shape of " << getName() << ":" << endl
		<< "Upper right point at: " << getUpRight() << endl
		<< "Lower left point at : " << getLowLeft() << endl
		<< "Area of             : " << getArea() << endl;

	return os;
}