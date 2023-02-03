#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

//ifstream fin("euclid3.in");
//ofstream fout("euclid3.out");

const int NMAX = 4e6;
int Z[NMAX + 1]; 

int n;
string s;

void Zalgo(){
	for(int i = 1, l = 0, r = 0; i < n; i++){
		if(i <= r)
			Z[i] = min(r - i + 1, Z[i - l]);
		while(i + Z[i] < n && s[Z[i]] == s[Z[i] + i])
			Z[i]++;
		if(i + Z[i] - 1 >= r){
			l = i;
			r = i + Z[i] - 1;
		}
	}
}

int main(){

	string s1, s2;
	fin >> s1 >> s2;

	s = s1 + "$" + s2;
	n = s.size();

	Zalgo();

	int ans = 0;
	for(int i = (int)s1.size() + 1; i < n; i++)
		if(Z[i] == (int)s1.size())
			ans++;

	fout << ans << '\n';

	int cnt = 0;
	for(int i = (int)s1.size() + 1; i < n; i++){
		if(Z[i] == (int)s1.size() && cnt < 1000){
			fout << i - (int)s1.size() - 1 << ' ';
			cnt++;

			if(cnt == 1000)
				return 0;
		}
	}

	return 0;
}