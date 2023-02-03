#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

const int N = 2e6;
int kmp[2 * N + 2], ans;
string a, b, s;

void calc_kmp(){
    kmp[1] = 0;
    for(int i = 2; i <= s.size(); i++){
        int l = kmp[i - 1];
        while(l > 0 && s[l + 1] != s[i]) l = kmp[l];
        if(s[l + 1] == s[i]) kmp[i] = l + 1;
    }
}

int main(){
    fin >> a >> b;
    s = "." + a + "$" + b;
    calc_kmp();
    for(int i = 1; i <= s.size(); i++)
        if(kmp[i] == a.size()) ans++;
    fout << ans << '\n';
    ans = min(ans, 1000);
    for(int i = a.size() + 2; i <= s.size() && ans; i++)
        if(kmp[i] == a.size())
            fout << i - (2 * a.size()) - 1 << ' ', ans--;
    return 0;
}