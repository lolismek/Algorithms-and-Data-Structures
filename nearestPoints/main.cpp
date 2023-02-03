#include <algorithm>
#include <iostream>
#include <fstream>
#include <complex>
#include <iomanip>
#include <random>
#include <time.h>
#include <cmath>

using namespace std;

ifstream fin("cmap.in");
ofstream fout("cmap.out");

const int NMAX = 1e5;
const double INF = 2e9;
const double PI = 4 * atan(1);

complex <double> points[NMAX + 1];

mt19937 Rand(clock());

bool cmp(complex <double> a, complex <double> b){
	if(a.real() == b.real())
		return a.imag() < b.imag();
	return a.real() < b.real();
}

signed main(){

	int n;
	fin >> n;

	double theta = (Rand() % 360) * PI;

	for(int i = 1; i <= n; i++){
		double x, y;
		fin >> x >> y;
		points[i] = complex <double> {x, y};
		points[i] = points[i] * polar(1.0, theta);
	}

	sort(points + 1, points + n + 1, cmp);

	double minDist = INF;

	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(points[j].real() - points[i].real() >= minDist)
				break;

			minDist = min(minDist, abs(points[i] - points[j]));
		}
	}

	fout << fixed << setprecision(6) << minDist << '\n';

	return 0;
}