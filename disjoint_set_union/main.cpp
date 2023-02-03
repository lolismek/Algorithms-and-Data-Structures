#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("disjoint.in");
ofstream fout("disjoint.out");

const int N = 1e5 + 1;
int m[N];

void init(int n) {
	for (int i = 1; i <= n; i++) m[i] = i;
}

int my_find(int i) {
	if (m[i] == i) return i;
	return m[i] = my_find(m[i]);
}

void my_union(int i, int j) {
	int sefi, sefj;
	sefi = my_find(i);
	sefj = my_find(j);
	m[sefj] = sefi;
}

int main() {
	int n, t;
	fin >> n >> t;
	init(n);
	while (t--) {
		int cerr, a, b;
		fin >> cerr >> a >> b;
		if (cerr == 1) {
			my_union(a, b);
		} else {
			if (my_find(a) == my_find(b)) fout << "DA" << "\n";
			else fout << "NU" << "\n";
		}
	}
	return 0;
}