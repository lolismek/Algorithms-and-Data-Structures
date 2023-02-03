#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("bfs.in");
ofstream fout("bfs.out");

const int N = 1e5 + 1;
vector <int> adj[N];
vector <int> dist(N + 1, 0);

void bfs(int sursa, int n) {
	vector <int> viz(n + 1, 0);
	queue <int> coada;

	coada.push(sursa);
	viz[sursa] = 1;
	dist[sursa] = 0;

	while (!coada.empty()) {
		int nod = coada.front();
		coada.pop();
		for (auto vec : adj[nod]) {
			if (!viz[vec]) {
				dist[vec] = dist[nod] + 1;
				coada.push(vec);
				viz[vec] = 1;	
			}
		}
	}
}

int main() {
	int n, m, s;
	fin >> n >> m >> s;
	for (int i = 1; i <= m; i++) {
		int a, b;
		fin >> a >> b;
		adj[a].push_back(b);
		//adj[b].push_back(a); - graful este orientat, deci nu inseram si aici!
	}
	bfs(s, n);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == 0 && i != s) fout << -1 << " ";
		else fout << dist[i] << " ";
	}
	return 0;
}