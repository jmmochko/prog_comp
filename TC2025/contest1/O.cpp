#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a = b; a<c; ++a)
#define ALL(a) a.begin(),a.end()
#define INF 10000000000
#define snd second
#define fst first
#define neut {-1,-1}
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;

int primerPotencia(ll x){
    return __lg(x);
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> nums(n);
    fore(i,0,n)cin>>nums[i];
    vector<int> sp(n+1);
    sp[0] = 0;
    fore(i,0,n)sp[i+1] = sp[i]^nums[i];
    int dp[n][31];
    fore(i,0,n)dp[i][30] = -1;
    for(int b = 29; b>=0; --b){
        if(b<=primerPotencia(nums[0]))dp[0][b] = 0;
        else dp[0][b] = -1;
    }
    fore(i,1,n){
        for(int b = 29; b>=0; --b){
            if(b<=primerPotencia(nums[i]))dp[i][b] = i;
            else dp[i][b] = max(dp[i-1][b], dp[i][b+1]);
        }
    }
    while(q--){
        int x;
        cin>>x;
        int estoy = n, next = 0;
        while(next>=0 && x>0 && estoy > 0){
            next = dp[estoy-1][primerPotencia(x)];
            if(next==-1){
                estoy = 0;
                break;
            }
            x ^= sp[estoy] ^ sp[next+1];
            estoy = next+1;
            if(x>=nums[next]){
                x ^= nums[next];
                estoy--;
            }
            else break;
        }
        cout<<n-estoy<<' ';
    }
}

int main(){
    FIN;
    int t;
    cin>>t;
    while(t--){solve();cout<<'\n';}
    return 0;
}