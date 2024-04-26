#pragma once
#include "InterpolationMethod.h"
class LagrangePolinomial : public InterpolationMethod
{
public:
	double Calculation(std::vector<double> f, std::vector<double> x, double t)
	{
		std::vector<double> L;
		for (int i = f.size() - 1; i > -1; i--)
		{
			x.push_back(x[i]);
			x.erase(x.begin() + i);
			double numenator = 1;
			double denumenator = 1;
			for (size_t j = 0; j < f.size() - 1; j++)
			{
				numenator *= (t - x[j]);
				denumenator *= (x[x.size() - 1] - x[j]);
			}
			L.push_back(numenator / denumenator);
		}
		double result = 0;
		for (size_t i = 0; i < f.size(); i++)
		{
			result += (f[i] * L[L.size() - 1 - i]);
		}
		return result;
	}
};