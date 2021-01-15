#pragma once
#include <cmath>
#include <iostream>
class Polynomial
{
public:
	Polynomial(int ord);
	~Polynomial();
	double* getCoeff();
	double valueAt(double xVal);
	void setCoeff();

private:
	double* coeff;
	int order;
};