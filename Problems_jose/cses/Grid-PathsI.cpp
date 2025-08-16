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

int main(){
    FIN;
    int n;
    cin>>n;
    char mat[n][n];
    fore(i,0,n)fore(j,0,n)cin>>mat[i][j];
    ll dp[n][n];
    dp[n-1][n-1] = mat[n-1][n-1] == '*'? 0 : 1;
    dfore(i,n-2,0){
        if(mat[i][n-1]=='*')dp[i][n-1] = 0;
        else dp[i][n-1] = dp[i+1][n-1];
    }
    dfore(i,n-2,0){
        if(mat[n-1][i]=='*')dp[n-1][i] = 0;
        else dp[n-1][i] = dp[n-1][i+1];
    }
    dfore(i,n-2,0)dfore(j,n-2,0){
        if(mat[i][j] == '*')dp[i][j] = 0;
        else dp[i][j] = (dp[i+1][j] + dp[i][j+1])%M;
    }
    show(dp[0][0]);
    return 0;
}

//Sobrevivimos al pabellon