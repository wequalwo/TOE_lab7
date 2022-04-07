#pragma once
#include <vector>
#include <iostream>
#define pi 3.1415926535897932384626433832795028841971
#define osc 0.1 // oscilloscope's accuracy, c^-1

class Calculus
{
private:
	const double I_accuracy = 0.01 * pow(10, -3); // ammeter's accuracy, A
	const double U_accuracy = 0.1; // voltmeter's accuracy, V
	const double w_accuracy = 0.4 * pow(10, 3); // generator's accuracy, Hz


	double w0_accuracy = 0.4 * pow(10, 3); // default generator's accuracy for resonance (frequency), Hz
	double I[2]; // real I, A (!)
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

	double multi_accuracy(std::vector<double*> units);
	void get_GR();
	void get_Q_rho();
	void get_LC();
	void get_vec();
	void out_vec();
	void out();

public:
	Calculus(double _I, double _U0, double _f0, double _Ic0, std::vector<std::vector<double>> _table, bool acc);

};
