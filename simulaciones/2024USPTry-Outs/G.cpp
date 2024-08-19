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

ll dp[MAXN][MAXN];//min cost to reach the end from i, with a tp at tp

ll f(int i, int tp, vector<ll> &nums){
    if(dp[i][tp]!=0)return dp[i][tp];
    if(i==SZ(nums)-1)return 0;
    dp[i][tp] = min(f(i+1,tp,nums)+abs(nums[i]-nums[i+1]),f(i+1,i,nums)+abs(nums[tp]-nums[i+1]));
    return dp[i][tp];
};

void solve(){
    int n;
    cin>>n;
    vector<ll> nums(n+1);
    nums[0] = 0;
    fore(i,1,n+1){
        cin>>nums[i];
    }
    show(f(1,0,nums)+nums[1]);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo