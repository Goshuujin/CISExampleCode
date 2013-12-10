/*
*  Program Name: FinalFractionDavidA.h
*  Written By: David Allen
*  Date: 11/26/13
*  Part of Project: Lab 7 Ex 1
*/

#ifndef FINALFRACTIONDAVIDA_H
#define FINALFRACTIONDAVIDA_H
#include <iostream>

class FinalFractionDavidA {
public:

	FinalFractionDavidA(void);
	FinalFractionDavidA(int, int);
	FinalFractionDavidA(int);
	FinalFractionDavidA(const FinalFractionDavidA&);
	~FinalFractionDavidA(void);
	int getNum(void) const;
	int getDenom(void) const;
	void setNum(int);
	void setDenom(int);
	int lCD(int, int) const;
	void update(int, int);
	FinalFractionDavidA& reduce(void);
	FinalFractionDavidA operator+(const FinalFractionDavidA&) const;
	FinalFractionDavidA operator-(const FinalFractionDavidA&) const;
	FinalFractionDavidA operator-(void) const;
	FinalFractionDavidA operator*(const FinalFractionDavidA&) const;
	FinalFractionDavidA operator/(const FinalFractionDavidA&) const;
	FinalFractionDavidA operator/(int) const;
	FinalFractionDavidA& operator+=(const FinalFractionDavidA&);
	FinalFractionDavidA& operator+=(int);
	FinalFractionDavidA& operator=(const FinalFractionDavidA&);
	FinalFractionDavidA& operator=(int);
	bool operator==(int old) const;
	bool operator>(const FinalFractionDavidA&) const;
	bool operator<(const FinalFractionDavidA&) const;
	friend std::ostream& operator<<(std::ostream&, const FinalFractionDavidA&);
	friend std::istream& operator>>(std::istream&, FinalFractionDavidA&);

private:

	int* num;
	int* denom;
};

#endif