#include <bits/stdc++.h>
#define fore(a,b,c) for(int a = b; a<c; ++a)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second 
#define all(a) a.begin(),a.end()
using namespace std;

int main(){
    FIN;
    string s;
    cin>>s;
    int vert = 0, hor = 2;
    fore(i,0,s.size()){
        if(s[i]=='0'){
            vert = (vert + 2)%4;
            cout<<vert + 1<<" "<<4<<'\n';
        }
        else{
            hor = (hor + 2)%4;
            cout<<1<<" "<<hor + 1<<'\n';
        }
    }
    return 0;
}