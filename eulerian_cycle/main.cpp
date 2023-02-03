#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("ciclueuler.in");
ofstream fout("ciclueuler.out");

const int NMAX = 1e5;
const int EMAX = 5e5;

vector <int> adj[NMAX + 1];

struct Edge{
    int U;
    int V;
}edges[EMAX + 1];

bool usedEdge[EMAX + 1];

int main(){

    int n, m;
    fin >> n >> m;

    for(int i = 1; i <= m; i++){
        int a, b;
        fin >> a >> b;

        adj[a].push_back(i);
        adj[b].push_back(i);

        edges[i] = {a, b};
    }

    for(int i = 1; i <= n; i++){
        if((int)adj[i].size() % 2 == 1){
            fout << "-1\n";
            return 0;
        }
    }

    stack <int> S;  
    S.push(1);

    vector <int> ans;

    while(!S.empty()){
        int nod = S.top();
        if(!adj[nod].empty()){
            int e = adj[nod].back();
            adj[nod].pop_back();
            if(!usedEdge[e]){
                usedEdge[e] = true;
                int To = edges[e].U ^ edges[e].V ^ nod;
                S.push(To); 
            }
        }else{
            S.pop();
            ans.push_back(nod);
        }
    }

    ans.pop_back();

    for(int nod : ans)
        fout << nod << ' ';
    fout << '\n';

    return 0;
}