#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("royfloyd.in"); ofstream fout("royfloyd.out");

struct edge{ int from, to, cost; };
const int N = 100, inf = 1e9 + 1;
vector <edge> edges;
int rf[N + 1][N + 1];

int main(){
    int n;
    fin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x;
            fin >> x;
            rf[i][j] = x;
            if(!x) rf[i][j] = inf;
        }
        rf[i][i] = 0;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(!rf[i][j]) rf[i][j] = inf;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                if(rf[i][k] != inf && rf[k][j] != inf) rf[i][j] = min(rf[i][j], rf[i][k] + rf[k][j]);
            rf[i][i] = 0;
        }
    for(int i = 1; i <= n; i++, fout << '\n')
        for(int j = 1; j <= n; j++, fout << ' ') fout << rf[i][j];
    return 0;
}