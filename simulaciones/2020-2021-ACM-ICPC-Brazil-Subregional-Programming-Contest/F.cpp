#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 200005
#define ALPH 26
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

int main(){
    FIN;
    string s;
    cin>>s;
    int gl=0,gr=0,pl=0,pr=0,wn = -1;
    bool server = true;
    fore(i,0,SZ(s)){
        if(s[i] == 'Q'){
            if(wn == -1){
                if(server){
                    cout<<gl<<" ("<<pl<<") - "<<gr<<" ("<<pr<<"*)\n";
                }
                else{
                    cout<<gl<<" ("<<pl<<"*) - "<<gr<<" ("<<pr<<")\n";
                }
            }
            else{
                if(wn == 0){
                    cout<<gl<<" (winner) - "<<gr<<'\n';
                }
                else{
                    cout<<gl<<" - "<<gr<<" (winner)"<<'\n';
                }
            }
        }
        if(s[i] == 'R' && wn==-1){
            ++pl;
        }
        if(s[i] == 'S' && wn == -1){
            ++pr;
        }
        if((pl-2>=pr && pl>=5) || pl==10){
            pl = 0, pr = 0;
            ++gl;
            server = false;
        }
        if((pr-2>=pl && pr>=5) || pr==10){
            pr = 0, pl = 0;
            ++gr;
            server = true;
        }
        if(gl == 2)wn = 0;
        if(gr == 2)wn = 1;
        //DGB(pl);DGB(pr);RAYA;
    }
    return 0;
}

//Sobrevivimos al pabellon