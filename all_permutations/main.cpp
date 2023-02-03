#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

ifstream fin("permutari.in");
ofstream fout("permutari.out");

const int N = 8;
int v[N + 1], n;
bitset <N + 1> viz;

void afisare(){
    for(int i = 1; i <= n; i++) fout << v[i] << ' ';
    fout << '\n';
}

void bkt(int poz){
    if(poz == n + 1){
        afisare();
        return;
    }
    for(int i = 1; i <= n; i++)
        if(!viz[i])
            v[poz] = i, viz[i] = 1,
            bkt(poz + 1), viz[i] = 0;
}

int main(){
    fin >> n;
    bkt(1);
    return 0;
}