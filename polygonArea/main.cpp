#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>

#define double long double

using namespace std;

ifstream fin("aria.in");
ofstream fout("aria.out");

struct Point{ double x, y; };
struct Seg{ Point p1, p2; };
struct Triangle{ Point p1, p2, p3; };
 
struct GEOMETRY{
	int n;
	vector <Point> points;
 
	GEOMETRY(){
		n = 0;
	}
 
	bool trigoCompare(Point a, Point b){
		if(a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}

	void trigoSort(){
		// sort(points.begin(), points.end(), trigoCompare);
	}

	double triangleArea(Triangle T){ // should be divided by 2
		return T.p1.x * (T.p2.y - T.p3.y) + T.p2.x * (T.p3.y - T.p1.y) + T.p3.x * (T.p1.y - T.p2.y);
	}
 
	int pointLocation(Point p, Seg s){
		double A = triangleArea({p, s.p1, s.p2});
 
		if(A == 0)
			return 0; // touches
		else if(A < 0)
			return 1; // down or right
		else
			return 2; // up or left
	}

	double poligonArea(Point reff){
		double A = 0;
		for(int i = 0; i < (int)points.size(); i++)
			A += triangleArea({reff, points[i], points[(i + 1) % n]});
		return (A / 2);
	}

	// TODO: new features
}G;

int main(){

	fin >> G.n;

	for(int i = 1; i <= G.n; i++){
		double x, y;
		fin >> x >> y;
		G.points.push_back({x, y});
	}

	fout << fixed << setprecision(5);
	fout << G.poligonArea({0, 0}) << '\n';

	return 0;
}