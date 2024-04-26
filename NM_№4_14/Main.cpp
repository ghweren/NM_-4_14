#include <iostream>
#include "NumericalMethods\TableCompactor.h"
#include "NumericalMethods\LagrangePolinomial.h"
#include <iomanip>
#include <vector>
using namespace std;

double function(double x)
{
	return x*x*x;
}

vector<double> table_generation(int start, int step, int num_of_points)
{
	vector<double> table;
	for (int i = 0; i < num_of_points; i++)
	{
		table.push_back(function(start));
		start += step;
	}
	return table;
}

void print_table(vector<double> table)
{
	cout << '\n';
	for (int i = 0; i<table.size(); i++)
		cout << setw(15) << table[i] << ' ';
	cout << '\n';
}
int main()
{
	try{
		int num_of_points, comp_factor, degree;
		double start, step;
		cout << "\nEnter the number of points - ";
		cin >> num_of_points;
		if (num_of_points < 2)
			throw invalid_argument("Invalide number of points");
		cout << "\nEnter the compaction factor - ";
		cin >> comp_factor;
		cout << "\nEnter the start - ";
		cin >> start;
		cout << "\nEnter the step - ";
		cin >> step;
		cout << "\nEnter the degree of the polynomial - ";
		cin >> degree;
		if (degree >= num_of_points)
			throw invalid_argument("Impossible to compaction");
		vector<double> table = table_generation(start, step, num_of_points);
		LagrangePolinomial *lagrangePolinomial = new LagrangePolinomial();
		TableCompactor tableCompactor(lagrangePolinomial);
		vector<double> comp_table = tableCompactor.Compaction(table, comp_factor, degree);
		print_table(table);
		print_table(comp_table);
	}
	catch (exception e)
	{
		cout << e.what();
	}
	int a;
	cin >> a;
}