#pragma once
#include <cmath>
#include <iostream>
#include <vector>
class Polynomial
{
public:
	Polynomial(int ord);
	std::vector<double> getCoeff();  // returns coefficient array
	double valueAt(double xVal); // returns the value of the polynomail at xVal
	void setCoeff(); // basic "cin" way to add data
	void setCoeff(double* inpCoeff); // adding data by making a double array first

	double minAt(double low, double high);
	double minVal(double low, double high);
	double maxVal(double low, double high);
	double maxAt(double low, double high);

	Polynomial derivative();  // returns another polynomial which is a derivative of the previous one
	double derivativeAt(double xVal); // value of dervative at a particular value

private:
	std::vector<double> coeff; // the coefficient vector, (a_0 + a_1 x + a_2 x^2 +...)  this vector contains all the a_i's
	int order; // order of the polynomial
};