#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

#define int long long

using namespace std;

ifstream fin("pinex.in");
ofstream fout("pinex.out");

const int SQRT = 1e6, centura_de_siguranta = 5;
bitset <SQRT + centura_de_siguranta> ciur;
vector <int> prime;

void find_prime(){
    for(int i = 2; i * i <= SQRT; i++)
        if(!ciur[i])
            for(int j = i * i; j <= SQRT; j += i)
                ciur[j] = 1;
    for(int i = 2; i <= SQRT; i++) 
        if(!ciur[i])
            prime.push_back(i);
}

void decomp(int n, vector <int> &fact){
    for(int i = 0; i < (int)prime.size() && prime[i] * prime[i] <= n; i++){
        if(n % prime[i] == 0){
            fact.push_back(prime[i]);
            while(n % prime[i] == 0) n /= prime[i];
        }
    }
    if(n != 1) fact.push_back(n);
}

int pop_count(int mask){
    int ans = 0;
    while(mask) ans += (mask & 1), mask >>= 1;
    return ans;
}

void solve(){
    vector <int> fact;
    int a, b;
    fin >> a >> b;
    decomp(b, fact);

    int ans = 0;
    for(int mask = 0; mask < (1 << (int)fact.size()); mask++){
        int prod = 1, i = 0, msk = mask;
        while(msk){
            if(msk & 1)
                prod *= fact[i];
            msk >>= 1, i++;
        }
        pop_count(mask) % 2 == 0 ? ans += (a / prod) : ans -= (a / prod);
    }
    fout << ans << '\n';
}

signed main(){
    find_prime();
    int t;
    fin >> t;
    while(t--) solve();
    return 0;
}

/*
    Aplicatie: Cate numere coprime cu b si mai mici sau egale cu a exista?
        
        b = d1 ^ p1 * d2 ^ p2 * ... * dk ^ pk, atunci fie Ai multimea multiplilot lui di mai mici sau egali cu a.
    
        Astfel, rezultatul cerut este a - | U Ai | => calculabil cu PINEX 
                                        (adunam pe aia cu numar pari, scadem pe aia cu numar impar)
    
        In plus, | Ai | = [a / di] si | Ai n Aj n ... | = a / (di * dj * ...) (*)
            * | Ai n Aj | = [a / cmmmc(di, dj)], dar cmmdc(di, dj) = 1 

*/