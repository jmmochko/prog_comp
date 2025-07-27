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

vector<ll> primes = {2,3,5,7};
vector<ll> cmb = {2*3, 2*5, 2*7, 3*5, 3*7, 5*7};
vector<ll> cmb2 = {2*3*5, 2*5*7, 2*3*7, 3*5*7};

//cuantos n con primos en la fact hay entre 0 y n;

ll malN(ll n){
    ll res = 0;
    for(ll p: primes){
        res += n/p;
    }
    for(ll c: cmb){
        res -= n/c;
    }
    for(ll c: cmb2){
        res += n/c;
    }
    return res - n/(2*3*5*7);
}

void solve(){
    ll l,r;
    cin>>l>>r;
    ll complemento = malN(r) - malN(l-1);
    show(r - l - complemento + 1);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Sobrevivimos al pabellon