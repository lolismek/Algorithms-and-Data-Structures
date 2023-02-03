#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

const int N = 2e5, M = 4e5;
struct edge{
	int a, b, c;
}e[M + 1];

bool cmp(edge e1, edge e2){
	return e1.c < e2.c;
}

int sef[N + 1];

int Find(int i){
	if(sef[i] == i)
		return i;
	return sef[i] = Find(sef[i]);
}

void Union(int i, int j){
	int sefI = Find(i), sefJ = Find(j);
	sef[sefJ] = sefI;
}

int main(){

	int n, m;
	fin >> n >> m;

	for(int i = 1; i <= m; i++)
		fin >> e[i].a >> e[i].b >> e[i].c;
	
	sort(e + 1, e + m + 1, cmp);

	for(int i = 1; i <= n; i++)
		sef[i] = i;

	int cost = 0;
	vector <edge> ans;
	for(int i = 1; i <= m; i++){
		if(Find(e[i].a) != Find(e[i].b)){
			Union(e[i].a, e[i].b);
			ans.push_back(e[i]);
			cost += e[i].c;
		}

		if((int)ans.size() == n - 1)
			break;
	}

	fout << cost << '\n' << n - 1 << '\n';

	for(auto x : ans)
		fout << x.a << ' ' << x.b << '\n';

	return 0;
}