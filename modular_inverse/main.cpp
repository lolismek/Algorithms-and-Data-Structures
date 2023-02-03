#include <iostream>
#include <fstream>

#define int long long

using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

int a, n;

int lgpow(int base, int pow){
    if(pow == 0) return 1;
    int gratziela;
    pow % 2 == 0 ? gratziela = 1 : gratziela = base;
    int oops = lgpow(base, pow / 2);
    return (((oops * oops) % n) * gratziela) % n;
}

int phi(int n){
    int ans = n;
    for(int div = 2; div * div <= n; div++){
        if(n % div == 0){
            ans = ans * (div - 1) / div;
            while(n % div == 0) n /= div;
        }
    }
    if(n > 1) ans = ans * (n - 1) / n;
    return ans;
}

signed main(){
    fin >> a >> n;
    int phi_val = phi(n) - 1;
    fout << lgpow(a, phi_val);
    return 0;
}