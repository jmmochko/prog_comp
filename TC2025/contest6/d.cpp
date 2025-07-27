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

int main(){
    FIN;
    pair<string,int> primero = {"",0},segundo = {"",0};
    fore(i,0,4){
        string s; int c; cin>>s>>c;
        if(c>primero.snd)primero = {s,c};
    }
    fore(i,0,4){
        string s; int c; cin>>s>>c;
        if(c>segundo.snd)segundo = {s,c};
    }
    if(primero.snd > segundo.snd){
        cout<<primero.fst<<" beats "<<segundo.fst<<'\n';
    }
    else{
        cout<<segundo.fst<<" beats "<<primero.fst<<'\n';
    }
    return 0;
}