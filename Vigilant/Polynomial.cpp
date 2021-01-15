#include "Polynomial.h"

Polynomial::Polynomial(int ord)
{
	order = ord;
	coeff = new double[order + 1];
}

Polynomial::~Polynomial()
{
	delete[] coeff;
}

double* Polynomial::getCoeff()
{
	if (order == 0)
	{
		return nullptr;
	}
	else
	{
		return coeff;
	}
}

void Polynomial::setCoeff()
{
	for (int i = 0; i < order + 1; i++)
	{
		std::cin >> *(coeff + i);
	}
}

double Polynomial::valueAt(double xVal)
{
	double res = 0.0;
	for (int i = 0; i < order + 1; i++)
	{
		res += pow(xVal, i) * *(coeff + i);
	}
	return res;
}
