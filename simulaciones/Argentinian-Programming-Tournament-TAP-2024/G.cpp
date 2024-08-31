#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
using namespace std;

int main(){
    FIN;
    string st;
    cin >> st;
    int t=0,au=0,p=0;
    for(auto c : st){
        if(c=='T') t++;
        else if(c=='A' || c=='U') au++;
        else if(c=='P') p++;

    }
    int res = min({t,au,p});
    cout << res << "\n";

}