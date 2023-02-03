#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("radixsort.in");
ofstream fout("radixsort.out");

const int N = (int)1e7, BASE = 256;
int v[N + 1], w[N + 1], f[BASE + 1], poz[BASE + 1];

int main(){
	int n, a, b, c;
	fin >> n >> a >> b >> c;

	v[1] = b;
	for(int i = 2; i <= n; i++)
		v[i] = (1ll * a * v[i - 1] + b) % c;

	for(int e = 0, masky = BASE - 1; e < 32; e += 8, masky <<= 8){
		for(int i = 1; i <= n; i++)
			f[((v[i] & masky) >> e)]++;
		for(int cif = 1; cif < BASE; cif++)
			f[cif] += f[cif - 1];
		for(int i = 1; i <= n; i++){
			int cif = (v[i] & masky) >> e;
			poz[cif]++;
			if(cif == 0)
				w[poz[cif]] = v[i];
			else
				w[f[cif - 1] + poz[cif]] = v[i]; 
		}

		for(int i = 1; i <= n; i++)
			v[i] = w[i];

		for(int i = 0; i < BASE; i++)
			f[i] = poz[i] = 0;
	}
		

	for(int i = 1; i <= n; i += 10)
		fout << v[i] << ' ';

	return 0;
}
