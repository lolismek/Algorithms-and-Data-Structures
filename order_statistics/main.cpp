#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("sdo.in");
ofstream fout("sdo.out");

const int N = 3 * 1e6 + 1;
int v[N];

int main() {
	int n, k;
	fin >> n >> k;
	for (int i = 0; i < n; i++) fin >> v[i];
	nth_element(v, v + k - 1, v + n);
	fout << v[k - 1];
	return 0;
}