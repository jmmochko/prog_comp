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
#define MAXN 10004
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

int k,l,n;

// sumas parciales 
ll dp[MAXN][755];

ll mat[755][755];

ll nums[MAXN];

ll modsub(ll a, ll b){
    ll res = a-b;
    while(res<0)res +=M;
    return res;
}

//sumas parciales sobre formas de avanzar a la pos+1esima tecla estando parado en key
ll f(ll pos, ll key){
    int left=-1,right=k;
    int leftbound, rightbound;
    while(left+1<right){
        int m = (left+right)/2;
        if(mat[key][m]<nums[pos]-l) left = m;
        else right = m;
    }
    //primero que me sirve
    leftbound = right;
    left=-1,right=k;
    while(left+1<right){
        int m = (left+right)/2;
        if(mat[key][m]<=nums[pos]+l) left = m;
        else right = m;
    }
    //primero que no me sirve
    rightbound = right;
    if(pos==n-2) dp[pos][key] = rightbound-leftbound;
    else {
        if(leftbound>k-1 || rightbound==0)dp[pos][key] = 0;
        else if(leftbound<=0)dp[pos][key] = dp[pos+1][rightbound-1];
        else {
            dp[pos][key] = modsub(dp[pos+1][rightbound-1],dp[pos+1][leftbound-1]);
        }
    }
    if(key>0)dp[pos][key] = (dp[pos][key-1] + dp[pos][key])%M;
    return dp[pos][key]%M;
}

void solve(){
    cin>>k>>l;
    fore(i,0,k){
        fore(j,0,k){
            cin>>mat[i][j];
        }
    }
    cin>>n;
    fore(I,0,n-1){
        cin>>nums[I];
    }
    dfore(pos,n-2,0)fore(key,0,k)f(pos,key);
    show(f(0,k-1));
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?
