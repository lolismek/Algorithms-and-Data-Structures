#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("rmq.in");
ofstream fout("rmq.out");

const int N = 1e5, LOGN = 17;
int rmq[N + 1][LOGN + 1];

// rmq[i][j] = minimul din intervalul incepand cu i de lungime 2 ^ j
// pas initial: rmq[i][0] = v[i], pt. orice i
// calcularea recurenta: rmq[i][j] = min(rmq[i][j - 1]), rmq[i + (1 << (j - 1))][j - 1])
// ^^^ nu conteaza ca vom ignora unele bucati, fiindca nu le folosim
// query (x, y): l = log2(y - x + 1), ans = min(rmq[x][l], rmq[y - (1 << l) + 1][l])

int main(){
    int n, q;
    fin >> n >> q;
    for(int i = 1; i <= n; i++) fin >> rmq[i][0];
    for(int j = 1; (1 << j) <= n; j++){
        for(int i = 1; i <= n; i++){
            rmq[i][j] = rmq[i][j - 1];
            if(i + (1 << (j - 1)) <= n) rmq[i][j] = min(rmq[i][j], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
    while(q--){
        int x, y;
        fin >> x >> y;
        int l = log2(y - x + 1);
        fout << min(rmq[x][l], rmq[y - (1 << l) + 1][l]) << '\n';
    }
    return 0;
}