#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>

#define pb push_back

using namespace std;

ifstream fin("sortaret.in");
ofstream fout("sortaret.out");

const int N = 5 * 1e4 + 1;
vector <int> adj[N];
vector <int> rasp;
bitset <N> viz;

void dfs(int nod) {
	viz[nod] = 1;
	for (auto vec : adj[nod]) 
		if (!viz[vec]) 
			dfs(vec);
	rasp.pb(nod);
}


int main() {
	int n, m;
	fin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		fin >> a >> b;
		adj[a].pb(b);
	}
	for (int i = 1; i <= n; i++) 
		if (!viz[i]) dfs(i);
	for (int i = rasp.size() - 1; i >= 0; i--)
		fout << rasp[i] << " ";
	return 0;
}