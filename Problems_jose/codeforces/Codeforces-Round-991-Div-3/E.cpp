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

string a,b,c;

int dp[MAXN][MAXN];

int f(int i, int j){
    if(dp[i][j]<MAXINT)return dp[i][j];
    if(i==0 && j==0)return 0;
    int pos = i+j-1;
    if(i>0){
        int res = f(i-1,j);
        if(c[pos]!=a[i-1])++res;
        dp[i][j] = min(dp[i][j],res);
    }
    if(j>0){
        int res = f(i,j-1);
        if(c[pos]!=b[j-1])++res;
        dp[i][j] = min(dp[i][j],res);
    }
    return dp[i][j];
}

void solve(){
    cin>>a>>b>>c;
    fore(i,0,SZ(a)+1)fore(j,0,SZ(b)+1)dp[i][j] = MAXINT;
    show(f(SZ(a),SZ(b)));
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//El año que viene soy GOD