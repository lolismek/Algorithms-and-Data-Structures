#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;
const int MAX = 2000000;
bitset<MAX>ciur;

int main()
{
    int n, i, j, total;
    ifstream fin;
    fin.open("ciur.in");
    fin >> n;
    fin.close();

    ciur[0] = ciur[1] = 1;
    for(i = 2; i * i <= n; i++)
    {
        if(ciur[i] == 0)
        {
            for(j = i * i; j <= n; j+=i)
            {
                ciur[j] = 1;
            }
        }
    }

    total = 0;
    for(i = 0; i <= n; i++)
    {
        if(ciur[i] == 0)
        {
            total++;
        }
    }

    ofstream fout;
    fout.open("ciur.out");
    fout << total;
    fout.close();
    return 0;
}