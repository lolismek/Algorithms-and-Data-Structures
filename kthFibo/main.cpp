#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

#define int long long

using namespace std;

ifstream fin("kfib.in");
ofstream fout("kfib.out");

/* fast matrix exponantionation tools: */

const int N = 2, mod = 666013;

int aux[N + 1][N + 1];
void mult(int mat1[N + 1][N + 1], int mat2[N + 1][N + 1], int prod[N + 1][N + 1], int n, int m, int p){

	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= m; j++)
			aux[i][j] = 0;

	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= m; j++)
			for(int k = 1; k <= m; k++)
				(aux[i][j] += mat1[i][k] * mat2[k][j]) %= mod;

	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= m; j++)
			prod[i][j] = aux[i][j];
}	

int rez[N + 1][N + 1];
void exp(int m[N + 1][N + 1], int n, int exp){

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			rez[i][j] = 0;

	for(int i = 1; i <= n; i++)
		rez[i][i] = 1;

	while(exp != 0){
		if(exp % 2 != 0)
			mult(rez, m, rez, n, n, n);

		mult(m, m, m, n, n, n);

		exp /= 2;
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			m[i][j] = rez[i][j];
}

/*----------------------------------------------*/

int ans[N + 1][N + 1];
int trans[N + 1][N + 1];

signed main(){

	int n;
	fin >> n;

	ans[1][1] = 0;
	ans[1][2] = 1;

	trans[1][1] = 0;
	trans[1][2] = 1;
	trans[2][1] = 1;
	trans[2][2] = 1;

	exp(trans, 2, n - 1);

	mult(ans, trans, ans, 1, 2, 2);

	fout << ans[1][2] << '\n';

	return 0;
}