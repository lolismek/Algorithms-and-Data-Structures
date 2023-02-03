// retelistica extrem de nesimtita
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <climits>
 
#define pii pair <int, int>
 
using namespace std;
 
ifstream fin("cmcm.in");
ofstream fout("cmcm.out");
 
const int N = 710, inf = INT_MAX; 
int dist[N + 1], cdist[N + 1], from[N + 1], aux[N + 1];
int f[N + 1][N + 1], cost[N + 1][N + 1];
int n, m, S, D, maxFlow = 0, minCost = 0;
 
vector <int> adj[N + 1];
 
void BF(){
	for(int i = 0; i <= n; i++)
		aux[i] = inf;
 
	queue <int> Q;
	Q.push(S), aux[S] = 0;
 
	while(!Q.empty()){
		int nod = Q.front();
		Q.pop();
 
		for(auto vec : adj[nod])
			if(aux[nod] + cost[nod][vec] < aux[vec] && f[nod][vec] > 0)
				aux[vec] = aux[nod] + cost[nod][vec], Q.push(vec);
	}
}
 
priority_queue <pii, vector <pii>, greater <pii>> pq;
bool DJK(){
	for(int i = 0; i <= n; i++)
		dist[i] = cdist[i] = inf;
 
	pq.push({0, S});
	dist[S] = cdist[S] = 0;
 
	while(!pq.empty()){
		int nod = pq.top().second, val = pq.top().first;
		pq.pop();
 
		if(val == dist[nod])
			for(auto vec : adj[nod])
				if(f[nod][vec] > 0 && dist[nod] + cost[nod][vec] + aux[nod] - aux[vec] < dist[vec]){
					dist[vec] = dist[nod] + cost[nod][vec] + aux[nod] - aux[vec];
					cdist[vec] = cdist[nod] + cost[nod][vec];
					pq.push({dist[vec], vec}), from[vec] = nod;
				}
	}
 
	return(dist[D] != inf);
}
 
signed main(){
 
	int nL, nR;
	fin >> nL >> nR >> m;

	S = 0, D = nL + nR + 1;
 
 	vector <pii> edges;
	for(int i = 1; i <= m; i++){
		int a, b, z;
		fin >> a >> b >> z;
		adj[a].push_back(b + nL);
		adj[b + nL].push_back(a);
		f[a][b + nL] = inf, cost[a][b + nL] = z, cost[b + nL][a] -= z;
		edges.push_back({a, b + nL});
	}
 
	for(int i = 1; i <= nL; i++){
		adj[S].push_back(i);
		adj[i].push_back(S);
		f[S][i] = 1;
	}

	for(int i = 1; i <= nR; i++){
		adj[i + nL].push_back(D);
		adj[D].push_back(i + nL);
		f[i + nL][D] = 1;
	}

	n = nL + nR + 1;

	BF();
 
	while(DJK()){
		int nod = D, flow = inf;
 
		while(nod != S)
			flow = min(flow, f[from[nod]][nod]), nod = from[nod];
 
		nod = D, maxFlow += flow;
 
		while(nod != S)
			f[from[nod]][nod] -= flow, f[nod][from[nod]] += flow, nod = from[nod];
		
		minCost += flow * cdist[D];
 
		for(int i = 1; i <= n; i++)
			aux[i] = dist[i];
	}
 
	fout << maxFlow << ' ' << minCost << '\n';
 
	for(int i = 0; i < (int)edges.size(); i++){
		pii x = edges[i];
		if(f[x.first][x.second] < inf)
			fout << i + 1 << ' ';
	}

	fout << '\n';

	return 0;
}