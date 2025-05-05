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
#define MAXN 1000000
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

string bueno,texto;

int dp[MAXN][100];

int n,m,k;

int f(int i, int j){
    if(j>=m)return 0;
    if(i>=n)return m - j;
    if(dp[i][j]!=-1)return dp[i][j];
    if(bueno[j] == texto[i])dp[i][j] = f(i+1,j+1);
    else{
        dp[i][j] = min({f(i,j+1),f(i+1,j),f(i+1,j+1)}) + 1;
    }
    return dp[i][j];
}

int main(){
    FIN;
    cin>>m>>n>>k;
    cin>>bueno>>texto;
    fore(i,0,n)memset(dp[i],-1,sizeof(int)*m);
    int res = MAXINT;
    fore(i,0,n){
        res = min(res,f(i,0));
    }
    if(res<=k){
        show("S");
    }
    else show("N");
    return 0;
}

//Cue "Eye of the Tiger"