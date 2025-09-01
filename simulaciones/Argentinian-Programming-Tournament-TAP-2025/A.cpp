#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;
typedef long long ll;

string eso = "TAP?";

int main(){
    FIN;
    string s;
    cin>>s;
    int i = 0;
    fore(j,0,SZ(s)){
        if(s[j]==eso[i])++i;
    }
    if(i==3){
        cout<<"S\n";
    }
    else cout<<"N\n";
    return 0;
}