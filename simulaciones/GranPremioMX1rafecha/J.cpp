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

int dp[500][500][501];

string a;

int f(int l, int r, int k){
    //DGB(l);DGB(r);DGB(k);RAYA;
    if(dp[l][r][k] != -1)return dp[l][r][k];
    if(k==0)return 0;
    if((r-l)+1<k || k<0 || l>r)return MAXINT;
    if(k==0||k==1)return 0;
    if(a[l]==a[r]){
        if(k==2)dp[l][r][k] = 0;
        else dp[l][r][k] = min(f(l+1,r-1,k-2),min(f(l+1,r,k),f(l,r-1,k)));
        return dp[l][r][k];
    }
    dp[l][r][k] = min(1 + f(l+1,r-1,k-2),min(f(l+1,r,k),f(l,r-1,k)));
    return dp[l][r][k];
}

int main(){
    FIN;
    int n,p;
    cin>>n>>p;
    cin>>a;
    fore(i,0,n)fore(j,0,n)fore(k,0,p+1)dp[i][j][k] = -1;
    show(f(0,n-1,p));
    return 0;
}

//Cue "Eye of the Tiger"

// f(l,r,k)