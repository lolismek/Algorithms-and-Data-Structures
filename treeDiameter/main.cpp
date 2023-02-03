#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("darb.in");
ofstream fout("darb.out");

const int N = 1e5 + 1, INF = 1e9 + 1;
vector <int> adj[N];
vector <int> distante1(N + 1, 0);

void bfs(int radacina, int n) {
	vector <int> viz(n + 1, 0);
	queue <int> coada;

	coada.push(radacina);
	viz[radacina] = 1;
	distante1[radacina] = 0;

	while (!coada.empty()) {
		int nod = coada.front();
		coada.pop();
		for (auto vec : adj[nod]) {
			if (!viz[vec]) {
				distante1[vec] = distante1[nod] + 1;
				viz[vec] = 1;
				coada.push(vec);
			}
		}
	}
}

int main() {
	int n;
	fin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		fin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	bfs(1, n);
	int c2, dmax = -INF;
	for (int i = 0; i < distante1.size(); i++) {
		if (distante1[i] > dmax) {
			dmax = distante1[i];
			c2 = i;
		}
	}
	bfs(c2, n);
	int c1; dmax = -INF;
	for (int i = 0; i < distante1.size(); i++) {
		if (distante1[i] > dmax) {
			dmax = distante1[i];
			c1 = i;
		}
	}
	fout << dmax + 1 << endl;
	return 0;
}