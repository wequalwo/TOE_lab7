#include <iostream>
#include <math.h>
#include <vector>

#include "Calculus.h"
int main()
{
	setlocale(LC_ALL, "rus");
	std::cout.precision(20);
	std::vector<std::vector<double>> table = { {5.5, 32.8}, {4.4, 26.4}, {5.0, 20.9}, {3.75, 10}, {2.25, 1} };

	Calculus calc1(0.5, 33.8, 4.5, 10.61, table, false);
}