#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

#define int long long
#define pii pair <int, int>

using namespace std;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

const int NMAX = 5e4;
const int INF = 1e18;

vector <pii> adj[NMAX + 1];
priority_queue <pii, vector <pii>, greater <pii>> pq;
bool viz[NMAX + 1];
int dist[NMAX + 1];

int n, m;

void djk(int s){
	for(int i = 1; i <= n; i++)
		dist[i] = INF;

	dist[s] = 0;
	pq.push({dist[s], s});

	while(!pq.empty()){
		int nod = pq.top().second;
		pq.pop();

		if(!viz[nod]){
			for(auto vec : adj[nod])
				if(dist[vec.first] > dist[nod] + vec.second){
					dist[vec.first] = dist[nod] + vec.second;
					pq.push({dist[vec.first], vec.first});
				}

			viz[nod] = true;
		}
	}
}	

signed main(){

	fin >> n >> m;

	for(int i = 1; i <= m; i++){
		int a, b, c;
		fin >> a >> b >> c;
		adj[a].push_back({b, c});
	}

	djk(1);

	for(int i = 2; i <= n; i++){
		if(dist[i] == INF)
			fout << 0 << ' ';
		else
			fout << dist[i] << ' ';
	}

	fout << '\n';

	return 0;
}
