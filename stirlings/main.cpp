#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("stirling.in");
ofstream fout("stirling.out");

const int N = 200, mod = 98999;
int s[N + 1][N + 1], S[N + 1][N + 1];

int main(){

	s[0][0] = S[0][0] = 1;

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++){
			(s[i][j] = (s[i - 1][j - 1] - (i - 1) * s[i - 1][j])) %= mod;
			(S[i][j] = S[i - 1][j - 1] + j * S[i - 1][j]) %= mod; 
		}

	int T;
	fin >> T;

	while(T--){
		int type, n, m;
		fin >> type >> n >> m;
		if(type == 1)
			fout << s[n][m] << '\n';
		else
			fout << S[n][m] << '\n';
	}

	return 0;
}