#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("ssm.in");
ofstream fout("ssm.out");

int main() {
	long long n, sum = 0, min_sum = 0, rasp = -1e18, min_poz = 0, l, r;
	fin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		fin >> x;
		sum += x;
		if (sum - min_sum > rasp) {
			rasp = sum - min_sum;
			l = min_poz + 2;
			r = i + 1;
		}
		if (sum < min_sum) {
			min_sum = sum;
			min_poz = i;
		}
	}
	fout << rasp << " " << l << " " << r;
	return 0;
}