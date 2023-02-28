#include <cstdio>
#include <cmath>

double const r5 = std::sqrt(5);
double const phi = (1 + r5) * .5;
double const psi = (1 - r5) * .5;

double fibb(unsigned int n) { return (std::pow(phi, n) - std::pow(psi, n))  / r5; }
double fibb_phi(unsigned int n) { return std::pow(phi, n) / r5; }
unsigned int fibb_u(unsigned int n, unsigned int a = 0, unsigned int b = 1) { return n == 0 ? a : fibb_u(n-1, b, a+b); }

int main() {
	for (unsigned int i = 0; i < 20; i++)
		fprintf(stdout, "%u\t%u\t%lf\t%lf\t%lf\n", i, fibb_u(i), fibb(i), fibb(i) - fibb_phi(i), std::round(fibb_phi(i)));
	return 0;
}
