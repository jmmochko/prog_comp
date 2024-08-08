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
#define MAXN 1001
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

int n,y;

double dp[MAXN][MAXN];

double f(int r, int x){
    if(y-r==0)return (double)0;
    if(n-r==1)return y-r==1?(double)1:(double)0;
    if(x==1)return y-r==1?(double)1:(double)0;
    double dx=x,dn=n-r;
    if(dp[r][x]!=(double)-1)return dp[r][x];
    double meVoy = (1.000/dn) * (dx-1.0000)/(dn-1.000) + (1.000/(dn-1.000))*((dx-1.000)/dn);
    double seVaUnoMejor = ((dx-1.000)/dn) * ((dx-2.000)/(dn-1.000));
    double seVaUnoPeor = 1.000-meVoy-seVaUnoMejor;
    if(n-r==y){
        dp[r][x] = meVoy;
    }
    else dp[r][x] = (seVaUnoPeor*f(r+1,x) + seVaUnoMejor*f(r+1,x-1));
    return dp[r][x];
}

void solve(){
    int x;
    cin>>n>>x>>y;
    fore(i,0,n+1)fore(j,0,n+1)dp[i][j]=(double)-1;
    cout<<fixed<<setprecision(4)<<f(0,x)<<'\n';
}

int main(){
    //FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo