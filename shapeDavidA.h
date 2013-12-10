/*
*  Program Name: shapeDavidADavidA.h
*  Written By: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/


#ifndef SHAPEDAVIDA_H
#define SHAPEDAVIDA_H

#include <iostream>
#include <string>
#include "finalFractionDavidA.h"
#include "finalPointDavidA.h"

using namespace std;

class ShapeDavidA {
public:
	ShapeDavidA(void) {
		name = new string("Shape");
	}
	
	virtual ~ShapeDavidA(void) {
		delete name;
	}

	ShapeDavidA(string i) {
		name = new string(i);
	}

	ShapeDavidA(const ShapeDavidA& old) {
		name = new string(old.getName());
	}

	virtual ShapeDavidA& operator=(const ShapeDavidA& old) {
		setName(old.getName());

		return *this;
	}

	virtual string getName(void) const {
		return *name;
	}

	virtual void setName(string old) {
		*name = old;
		
		return;
	}

	virtual FinalFractionDavidA getArea(void) const = 0;

	virtual FinalFractionDavidA getVolume(void) const = 0;

	virtual ostream& printOut(ostream&) const = 0;

	friend ostream& operator<<(ostream& os, const ShapeDavidA& old) {
		return (old.printOut(os));
	}

protected:
	string* name;
};

#endif