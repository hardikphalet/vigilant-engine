#include "Polynomial.h"

Polynomial::Polynomial(const int ord)  // initialiser for the polynomial class
{
	order = ord;
	for (int i = 0; i < order + 1; i++)
	{
		coeff.push_back(0.0);
	}
}

std::vector<double> Polynomial::getCoeff()  // getter for coefficients
{
	return coeff;
}

double Polynomial::valueAt(const double xVal)  // value of polynomial at particular value in it's domain
{
	double res = 0.0;
	for (double i = 0; i < coeff.size(); i++)
	{
		if (i == 0)
		{
			res += coeff[i];
		}
		else
		{
			res += coeff[i] * pow(xVal, i);
		}
	}
	return res;
}

void Polynomial::setCoeff()
{
	std::cout << "Enter coefficients of the polynomial, starting from the constant term seperated by space:::   ";
	for (int i = 0; i < order + 1; i++)
	{
		std::cin >> coeff[i];
	}
	std::cout << std::endl;
}

void Polynomial::setCoeff(double* inpCoeff) // sett
{
	coeff.clear();
	for (int i = 0; i < order + 1; i++)
	{
		coeff.push_back(*(inpCoeff+i));
	}
}

double Polynomial::minAt(double low, double high)
{
	return 0.0;
}

double Polynomial::maxVal(double low, double high)
{
	return 0.0;
}

double Polynomial::minVal(double low, double high)
{
	return 0.0;
}

double Polynomial::maxAt(double low, double high)
{
	return 0.0;
}

Polynomial Polynomial::derivative()
{
	Polynomial poly(order - 1);
	poly.coeff.clear();
	for (int i = 0; i < order; i++)
	{
		poly.coeff.push_back(coeff[i + 1] * (i + 1));
	}
	return poly;
}

double Polynomial::derivativeAt(const double xVal)
{
	return this->derivative().valueAt(xVal);
}

double Polynomial::newtonRaphson(double initial, double iterations)
{
	double res = 0.0;
	for (int i = 0; i < iterations; i++)
	{
		res -= (valueAt(res) / derivative().valueAt(res));
	}
	return res;
}

double Polynomial::newtonRaphsonLim(double initial, double eps)
{
	double h = valueAt(initial) / derivative().valueAt(initial);
	double res = initial;
	while (std::abs(h) >= eps)
	{
		h = valueAt(res) / derivative().valueAt(res);

		res -= h;
	}
	return res;
}
