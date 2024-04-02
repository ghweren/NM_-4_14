#include "TableCompactor.h"


std::vector<double> TableCompactor::x_generation(int comp_factor, int degree)
{
	degree++;
	std::vector<double> x;
	for (int i = 0; i<degree; i++)
		x.push_back(i*comp_factor);
	return x;
}

std::vector<double>TableCompactor::f_generation(std::vector<double> table, int degree, int start)
{
	degree++;
	std::vector<double> f;
	for (int i = 0; i<degree; i++)
		f.push_back(table[start + i]);
	return f;
}

std::vector<double>TableCompactor::Compaction(std::vector<double> table, int comp_factor, int degree)
{
	std::vector<double> YY;
	
	for (int i = 0; i<degree / 2; i++)
	{
		YY.push_back(table[i]);
		for (int j = 1; j<comp_factor; j++)
		{
			YY.push_back(interpolationMethod->Calculation(f_generation(table, degree, 0), x_generation(comp_factor, degree), i*comp_factor + j));
		}
	}
	for (int i = degree / 2; i<table.size() - degree; i++)
	{
		YY.push_back(table[i]);
		for (int j = 1; j<comp_factor / 2 + 1; j++)
		{
			YY.push_back(interpolationMethod->Calculation(f_generation(table, degree, i - degree / 2), x_generation(comp_factor, degree), degree / 2 * comp_factor + j));
		}
		for (int j = comp_factor / 2 + 1; j<comp_factor; j++)
		{
			YY.push_back(interpolationMethod->Calculation(f_generation(table, degree, i - degree / 2 + 1), x_generation(comp_factor, degree), (degree / 2 - 1)*comp_factor + j));
		}
	}
	for (int i = table.size() - degree; i<table.size() - 1; i++)
	{
		YY.push_back(table[i]);
		for (int j = 1; j<comp_factor; j++)
		{
			YY.push_back(interpolationMethod->Calculation(f_generation(table, degree, table.size() - degree - 1), x_generation(comp_factor, degree), (i - (table.size() - degree - 1))*comp_factor + j));
		}
	}
	YY.push_back(table[table.size() - 1]);
	return YY;
}
