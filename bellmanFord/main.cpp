#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>

using namespace std;

ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

const int NMAX = 5e4;
const int INF = 1e9;

struct Node{
	int node;
	int cost;
};

int n, m;
vector <Node> adj[NMAX + 1];
int dist[NMAX + 1], f[NMAX + 1];
bool cycle;

void BF(int start){
	for(int i = 1; i <= n; i++)
		dist[i] = INF;

	queue <int> Q;

	Q.push(start);
	dist[start] = 0;

	while(!Q.empty()){
		int nod = Q.front();
		Q.pop();

		if(++f[nod] > n){
			cycle = true;
			return;
		}	

		for(auto vec : adj[nod])
			if(dist[nod] + vec.cost < dist[vec.node]){
				dist[vec.node] = dist[nod] + vec.cost;
				Q.push(vec.node);
			}
	}
}

int main(){

	fin >> n >> m;

	for(int i = 1; i <= m; i++){
		int a, b, c;
		fin >> a >> b >> c;
		adj[a].push_back({b, c});
	}

	BF(1);

	if(cycle){
		fout << "Ciclu negativ!\n";
		return 0;
	}

	for(int i = 2; i <= n; i++)
		fout << dist[i] << ' ';

	return 0;
}