#include <fstream>
#include <vector>

using namespace std;

ifstream fin("hashuri.in");
ofstream fout("hashuri.out");

const int nmax=1000000, mod=999983;

vector <int> r[mod+1];

int main(){
    int n;
    fin>>n;
    for(int in=1;in<=n;in++){
        int x,y;
        fin>>x>>y;
        int a=y%mod;
        int b=r[a].size();
        if(x==1){
            r[a].push_back(y);
        }else if(x==2){
            for(int i=0;i<b;i++){
                if(r[a][i]==y){
                    r[a][i]=r[a][b-1];
                    r[a].pop_back();
                    i=b+2;
                }
            }
        }else{
            int i=0;
            for(i=0;i<b;i++){
                if(r[a][i]==y){
                    fout<<"1\n";
                    i=b+2;
                }
            }
            if(i<=b){
                fout<<"0\n";
            }
        }
    }
    return 0;
}