#pragma once
#include <vector>
#include <iostream>
#define pi 3141592653589793238462643383279
#define osc 0.1 // oscilloscope's accuracy, c^-1

class Calculus
{
private:
	const double I_accuracy = 0.01; // ammeter's accuracy, mA
	const double U_accuracy = 0.1; // voltmeter's accuracy, V
	const double w_accuracy = 0.4; // generator's accuracy, kHz

	
	double w0_accuracy = 0.4; // default generator's accuracy for resonance (frequency), kHz
	double I[2]; // real I, mA
	double R[2]; // resistance, Ω
	double G[2]; // conductivity, 1/Ω
	double U0[2]; // resonance voltage, V
	double Ic0[2]; // capacitor voltage, V
	double f0[2]; // resonance frequency, c^-1
	double Q[2]; // 
	double rho[2];
	double L[2];
	double C[2];

	std::vector<std::vector<double>> table; // table    | frequency | voltage | Z | Z accuracy |

	double multi_accuracy(std::vector<double[2]> units)
	{
		double res = 0;
		for (int i = 0; i < units.size(); i++)
		{
			res += units[i][1] / units[i][0];
		}
		return(res);
	}
	void get_GR();
	void get_Q_rho();
	void get_L();
	void get_C();

public:
	Calculus(double _I, double _U0, double f0, double _Ic0, std::vector<std::vector<double>> _table, bool acc);

};
