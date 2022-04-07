#pragma once
#include <vector>
#include <iostream>
#define pi 3.1415926535897932384626433832795028841971
#define osc 0.1 * pow(10, 3) // oscilloscope's accuracy, Hz
#define gac 0.4 * pow(10, 3) // generator's accuracy, Hz
class Calculus
{
private:
	const double I_accuracy = 0.01 * pow(10, -3); // ammeter's accuracy, A
	const double U_accuracy = 0.1; // voltmeter's accuracy, V
	const double w_accuracy = gac; // accuracy of frequency, Hz


	double w0_accuracy = 0.4 * pow(10, 3); // default generator's accuracy for resonance (frequency), Hz
	double I[2]; // real I, A (!)
	double R[2]; // resistance, \Omega
	double G[2]; // conductivity, Sm
	double U0[2]; // resonance voltage, V
	double Ic0[2]; // capacitor voltage, V
	double f0[2]; // resonance frequency, c^-1
	double Q[2]; // circuit Q-factor
	double rho[2]; // characteristic impedance
	double L[2]; // inductance
	double C[2]; // capacity

	std::vector<std::vector<double>> table; // table    | frequency | voltage | Z | Z accuracy |

	double multi_accuracy(std::vector<double*> units);
	void get_GR(); // conductivity resistance & calculations 
	void get_Q_rho(); // circuit Q-factor & characteristic impedance calculations 
	void get_LC(); // inductance & capacity calculations
	void get_vec(); // |Z(jw)| calculations

	// output
	void out_vec(); 
	void out();

public:
	Calculus(double _I, double _U0, double _f0, double _Ic0, std::vector<std::vector<double>> _table, bool acc);

};
