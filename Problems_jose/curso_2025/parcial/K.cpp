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

int n,k;
ll dp[MAXN][MAXN][2];

ll f(int i, int a, int d){//how many particles (not including self) are generated by a particle with age a hitting the ith wall going right if d
    if(i<0 || i>=n)return 0;
    if(dp[i][a][d]!=-1)return dp[i][a][d];
    if(d){
        dp[i][a][d] = f(i+1,a,d);
        if(a>1)dp[i][a][d] += 1 + f(i-1,a-1,1-d);
    }
    else{
        dp[i][a][d] = f(i-1,a,d);
        if(a>1)dp[i][a][d] += 1 + f(i+1,a-1,1-d);
    }
    dp[i][a][d] = dp[i][a][d] % M;
    return dp[i][a][d];
}

void solve(){
    cin>>n>>k;
    fore(i,0,n)fore(j,0,k+1)fore(d,0,2)dp[i][j][d] = -1;
    show((1 + f(0,k,1))%M);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"