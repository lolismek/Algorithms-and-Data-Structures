#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

ifstream fin("hamilton.in");
ofstream fout("hamilton.out");

const int N = 18, inf = 1e9 + 1;
vector <int> in[N + 1];
int cost[N + 1][N + 1], dp[(1 << N)][N + 1];

int main(){
	int n, m;
	fin >> n >> m;
	for(int i = 1; i <= m; i++){
		int a, b, c;
		fin >> a >> b >> c, cost[a][b] = c;
		in[b].push_back(a);
	}

	for(int mask = 0; mask < (1 << n); mask++)
		for(int i = 0; i < n; i++)
			dp[mask][i] = inf;

	dp[1][0] = 0;
	for(int mask = 1; mask < (1 << n); mask++)
		for(int i = 0; i < n; i++)
			if((mask & (1 << i)) == (1 << i))
				for(auto vec : in[i])
					if((mask & (1 << vec) == (1 << vec)))
						dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][vec] + cost[vec][i]);

	int ans = inf;
	for(auto vec : in[0])
		ans = min(ans, dp[(1 << n) - 1][vec] + cost[vec][0]);

	if(ans == inf){
		fout << "Nu exista solutie\n";
		return 0;
	}

	fout << ans;

	return 0;
}