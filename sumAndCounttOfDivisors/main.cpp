#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>

#define int long long 

using namespace std;

ifstream fin("ssnd.in");
ofstream fout("ssnd.out");

const int N = 1e6, mod = 9973;
vector <int> prime;
bitset <N + 1> ciur;

void init(){
    for(int i = 2; i * i <= N; i++)   
        if(!ciur[i])
            for(int j = i * i; j <= N; j += i)
                ciur[j] = 1;
    for(int i = 2; i <= N; i++)
        if(!ciur[i]) prime.push_back(i);
}

void solve(){
    int n, nrdiv = 1, sdiv = 1;
    fin >> n;
    for(auto div : prime){
        if(n > 1 && div * div > n) div = n;
        if(n % div == 0){
            int exp = 0, pow = div, tmp = 1;
            while(n % div == 0){
                (tmp += pow) %= mod, (pow *= div) %= mod;
                n /= div, exp++;
            } 
            nrdiv *= (exp + 1);
            (sdiv *= tmp) %= mod;
        }
        if(n == 1) break;
    }
    fout << nrdiv << ' ' << sdiv << '\n';
}

signed main(){
    init();
    int t;
    fin >> t;
    while(t--) solve();
    return 0;
}

/*
    fie descompunerea in factori primi a lui n:
        n = (d1 ^ p1) * (d2 ^ p2) * ... * (dk ^ pk)
    atunci numarul divizorilor va fi:
        nr = (p1 + 1) * (p2 + 1) * ... * (pk + 1)
    iar suma divizorilor va fi:
        S = (d1 ^ p1 + d1 ^ (p1 - 1) + ... + d1 + 1) * (d2 ^ p2 + d2 ^ (p2 - 1) + ... + d2 + 1)
        * ... * (dk ^ pk + dk ^ (pk - 1) + ... + dk + 1)
                                        sau 
        S = (d1 ^ (p1 + 1) - 1) / (d1 - 1) * (d2 ^ (p2 + 1) - 1) / (d2 - 1)
        * ... * (dk ^ (pk + 1) - 1) / (dk - 1)
*/