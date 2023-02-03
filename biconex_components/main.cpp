#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("biconex.in");
ofstream fout("biconex.out");

const int N = 1e5;
vector <int> adj[N + 1], comp[N + 1];
int lowLink[N + 1], depth[N + 1];
bool viz[N + 1];

int Comp = 0, ind = 0;
stack <int> S;

void DFS(int nod, int parent){	
	depth[nod] = lowLink[nod] = ++ind;
	viz[nod] = true;
	S.push(nod);

	for(auto vec : adj[nod]){
		if(vec == parent)
			continue;

		if(viz[vec])
			lowLink[nod] = min(lowLink[nod], depth[vec]);
		else{
			DFS(vec, nod);
			lowLink[nod] = min(lowLink[nod], lowLink[vec]);
			if(lowLink[vec] >= depth[nod]){
				++Comp;
				while(S.top() != vec)
					comp[Comp].push_back(S.top()), S.pop();
				comp[Comp].push_back(vec), S.pop();
				comp[Comp].push_back(nod);
			}
		}
	}

}	

int main(){

	int n, m;
	fin >> n >> m;

	for(int i = 1; i <= m; i++){
		int a, b;
		fin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	DFS(1, 0);

	fout << Comp << '\n';
	for(int i = 1; i <= Comp; i++, fout << '\n')
		for(auto x : comp[i])
			fout << x << ' ';

	return 0;
}