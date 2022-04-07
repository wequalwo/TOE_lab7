#include "Calculus.h"
Calculus::Calculus(double _I, double _U0, double _f0, double _Ic0, std::vector<std::vector<double>> _table, bool acc)
{
	I[0] = _I;
	I[1] = I_accuracy;

	U0[0] = _U0;
	U0[1] = U_accuracy;

	Ic0[0] = _Ic0;
	Ic0[1] = I_accuracy;

	table = _table;

	if (acc)
	{
		w0_accuracy = osc;
	}
	get_GR();
}
void Calculus::get_GR()
{
	G[0] = I[0] / U0[0];
	G[1] = G[0] * multi_accuracy(I, U0);
	R[0] = U0[0] / I[0];
	R[1] = R[0] * multi_accuracy(I, U0);


	G[0] *= pow(10, -3);
	G[1] *= pow(10, -3);

	R[0] /= pow(10, -3);
	R[1] /= pow(10, -3);

	std::cout.precision(3);
	std::cout << "G = (" << G[0] * pow(10, 6) << " +- " << G[1]*pow(10, 6) << ") ìêÑì\n";
	std::cout.precision(3);
	std::cout << "R = (" << R[0]*pow(10, -3) << " +- " << R[1]* pow(10, -3) << ") k[Omega]\n";
}
void Calculus::get_Q_rho()
{
	Q[0] = Ic0[0] / I[0];
	Q[1] = Q[0]*multi_accuracy(Ic0[0])
}
