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

void solve(){
    ll l=1, r = 1000000000;
    while(l+1<r){
        ll m = (l+r)/2;
        cout<<"? "<<m<<" "<<r<<'\n';
        fflush(stdout);
        char res;
        cin>>res;
        if(res=='x')l=m;
        else r=m;
    }
    cout<<"! "<<l<<'\n';
    fflush(stdout);
}

int main(){
    string s;
    do{
        cin>>s;
        if(s[0]=='s')solve();
    }
    while(s[0]=='s');
    return 0;
}

//Escuchen, corran la bola...