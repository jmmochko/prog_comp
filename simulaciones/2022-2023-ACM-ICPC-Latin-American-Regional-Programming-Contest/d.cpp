#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst frist
#define snd second
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;

int main(){
    FIN;
    int n,h,w;
    cin>>n>>h>>w;
    fore(i,0,n){
        char a,b;
        cin>>a>>b;
        if((a=='Y') || (w==0)){
            cout<<"Y ";
            ++w;--h;
        }
        else{
            cout<<"N ";
        }
        if((b=='Y') || (h==0)){
            cout<<"Y\n";
            --w;++h;
        }
        else{
            cout<<"N\n";
        }
    }
    return 0;
}