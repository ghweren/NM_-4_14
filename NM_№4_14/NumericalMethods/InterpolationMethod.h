#pragma once
#include <vector>
class InterpolationMethod abstract
{
public:
	virtual double Calculation(std::vector <double> f, std::vector <double> x, double t) = 0;
};