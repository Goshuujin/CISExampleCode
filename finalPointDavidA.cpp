/*
*  Program Name: FinalPointDavidA.cpp
*  Written By: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/
#include "FinalPointDavidA.h"
using namespace std;

FinalPointDavidA::FinalPointDavidA(void) {
	x = new FinalFractionDavidA();
	y = new FinalFractionDavidA();
}

FinalPointDavidA::~FinalPointDavidA(void) {
	delete x;
	delete y;
}

FinalPointDavidA::FinalPointDavidA(const FinalFractionDavidA& run, const FinalFractionDavidA& rise) {
	x = new FinalFractionDavidA(run);
	y = new FinalFractionDavidA(rise);
}

FinalPointDavidA::FinalPointDavidA(int run, int rise) {
	x = new FinalFractionDavidA(run);
	y = new FinalFractionDavidA(rise);
}

FinalPointDavidA::FinalPointDavidA(const FinalPointDavidA& old) {
	x = new FinalFractionDavidA(old.getX());
	y = new FinalFractionDavidA(old.getY());
}

FinalPointDavidA& FinalPointDavidA::operator=(const FinalPointDavidA& old) {
	setX(old.getX());
	setY(old.getY());

	return *this;
}

void FinalPointDavidA::moveBy(FinalFractionDavidA& delX, FinalFractionDavidA& delY) { 
	setX(getX() + delX);
	setY(getY() + delY);

	return;
} 

void FinalPointDavidA::moveBy(int iOld) {
	setX(getX() + iOld);
	setY(getY() + iOld);

	return;
} 

void FinalPointDavidA::flipByX() {
	setX(-(getX()));

	return;
} 

void FinalPointDavidA::flipByY() { 
	setY(-(getY()));

	return;
} 

void FinalPointDavidA::flipThroughOrigin() { 
	setX(-(getX()));
	setY(-(getY()));

	return;
} 

FinalFractionDavidA FinalPointDavidA::getX() const {
	return *x;
}

FinalFractionDavidA FinalPointDavidA::getY() const {
	return *y;
}

	void FinalPointDavidA::setX(FinalFractionDavidA& old) {
		*x = old;

		return;
	}

	void FinalPointDavidA::setY(FinalFractionDavidA& old) {
		*y = old;

		return;
	}

ostream& operator<<(ostream& os, const FinalPointDavidA& old) {
	os << "(" << old.getX() << ", " << old.getY() << ")";

	return os;
}

istream& operator>>(istream& is, FinalPointDavidA& old) {
	cout << "\nInput X coordintate: \n";
	is >> *(old.x);
	cout << "\nInput Y coordinate: \n";
	is >> *(old.y);

	return is;
}