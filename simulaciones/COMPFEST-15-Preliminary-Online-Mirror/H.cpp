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
#define M 998244353
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

ll add(ll a, ll b){return (a+b)%M;}
ll sub(ll a, ll b){
    a -= b;
    while(a<0)a += M;
    return a%M;
}
ll mul(ll a, ll b){return (a*b)%M;}
ll fpow(ll b, ll e){
    if(e==0)return 1;
    ll m = fpow(b,e/2);
    m = mul(m,m);
    if(e&1)m = mul(m,b);
    return m;
}
ll dv(ll a, ll b){
    ll inv = fpow(b,M-2);
    return mul(a,inv);
}

ll n,k;
ll fact[2*MAXN+1];

ll moi(ll vacios){//cnt con mayor o igual cantidad de vacios
    if(vacios>n)return 0;
    ll antes = min(n-vacios+1,k+1), iguales = k-(n-vacios);
    //DGB(vacios);DGB(antes);DGB(iguales);RAYA;
    if(iguales<0)return fact[antes];
    return mul(fact[antes],fpow(antes,iguales));
}

int main(){
    FIN;
    cin>>n>>k;
    fact[0] = 1;
    fore(i,1,2*MAXN+1){fact[i] = mul(fact[i-1],i);}
    ll res = 1;
    fore(vacios,0,n){
        ll sinorden = sub(moi(vacios),moi(vacios+1));
        ll ordenes = dv(fact[n],fact[vacios]);
        res = add(res,mul(sinorden,ordenes));
        //DGB(vacios);DGB(sinorden);DGB(ordenes);DGB(moi(vacios));DGB(moi(vacios+1));DGB(res);RAYA;
    }
    cout<<res<<'\n';
    return 0;
}

//Returneamos al pabellón