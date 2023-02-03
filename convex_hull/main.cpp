#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream fin("infasuratoare.in");
ofstream fout("infasuratoare.out");

const int NMAX = 12e4;

struct Point{
	double x, y;
};

Point v[NMAX + 1];

bool cmp(Point a, Point b){
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

double area(Point p1, Point p2, Point p3){
	return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y);
}

vector <Point> convexHull(Point v[], int n){
	sort(v + 1, v + n + 1, cmp);

	vector <Point> up, down;

	up.push_back(v[1]);
	down.push_back(v[1]);

	for(int i = 2; i <= n; i++){
		while((int)up.size() > 1 && area(up[(int)up.size() - 2], up[(int)up.size() - 1], v[i]) >= 0)
			up.pop_back();
		up.push_back(v[i]);
		while((int)down.size() > 1 && area(down[(int)down.size() - 2], down[(int)down.size() - 1], v[i]) <= 0)
			down.pop_back();
		down.push_back(v[i]);
	}

	vector <Point> CH = up;
	for(int i = (int)down.size() - 2; i >= 1; i--)
		CH.push_back(down[i]);

	reverse(CH.begin(), CH.end());

	return CH;
}

int main(){

	int n;
	fin >> n;

	for(int i = 1; i <= n; i++)
		fin >> v[i].x >> v[i].y;

	vector <Point> CH = convexHull(v, n);

	fout << (int)CH.size() << '\n';

	fout << fixed << setprecision(12);

	for(auto p : CH)
		fout << p.x << ' ' << p.y << '\n';

	return 0;
}

/*
speta 1:
	cati cicli
speta 2:
	nr de partitonari

s[i][j] = s[i - 1][j - 1] + (i - 1) * s[i - 1][j]

S[i][j] = S[i - 1][j - 1] + j *	S[i - 1][j]
*/