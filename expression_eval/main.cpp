#include <iostream>
#include <fstream>


using namespace std;

ifstream fin("evaluare.in");
ofstream fout("evaluare.out");

string s;
int ind = 0;
int term(), fact();

int expresie(){
    int sum = term();
    while(s[ind] == '+' || s[ind] == '-'){
        if(s[ind] == '+') ind++, sum += term();
        else ind++, sum -= term();
    }
    return sum;
}

int term(){
    int prod = fact();
    while(s[ind] == '*' || s[ind] == '/'){
        if(s[ind] == '*') ind++, prod *= fact();
        else ind++, prod /= fact();
    }
    return prod;
}

int fact(){
    int sign = 1, val = 0;
    while(s[ind] == '-') ind++, sign = -sign;
    if(s[ind] == '('){
        ind++;
        val = expresie();
        ind++;
        return sign * val;
    }
    while(s[ind] >= '0' && s[ind] <= '9'){
        val = val * 10 + (s[ind] - '0');
        ind++;
    }
    return sign * val;
}

signed main(){
    fin >> s;
    fout << expresie();
    return 0;
}