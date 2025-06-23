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
#define M 998244353
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

void solve(){
    int n;
    cin>>n;
    vector<ll> nums(n);
    input(nums);
    vector<ll> dp(n,0);
    if(nums[0]==0)dp[0]++;
    if(n==1){
        show(dp[0]+1);return;
    }
    if(nums[1]==1)dp[1]++;
    if(nums[1]==0){
        dp[1] += dp[0];
    }
    fore(i,2,n){
        if(nums[i]==nums[i-1])dp[i] = dp[i-1];
        if(nums[i]==nums[i-2] + 1)dp[i] += dp[i-2];
        dp[i] = dp[i] % M;
    }
    show((dp[n-1]+dp[n-2])%M);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"