#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

const int N = 1e5;
vector <int> adj[N + 1];

int depth[N + 1], lowLink[N + 1];
bool viz[N + 1], onStack[N + 1];

stack <int> s;
vector <int> comp[N + 1];

int ind = 0, Comp = 0;
void Tarjan(int nod){
	depth[nod] = lowLink[nod] = ++ind;
	viz[nod] = onStack[nod] = true;
	s.push(nod);

	for(auto vec : adj[nod])
		if(!viz[vec])
			Tarjan(vec), lowLink[nod] = min(lowLink[nod], lowLink[vec]);
		else if(onStack[vec])
			lowLink[nod] = min(lowLink[nod], depth[vec]);

	if(lowLink[nod] == depth[nod]){
		while(s.top() != nod)
			comp[nod].push_back(s.top()), onStack[s.top()] = false, s.pop();
		comp[nod].push_back(nod), onStack[nod] = false, s.pop();
		Comp++;
	}
}

int main(){

	int n, m;
	fin >> n >> m;

	for(int i = 1; i <= m; i++){
		int a, b;
		fin >> a >> b;
		adj[a].push_back(b);
	}

	for(int i = 1; i <= n; i++)
		if(!viz[i])
			Tarjan(i);

	fout << Comp << '\n';

	for(int i = 1; i <= n; i++){
		for(auto x : comp[i])
			fout << x << ' ';
		if(comp[i].size() > 0)
			fout << '\n';
	}

	return 0;
}