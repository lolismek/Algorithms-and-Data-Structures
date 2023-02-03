#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int main() {
	int t;
	fin >> t;
	while (t--) {
		int n;
		fin >> n;
		int xor_sum = 0;
		for (int i = 0; i < n; i++) {
			int x;
			fin >> x;
			xor_sum ^= x;
		}
		if (xor_sum) fout << "DA";
		else fout << "NU";
		fout << '\n';
	}
	return 0;
}