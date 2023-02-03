#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ifstream fin("mergeheap.in");
ofstream fout("mergeheap.out");

const int N = 100;
priority_queue <int> pq[N + 1];

int main(){

	int n, q;
	fin >> n >> q;

	while(q--){
		int type;
		fin >> type;

		if(type == 1){
			int m, x;
			fin >> m >> x;
			pq[m].push(x);
		}else if(type == 2){
			int m;
			fin >> m;
			fout << pq[m].top() << '\n';
			pq[m].pop();
		}else{
			int a, b;
			fin >> a >> b;
			if(pq[a].size() < pq[b].size())
				pq[a].swap(pq[b]);

			while(!pq[b].empty())
				pq[a].push(pq[b].top()), pq[b].pop();
		}
	}

	return 0;
}