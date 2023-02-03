#include <iostream>
#include <fstream>
#include <vector>
#include <vector>

using namespace std;

ifstream fin("cuplaj.in");
ofstream fout("cuplaj.out");

const int NMAX = 1e4;

int n1, n2, m;
vector <int> adj[NMAX + 1];
int l[NMAX + 1], r[NMAX + 1];
bool viz[NMAX + 1];

bool pairUp(int nod){
	if(viz[nod])
		return false;

	viz[nod] = true;

	for(int vec : adj[nod])
		if(!r[vec]){
			r[vec] = nod;
			l[nod] = vec;
			return true;
		}

	for(int vec : adj[nod])
		if(pairUp(r[vec])){
			r[vec] = nod;
			l[nod] = vec;
			return true;
		}

	return false;
}

int main(){

	int n1, n2, m;
	fin >> n1 >> n2 >> m;

	for(int i = 1; i <= m; i++){
		int a, b;
		fin >> a >> b;
		adj[a].push_back(b);
	}

	while(true){
		for(int i = 1; i <= n1; i++)
			viz[i] = false;

		bool ok = false;
		for(int i = 1; i <= n1; i++)
			if(!l[i])
				ok |= pairUp(i);

		if(!ok)
			break;
	}

	int maxMatch = 0;

	for(int i = 1; i <= n1; i++)
		if(l[i])
			maxMatch++;

	fout << maxMatch << '\n';

	for(int i = 1; i <= n1; i++)
		if(l[i])
			fout << i << ' ' << l[i] << '\n';

	return 0;
}