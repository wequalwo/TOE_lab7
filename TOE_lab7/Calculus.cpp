#include "Calculus.h"
#include <algorithm>



bool comp(std::vector<double> left, std::vector<double> right)
{

	return left[0] > right[0];

}

Calculus::Calculus(double _I, double _U0, double _f0, double _Ic0, std::vector<std::vector<double>> _table, bool acc)
{
	I[0] = _I * pow(10, -3);
	I[1] = I_accuracy;

	U0[0] = _U0;
	U0[1] = U_accuracy;

	Ic0[0] = _Ic0 * pow(10, -3);
	Ic0[1] = I_accuracy;

	table = _table;

	if (acc)
	{
		w0_accuracy = osc;
	}
	f0[0] = _f0 * pow(10, 3);
	f0[1] = w0_accuracy;

	// let's calculate it
	get_GR();
	get_Q_rho();
	get_LC();
	get_vec();

	// resault
	out();
	out_vec();
}
double Calculus::multi_accuracy(std::vector<double*> units)
{
	double res = 0;
	for (int i = 0; i < units.size(); i++)
	{
		res += units[i][1] / units[i][0];
	}
	return(res);
}
void Calculus::get_GR()
{
	G[0] = I[0] / U0[0];
	G[1] = G[0] * multi_accuracy({ I, U0 });
	R[0] = U0[0] / I[0];
	R[1] = R[0] * multi_accuracy({ I, U0 });
}
void Calculus::get_Q_rho()
{
	Q[0] = Ic0[0] / I[0];
	Q[1] = Q[0] * multi_accuracy({ Ic0, I });

	rho[0] = R[0] / Q[0];
	rho[1] = rho[0] * multi_accuracy({ R, Q });
}

void Calculus::get_LC()
{
	L[0] = rho[0] / (2 * pi * f0[0]);
	L[1] = L[0] * multi_accuracy({ rho, f0 });


	C[0] = 1 / (2 * pi * f0[0] * rho[0]);
	C[1] = C[0] * multi_accuracy({ rho, f0 });
}
void Calculus::get_vec()
{
	double U[2] = { 0, U_accuracy };
	for (int i = 0; i < table.size(); i++)
	{
		U[0] = table[i][1];
		table[i].push_back(U[0] / I[0]);
		table[i].push_back(table[i][2] * multi_accuracy({ U, I }));
	}
	table.push_back({ f0[0] * pow(10, -3), U0[0], R[0], R[1] });
}
void Calculus::out_vec()
{
	std::cout << "\nTable:\n";
	std::sort(table.begin(), table.end(), comp);
	for (auto i : table)
	{
		if (i[0] == f0[0] * pow(10, -3))
		{
			std::cout << "\x1b[33m";
		}

		std::cout << "f = " << i[0]
			<< ", U = " << i[1]
			<< ", |Z(jw)| = (" << i[2] * pow(10, -3)
			<< " +- " << i[3] * pow(10, -3) << ") k\\Omega\n\x1b[0m";
	}
	std::cout << "\n\nPoints |Z(jw)|, [Z] = k\\Omega, [f] = kHz\n";
	std::cout << " x         y\n";
	for (auto j : table)
	{
		std::cout << " " << j[0] << "     " << j[2]*pow(10, -3) << "\n";
	}
}
void Calculus::out()
{
	std::cout.precision(3);
	std::cout << "G = (" << G[0] * pow(10, 6) << " +- " << G[1] * pow(10, 6) << ") \\nuSm\n";
	std::cout << "R = (" << R[0] * pow(10, -3) << " +- " << R[1] * pow(10, -3) << ") k\\Omega\n";

	std::cout << "Q = (" << Q[0] << " +- " << Q[1] << ")\n";
	std::cout << "rho = (" << rho[0] * pow(10, -3) << " +- " << rho[1] * pow(10, -3) << ") k\\Omega\n";

	std::cout << "L = (" << L[0] * pow(10, 3) << " +- " << L[1] * pow(10, 3) << ") mH\n";
	std::cout << "C = (" << C[0] * pow(10, 9) << " +- " << C[1] * pow(10, 9) << ") \nF\n";

	std::cout << "\nLet's check it: f0 = \x1b[32m" << f0[0]
		<< "\x1b[0m = w / (2pi) = 1 / [sqrt(LC)*2pi] = \x1b[32m"
		<< (1 / (2 * pi)) / sqrt(L[0] * C[0]) << "\x1b[m\n";
	std::cout << "\n";
}
