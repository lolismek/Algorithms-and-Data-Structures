#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;
ifstream fin("combinari.in"); ofstream fout("combinari.out");

const int N = 18;
int v[N + 1], n, k;

void afisare(){
    for(int i = 1; i <= k; i++) fout << v[i] << ' ';
    fout << '\n';
}

void bkt(int poz){
    if(poz == k + 1){ afisare(); return; }
    for(int i = v[poz - 1] + 1; i <= n; i++) v[poz] = i, bkt(poz + 1);
}

int main(){
    fin >> n >> k, bkt(1);
    return 0;
}