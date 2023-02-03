#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

ifstream fin("gauss.in");
ofstream fout("gauss.out");

const int N = 300;
const double eps = 1e-8;
double coef[N + 2][N + 2], sol[N + 1];
vector <pair <int, int>> adj[N + 1];

bool notNull(double x){
	return (x < -eps || x > eps);
}

void Gauss(/*double coef[N + 2][N + 2], double sol[N + 1], */int n, int m){
	int i = 1, j = 1;
	while(i <= n && j <= m){
		int k = i;
		while(k <= n){
			if(notNull(coef[k][j]))
				break;
			k++;
		}

		if(k == n + 1){
			j++;
			continue;
		}

		if(k != i)
			for(int jj = 1; jj <= m + 1; jj++)
				swap(coef[k][jj], coef[i][jj]);
		
		for(int jj = m + 1; jj >= j; jj--)
			coef[i][jj] /= coef[i][j];

		for(int ind = i + 1; ind <= n; ind++)
			for(int jj = m + 1; jj >= j; jj--)
				coef[ind][jj] -= coef[ind][j] * coef[i][jj];

		i++, j++;
	}

	for(int i = n; i >= 1; i--)
		for(int j = 1; j <= m + 1; j++)
			if(notNull(coef[i][j])){
				if(j == m + 1){
					fout << "Imposibil\n";
					exit(0); 
				}

				sol[j] = coef[i][m + 1];
				for(int jj = j + 1; jj <= m; jj++)
					sol[j] -= sol[jj] * coef[i][jj];

				break;
			}
}

int main(){

	int n, m;
	fin >> n >> m;

	/*for(int i = 1; i <= m; i++){
		int a, b, c;
		fin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	for(int i = 1; i <= n - 1; i++){
		double costSum = 0;

		for(auto vec : adj[i])
			coef[i][vec.first] = (1 / (double)adj[i].size()), costSum += vec.second;

		coef[i][n] = (-costSum / (double)adj[i].size());
		coef[i][i] = -1;
	}*/

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m + 1; j++)
			fin >> coef[i][j];

	Gauss(/*coef, sol, */n, m);

	fout << fixed << setprecision(10);

	for(int i = 1; i <= m; i++)
		fout << sol[i] << '\n';

	return 0;
}