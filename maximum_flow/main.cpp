#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

using namespace std;

ifstream fin("maxflow.in");
ofstream fout("maxflow.out");

const int NMAX = 1000;
const int INF = 1e9;

vector <int> adj[NMAX + 1];

int n, m;
int f[NMAX + 1][NMAX + 1];
int parent[NMAX + 1];
bool viz[NMAX + 1];


bool BFS(int nod){
	for(int i = 1; i <= n; i++)
		viz[i] = parent[i] = 0;

	queue <int> Q;

	Q.push(1);
	viz[1] = true;

	while(!Q.empty()){
		int nod = Q.front();
		Q.pop();

		if(nod == n)
			return true;

		for(auto vec : adj[nod])
			if(!viz[vec] && f[nod][vec] > 0){
				parent[vec] = nod;
				Q.push(vec);
				viz[vec] = true;
			}

	}

	return false;
}

int main(){

	fin >> n >> m;

	for(int i = 1; i <= m; i++){
		int a, b, c;
		fin >> a >> b >> c;	
		adj[a].push_back(b);
		adj[b].push_back(a);
		f[a][b] = c;
	}

	int maxFlow = 0;
	while(BFS(1)){
		for(auto vec : adj[n]){
			if(f[vec][n] <= 0 || !viz[vec])
				continue;

			parent[n] = vec;

			int mini = INF;
			int nod = n;

			while(nod != 1){
				mini = min(mini, f[parent[nod]][nod]);
				nod = parent[nod]; 
			}

			if(mini == 0)
				continue;

			maxFlow += mini;
			nod = n;

			while(nod != 1){
				f[parent[nod]][nod] -= mini;
				f[nod][parent[nod]] += mini;
				nod = parent[nod];
			}
		}
	}

	fout << maxFlow << '\n';

	return 0;
}