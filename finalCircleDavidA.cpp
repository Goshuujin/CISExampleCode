/*
*  Program Name: FinalCircleDavidA.cpp
*  Written By: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/

#include "finalCircleDavidA.h"
#include "finalFractionDavidA.h"
#include "finalPointDavidA.h"
#include "shapeDavidA.h"
#include <iostream>
using namespace std;


FinalCircleDavidA::FinalCircleDavidA(void) : ShapeDavidA("Circle"), PI(157, 50) {
	cen = new FinalPointDavidA();
	rad = new FinalFractionDavidA();
}

FinalCircleDavidA::~FinalCircleDavidA(void) {
	delete cen;
	delete rad;
}

FinalCircleDavidA::FinalCircleDavidA(const FinalCircleDavidA& old) : ShapeDavidA("Circle"), PI(157, 50) {
	cen = new FinalPointDavidA(old.getCen());
	rad = new FinalFractionDavidA(old.getRad());
}

FinalCircleDavidA::FinalCircleDavidA(const FinalPointDavidA& cen1, const FinalFractionDavidA& rad1) : ShapeDavidA("Circle"), PI(157, 50) {
	cen = new FinalPointDavidA(cen1);
	rad = new FinalFractionDavidA(rad1);
}

FinalCircleDavidA::FinalCircleDavidA(const FinalFractionDavidA& rad1) : ShapeDavidA("Circle"), PI(157, 50) {
	cen = new FinalPointDavidA();
	rad = new FinalFractionDavidA(rad1);
}

FinalCircleDavidA& FinalCircleDavidA::operator=(const FinalCircleDavidA& old) {
	setCen(old.getCen());
	setRad(old.getRad());

	return *this;
}

FinalCircleDavidA FinalCircleDavidA::operator+(const FinalCircleDavidA& old) {
	return FinalCircleDavidA(FinalPointDavidA(FinalFractionDavidA((old.getCen().getX() + getCen().getX()) / 2), FinalFractionDavidA((old.getCen().getY() + getCen().getY()) / 2)), (getRad() + old.getRad()));
}

FinalFractionDavidA FinalCircleDavidA::getArea() const {
	return (FinalFractionDavidA((getRad() * getRad()) * PI));
}

FinalFractionDavidA FinalCircleDavidA::getVolume() const {
	return FinalFractionDavidA(0);
}

FinalFractionDavidA FinalCircleDavidA::getRad() const {
	return *rad;
}

FinalPointDavidA FinalCircleDavidA::getCen() const {
	return *cen;
}

void FinalCircleDavidA::setRad(const FinalFractionDavidA& old) {
	*rad = old;

	return;
}

void FinalCircleDavidA::setCen(const FinalPointDavidA& old) {
	*cen = old;

	return;
}

void FinalCircleDavidA::print() const {
	cout << *this;

	return;
}

ostream& FinalCircleDavidA::printOut(ostream& os) const {
	os << "Shape of " << getName() << ":" << endl
		<< "Radius of: " << getRad() << endl
		<< "Center at: " << getCen() << endl
		<< "Area of  : " << getArea() << endl;

	return os;
}