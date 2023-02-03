#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream fin("deque.in");
ofstream fout("deque.out");

const int N = 5000001;
int v[N];
deque <int> D;

int main()
{
    long long n, k, i, ultim, sum = 0, val;
    fin >> n >> k;
    for(i = 1; i <= n; i++) fin >> v[i];

    for(i = 1; i <= n; i++){ ///indicile va fi ultimul element din fereastra
        while(!D.empty() && v[i] <= v[D.back()])
            D.pop_back();
        D.push_back(i);
        if(D.front() == i - k)
            D.pop_front();
        if(i >= k)
            sum += v[D.front()];
    }
    fout << sum;
    return 0;
}