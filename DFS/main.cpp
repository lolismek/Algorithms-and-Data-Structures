#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("dfs.in");
ofstream fout("dfs.out");

const int N = 1e5 + 1;
vector <int> adj[N];
vector <int> viz(N + 1, 0);

void dfs(int nod, int tata) {
	viz[nod] = 1;
	for (auto vec : adj[nod])
		if (!viz[vec])
			dfs(vec, nod);
}

int main() {
	int n, m;
	fin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		fin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (!viz[i]) 
			dfs(i, i), cnt++;
	fout << cnt;
	return 0;
}