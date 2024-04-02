#pragma once
#include "InterpolationMethod.h"
class TableCompactor
{
private:
	InterpolationMethod *interpolationMethod;
public:
	TableCompactor(InterpolationMethod *interpolationMethod)
	{
		this->interpolationMethod = interpolationMethod;
	}
	std::vector<double> x_generation(int comp_factor, int degree);
	std::vector<double> f_generation(std::vector<double> table, int degree, int start);
	std::vector<double> Compaction(std::vector<double> table, int comp_factor, int degree);
};