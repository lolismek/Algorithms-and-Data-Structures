#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("arbint.in");
ofstream fout("arbint.out");

const int N = 1e5;
int aint[4 * N + 1], ans;

int left_son(int nod){
	return 2 * nod;
}

int right_son(int nod){
	return 2 * nod + 1;
}

void update(int nod, int st, int dr, int poz, int val){
	if(st == dr){
		aint[nod] = val;
		return;
	}

	int mij = (st + dr) / 2;
	if(poz <= mij)
		update(left_son(nod), st, mij, poz, val);
	else
		update(right_son(nod), mij + 1, dr, poz, val);
	aint[nod] = max(aint[left_son(nod)], aint[right_son(nod)]);
}

void query(int nod, int st, int dr, int Qst, int Qdr){
	if(Qst <= st && dr <= Qdr){
		ans=  max(ans, aint[nod]);
		return;
	}

	int mij = (st + dr) / 2;
	if(Qst <= mij)
		query(left_son(nod), st, mij, Qst, Qdr);
	if(mij + 1 <= Qdr)
		query(right_son(nod), mij + 1, dr, Qst, Qdr);
}

int main(){
	int n, q;
	fin >> n >> q;

	for(int i = 1; i <= n; i++){
		int x;
		fin >> x;
		update(1, 1, n, i, x);
	}

	while(q--){
		int cerinta, a, b;
		fin >> cerinta >> a >> b;

		if(cerinta == 0){
			ans = -1;
			query(1, 1, n, a, b);
			fout << ans << '\n';
		}else{
			update(1, 1, n, a, b);
		}
	}

	return 0;
}