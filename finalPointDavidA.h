/*
*  Program Name: FinalPointDavidA.h
*  Written By: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/

#ifndef FINALPOINTDAVIDA_H
#define FINALPOINTDAVIDA_H
#include "finalFractionDavidA.h"
#include <iostream>

class FinalPointDavidA {
public:

	FinalPointDavidA(void);
	~FinalPointDavidA(void);
	FinalPointDavidA(const FinalFractionDavidA&, const FinalFractionDavidA&);
	FinalPointDavidA(int, int);
	FinalPointDavidA(const FinalPointDavidA&);
	FinalPointDavidA& operator=(const FinalPointDavidA&);
	void moveBy(FinalFractionDavidA&, FinalFractionDavidA&);
	void moveBy(int);
	void flipByX();
	void flipByY();
	void flipThroughOrigin();
	FinalFractionDavidA getX(void) const;
	FinalFractionDavidA getY(void) const;
	void setX(FinalFractionDavidA&);
	void setY(FinalFractionDavidA&);
	friend std::ostream& operator<<(std::ostream&, const FinalPointDavidA&);
	friend std::istream& operator>>(std::istream&, FinalPointDavidA&);

private:
	FinalFractionDavidA* x;
	FinalFractionDavidA* y;
};

#endif