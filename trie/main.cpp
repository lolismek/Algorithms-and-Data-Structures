#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("trie.in");
ofstream fout("trie.out");

const int SIGMA = 26;
char s[SIGMA];

struct trie{
	int cnt, nr;
	trie *nxt[SIGMA];

	trie(){
		cnt = 0, nr = 0;
		for(int i = 0; i < SIGMA; i++)
			nxt[i] = 0;
	}
};

trie *root = new trie;

void insert_trie(trie *nod, char *s){
	if(*s == NULL){
		nod -> cnt++;
		return;
	}

	int ind = *s - 'a';
	if(nod -> nxt[ind] == 0){
		nod -> nxt[ind] = new trie;
		nod -> nr++;
	}
	insert_trie(nod -> nxt[ind], s + 1);
}

bool delete_trie(trie *nod, char *s){
	if(*s == NULL){
		nod -> cnt--;
	}else{
		int ind = *s - 'a';
		if(delete_trie(nod -> nxt[ind], s + 1)){
			nod -> nxt[ind] = 0;
			nod -> nr--;
		}
	}

	if(nod -> cnt == 0 && nod -> nr == 0 && nod != root)
		return true;
	return false;
}

int query_trie(trie *nod, char *s){
	if(*s == NULL)
		return nod -> cnt;

	int ind = *s - 'a';
	if(nod -> nxt[ind])
		return query_trie(nod -> nxt[ind], s + 1);
	return 0;
}

int prefix_trie(trie *nod, char *s, int len){
	if(*s == NULL)
		return len;

	int ind = *s - 'a';
	if(nod -> nxt[ind] == 0)
		return len;
	return prefix_trie(nod -> nxt[ind], s + 1, len + 1);
}

int main(){
	int cerinta;

	while(fin >> cerinta >> (s + 1)){
		if(cerinta == 0)
			insert_trie(root, (s + 1));
		else if(cerinta == 1)
			delete_trie(root, (s + 1));
		else if(cerinta == 2)
			fout << query_trie(root, (s + 1)) << '\n';
		else
			fout << prefix_trie(root, (s + 1), 0) << '\n';

	}
	return 0;
}