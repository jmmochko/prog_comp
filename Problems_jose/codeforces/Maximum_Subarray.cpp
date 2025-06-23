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
#define MAXK 21
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

ll n,k,x;
ll nums[MAXN];
ll dp[MAXN][MAXK][3];//mejor solucion en i habiendo usado exactamente c cosos

ll f(int i, int c, int t){
    if(i<0 || c>k || t<0)return -MAXll;
    if(dp[i][c][t]!=-MAXll)return dp[i][c][t];
    if(i==0){
        if(k-c > 1)return -MAXll;
        if(t==1){
            if(k-c == 1)return nums[0] + x,0ll;
            return nums[0] - x;
        }
        if(k-c == 1)return max(nums[0] + x,0ll);
        return max(nums[0] - x,0ll);
    }
    if(t==0){
        if(k-c-1 > i)return -MAXll;
        return 0;
    }
    if(t==1){
        dp[i][c][t] = max({f(i-1,c+1,t) + x, f(i-1,c+1,t-1) + x, f(i-1,c,t) - x, f(i-1,c,t-1) - x}) + nums[i];
    }
    else dp[i][c][t] = max({f(i-1,c+1,t),f(i-1,c+1,t-1),f(i-1,c,t),f(i-1,c,t-1)});
    return dp[i][c][t];
}

void solve(){
    cin>>n>>k>>x;
    fore(i,0,n)fore(c,0,k+1)fore(t,0,3)dp[i][c][t] = -MAXll;
    fore(i,0,n)cin>>nums[i];
    ll res = 0;
    res = max(res,f(n-1,0,1));
    res = max(res,f(n-1,0,2));
    show(res);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"