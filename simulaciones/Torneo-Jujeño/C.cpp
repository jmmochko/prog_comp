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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int estoy = 0, perc = 0;
    bool gane = false;
    fore(i,0,n){
        if(estoy<4){
            if(s[i]=='G')++estoy;
        }
        else if(estoy<8){
            if(s[i]=='G'){++estoy;perc = 0;}
            else ++perc;
            if(perc >= 2){
                estoy = max(estoy-1,4);
            }
        }
        else{
            if(s[i]=='G'){++estoy;}
            else estoy = max(8,estoy-1);
            if(estoy == 12)gane = true;
        }
    }
    if(gane){
        show("CLASIFICADO");
    }
    else{
        if(estoy<4)show(1);
        else if (estoy<8)show(2);
        else show(3);
    }
    return 0;
}

//Sobrevivimos al pabellon