#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("lca.in");
ofstream fout("lca.out");

const int NMAX = 1e5;
const int LOGMAX = 17;

int dp[NMAX + 1][LOGMAX + 1];
vector <int> adj[NMAX + 1];
int level[NMAX + 1];

void DFS(int nod, int parent){
	level[nod] = level[parent] + 1;

	for(int child : adj[nod])
		if(child != parent)
			DFS(child, nod);
}

int LCA(int a, int b){
	if(level[a] < level[b])
		swap(a, b);

	int diff = level[a] - level[b];

	for(int i = LOGMAX; i >= 0; i--)
		if(diff & (1 << i))
			a = dp[a][i];

	if(a == b)
		return a;

	for(int i = LOGMAX; i >= 0; i--)
		if(dp[a][i] != dp[b][i]){
			a = dp[a][i];
			b = dp[b][i];
		}

	return dp[a][0];
}

int main(){

	int n, q;
	fin >> n >> q;

	for(int i = 2; i <= n; i++){
		fin >> dp[i][0];
		adj[i].push_back(dp[i][0]);
		adj[dp[i][0]].push_back(i);
	}

	DFS(1, 0);

	for(int j = 1; (1 << j) <= n; j++)
		for(int i = 1; i <= n; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];

	while(q--){
		int a, b;
		fin >> a >> b;
		fout << LCA(a, b) << '\n';
	}

	return 0;
}