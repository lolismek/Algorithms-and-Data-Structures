#include <iostream>
#include <fstream>

using namespace std;

//ifstream fin("shumen.in");
//ofstream fout("shumen.out");

ifstream fin("euclid3.in");
ofstream fout("euclid3.out");

int euclid(int a, int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}

	int x0, y0, d;
	d = euclid(b, a % b, x0, y0);
	x = y0;
	y = x0 - (a / b) * y0;

	return d;
}

void solve(){
	int a, b, c;
	fin >> a >> b >> c;

	int x, y;
	int d = euclid(a, b, x, y);

	if(c % d != 0)
		fout << 0 << ' ' << 0 << '\n';
	else
		fout << x * (c / d) << ' ' << y * (c / d) << '\n';

}

int main(){

	int T;
	fin >> T;

	while(T--)
		solve();

	return 0;
}