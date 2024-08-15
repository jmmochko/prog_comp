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

ll l,o,s,t,res;

void f(ll a, ll b, ll c, ll d){
    ll m = 1e9;
    if(a)m=min(m,l/a);
    if(b)m=min(m,o/b);
    if(c)m=min(m,s/c);
    if(d)m=min(m,t/d);
    l-= a*m; o-= b*m; s-= c*m; t-= d*m;
    res += m;
}

void solve(){
    cin>>l>>o>>s>>t;
    f(0,4,0,0); // oooo
    f(2,2,0,0); // lloo
    f(0,0,0,4); // tttt
    f(1,0,1,2); // lstt
    f(2,0,2,0); // llss
    f(4,0,0,0); // llll
    show(res);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo