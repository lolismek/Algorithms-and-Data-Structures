#include <iostream>
#include <fstream>
#include <vector>

#define int long long

using namespace std;

ifstream fin("aib.in");
ofstream fout("aib.out");

const int N = 1e5 + 1, LOGN = 17;
vector <int> aib(N);
int logn = 1, n;

int lsb(int x){
    return (x & (-x));
}

void update(int poz, int val){
    for(int i = poz; i < aib.size(); i += lsb(i)) aib[i] += val;
}

int query(int poz){
    int ans = 0;
    for(int i = poz; i > 0; i -= lsb(i)) ans += aib[i];
    return ans;
}

int cb2(int x){
    int ans = 0, sum = 0;
    for(int pas = (1 << LOGN); pas > 0; pas >>= 1){
        if(ans + pas <= n && sum + aib[ans + pas] <= x){
            //cout << ans << " " << pas << endl;
            ans += pas;
            sum += aib[ans];
        }
    }
    if(sum != x || ans == 0) return -1;
    return ans;
}

signed main()
{
    int q;
    fin >> n >> q;
    while(logn < n) logn <<= 1;
    for(int i = 1; i <= n; i++){
        int x;
        fin >> x;
        update(i, x);
    }
    while(q--){
        int cerinta;
        fin >> cerinta;
        if(cerinta == 0){
            int a, b;
            fin >> a >> b;
            update(a, b);
        }else if(cerinta == 1){
            int a, b;
            fin >> a >> b;
            fout << query(b) - query(a - 1) << '\n';
        }else{
            int x;
            fin >> x;
            //cout << "----------------------------------------------------" << endl;

            fout << cb2(x) << '\n';
        }
    }
    return 0;
}