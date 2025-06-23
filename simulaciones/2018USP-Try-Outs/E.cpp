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
#define MAXN 32
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

const ll MOD=998244353; 

ll mul(ll a, ll b){
    return a*b%MOD;
}

ll fpow(ll a, ll b){ // iterativa (mas rapida)
    ll res=1;
    while(b>0){
        if(b%2==1){
            res=(res*a)%MOD;
        }
        a=(a*a)%MOD,b/=2;
    }
    return res;
}
ll fc[MAXN],fci[MAXN];
void factoriales(){
    fc[0]=1;
    fore(i,1,MAXN)fc[i]=mul(fc[i-1],i);
    fci[MAXN-1]=fpow(fc[MAXN-1],MOD-2);
    for(ll i=MAXN-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
}

ll comb(ll n, ll k){
    return mul(fc[n],mul(fci[k],fci[n-k]));
}

int main(){
    FIN;
    factoriales();
    ll n;
    cin>>n;
    if(n==1){
        show("0");return 0;
    }
    ll res = 0;
    fore(i,2,n+1)res += comb(n,i);
    show(res);
    return 0;
}

//Cue "Eye of the Tiger"