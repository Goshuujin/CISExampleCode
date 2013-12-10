/*
*  Program Name: FinalFractionDavidA.cpp
*  Written by: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/

#include <iostream>
#include "finalFractionDavidA.h"

using namespace std;

//Default constructor
FinalFractionDavidA::FinalFractionDavidA(void) { 
	num = new int(0);
	denom = new int(1);
}

//Constructor for inputs
FinalFractionDavidA::FinalFractionDavidA(int a, int b) {
	num = new int(a);
	denom = new int(1);
	setDenom(b);
	reduce();
}

//Conversion Constructor
FinalFractionDavidA::FinalFractionDavidA(int a) { 
	num = new int(a);
	denom = new int(1);
}

//Copy Constructor
FinalFractionDavidA::FinalFractionDavidA(const FinalFractionDavidA& old) {
	num = new int(old.getNum());
	denom = new int(old.getDenom());
}

//Destructor
FinalFractionDavidA::~FinalFractionDavidA() {
	delete num;
	delete denom;
}

//Get numerator
int FinalFractionDavidA::getNum(void) const { 
	return *num;
}

//Get denominator
int FinalFractionDavidA::getDenom(void) const { 
	return *denom;
}

//Set numerator
void FinalFractionDavidA::setNum(int n) { 
	*num = n;
}

//Set denominator
void FinalFractionDavidA::setDenom(int d) { 
	if (d != 0) {
		*denom = d;

		if (*denom < 0) {
			*denom = -*(denom);
			*num = -*(num);
		}
	} else {
		cout << "\n\n\tERROR! ATTEMPT TO DIVIDE BY ZERO!" << endl 
			<< "\nDenominator set to (1) by default!" << endl;
	}
}

//Find and return the Least Common Denominator of the object
int FinalFractionDavidA::lCD(int n, int d) const { 

	if (n % d) 
		return lCD(d, (n % d));
	else {
		(d < 0) ? d = -d : d = d;
		return d;
	}
}

//Returns a reduced fraction object based off of the LCD
FinalFractionDavidA& FinalFractionDavidA::reduce(void) { 
	int lcd = lCD(getNum(), getDenom());

	setNum(getNum() / lcd);
	setDenom(getDenom() / lcd);

	return *this;
}

void FinalFractionDavidA::update(int n, int d) {
	setNum(n);
	setDenom(d);
}

//Returns the addition of this and another fraction
FinalFractionDavidA FinalFractionDavidA::operator+(const FinalFractionDavidA& old) const { 

	return FinalFractionDavidA(((getNum() * old.getDenom()) + (old.getNum() * getDenom())), (getDenom() * old.getDenom()));
}

//Returns the subtraction of this and another fraction
FinalFractionDavidA FinalFractionDavidA::operator-(const FinalFractionDavidA& old) const {

	return FinalFractionDavidA(((getNum() * old.getDenom()) - (old.getNum() * getDenom())), (getDenom() * old.getDenom()));
}

//Returns the multiplication of this and another fraction
FinalFractionDavidA FinalFractionDavidA::operator*(const FinalFractionDavidA& old) const { 

	return FinalFractionDavidA((getNum() * old.getNum()), (getDenom() * old.getDenom()));
}

//Returns the division of this and another fraction
FinalFractionDavidA FinalFractionDavidA::operator/(const FinalFractionDavidA& old) const { 

	return FinalFractionDavidA((getNum() * old.getDenom()), (getDenom() * old.getNum()));
}

FinalFractionDavidA FinalFractionDavidA::operator/(int old) const {

	return FinalFractionDavidA(getNum(), (getDenom() * old));
}

FinalFractionDavidA& FinalFractionDavidA::operator+=(const FinalFractionDavidA& old) {
	setNum((getNum() * old.getDenom()) + (old.getNum() * getDenom()));
	setDenom(getDenom() * old.getDenom());
	reduce();

	return *this;
}

FinalFractionDavidA& FinalFractionDavidA::operator+=(int old) {
	setNum(getNum() + (old * getDenom()));
	reduce();

	return *this;
}

//Returns the value of the updated left hand side of the argument
FinalFractionDavidA& FinalFractionDavidA::operator=(const FinalFractionDavidA& old) {
	setNum(old.getNum());
	setDenom(old.getDenom());
	reduce();

	return *this;
}

FinalFractionDavidA& FinalFractionDavidA::operator=(int old) {
	setNum(old);
	setDenom(1);

	return *this;
}

FinalFractionDavidA FinalFractionDavidA::operator-(void) const {

	return FinalFractionDavidA(-(getNum()), getDenom());
}

bool FinalFractionDavidA::operator>(const FinalFractionDavidA& old) const {

	return ((getNum() * old.getDenom()) > (old.getNum() * getDenom()));
}

bool FinalFractionDavidA::operator<(const FinalFractionDavidA& old) const {

	return ((getNum() * old.getDenom()) < (old.getNum() * getDenom()));
}

bool FinalFractionDavidA::operator==(int old) const {
	return (getNum() == (getDenom() * old));
}

ostream& operator<<(ostream& os, const FinalFractionDavidA& old) {
	os << old.getNum() << " / " << old.getDenom();

	return os;
}

istream& operator>>(istream& is, FinalFractionDavidA& old) {
	bool check = false;

	cout << "\nNumerator: ";
	is >> *(old.num);

	do {
		if (check)
			cout << "\nThe denominator cannot be zero! Please try again." << endl;
		cout << "Denominator: ";
		is >> *(old.denom);
		check = true;   
	} while (*(old.denom) == 0);

	old.setDenom(old.getDenom());
	old.reduce();

	return is;
}