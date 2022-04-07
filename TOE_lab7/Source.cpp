#include <iostream>
#include <math.h>
#include <vector>

#include "Calculus.h"
int main()
{
	std::cout << "\n\x1b[31m               7.3.1\x1b[0m\n\n";
	setlocale(LC_ALL, "rus");
	std::cout.precision(20);
	std::vector<std::vector<double>> table1 = { {5.5, 32.8}, {4.4, 26.4}, {5.0, 20.9}, {3.75, 10}, {2.25, 1} };

	Calculus calc1(0.5, 33.8, 4.5, 10.61, table1, false);
	std::cout << "\n\n\n\x1b[36mLet's try osc:\x1b[0m\n";
	Calculus calc1_1(0.5, 42.5, 3.77, 10.61, table1, true);


	std::cout << "\n\n\n\x1b[31m               7.3.2\x1b[0m\n\n";
	std::vector<std::vector<double>> table2 = { {3.8, 5}, {5.2, 4.1}, {6, 2.8}, {8.2, 1.5}, {12, 0.7} };
	Calculus calc2(0.65, 5.7, 3.9, 1.89, table2, true);

	std::cout << "\n\n\n\x1b[31m               7.3.3\x1b[0m\n\n";
	std::vector<std::vector<double>> table3 = { {2.8, 4.2}, {2.18, 2}, {3.7, 1.5}, {4.5, 0.5} };
	Calculus calc3(0.65, 5.3, 3.0, 3.18, table3, true);


}