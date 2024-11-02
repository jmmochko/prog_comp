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
#define MAXN 5005
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

ll modsub(ll a, ll b){
    ll res = a-b;
    if(res<0) res+=M;
    return res;
}

ll dp[MAXN][MAXN]; // amount of ways to put b blocks in a base of sz s

ll f(ll s, ll b){
    if(b<0 || s<=0) return 0;
    if(b == 0) return 1;
    if(s == 1) return 1;
    if(b == 1) return s;
    if(dp[s][b]!=-1)return dp[s][b];
    dp[s][b] = (modsub((f(s,b-s) + (2*f(s-1,b))%M)%M,f(s-2,b)))%M;
    return dp[s][b];
}

void solve(){
    ll s,b;
    cin>>s>>b;
    fore(i,0,MAXN)fore(j,0,MAXN)dp[i][j] = -1;
    show(f(s,b-s));
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?