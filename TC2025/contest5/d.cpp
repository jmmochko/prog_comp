#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first 
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
#define DGB(a) cout<<#a<<" = "<<a<<'\n';
using namespace std;
typedef long long ll;

const int MAXN = 200005;

void solve(){
    int n;
    cin>>n;
    int nums[n];
    int dp[n+1];
    int best[n+1];
    fore(i,0,n)cin>>nums[i];
    dp[0] = 0;
    fore(i,0,n+1)best[i] = MAXN;
    fore(i,1,n+1){
        dp[i] = min(dp[i-1]+1,best[nums[i-1]]);
        best[nums[i-1]] = min(best[nums[i-1]],dp[i-1]);
    }
    //fore(i,0,n)cout<<dp[i]<<'\n';
    cout<<n-dp[n]<<'\n';
}

int main(){
    FIN;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}