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
int n,m,p,p2;

ll dp[1001][101];//foremas de llegar a este puntaje ganando esta cantidad de rondas

ll f(int x, int r){
    if(x<0)return 0;
    if(dp[x][r]!=-1)return dp[x][r];
    if(m*r<x)return 0;
    if(x==0)return r==0;
    if(r==0)return x==0;
    if(r==1)return 1;
    dp[x][r] = 0;
    fore(i,1,m+1){
        dp[x][r] += f(x-i,r-1);
    }
    return dp[x][r];
}

void solve(){
    cin>>n>>m>>p>>p2;
    ll res = 0;
    fore(i,0,1001)fore(j,0,101)dp[i][j] = -1;
    fore(i,0,n+1){
        res += (f(p,i) * f(p2,n-i))%M;
        DGB(p);DGB(i);DGB(f(p,i));DGB(f(p2,n-i));
        res = res%M;
    }
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