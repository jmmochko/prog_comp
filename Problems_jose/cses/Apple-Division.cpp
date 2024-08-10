#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c;++a)
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
#define fst first
#define snd second
#define PI 3.141592653
#define yesif(a) cout << (a ? "YES\n" : "NO\n")
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
 
vector<ll> nums;
ll total = 0;
ll res = (1ll<<61);
 
void dif(ll n, ll c, ll l, ll r){//amount left to choose, carry
    if(l==r){
        res = min(res,abs((total - c) - (total-(total - c))));
        return;
    }
    if(n==0){
        res = min(res,abs((total - c) - (total-(total - c))));
        return;
    }
    fore(i,l,r){
        dif(n-1,c+nums[i],i+1,r);
    }
    return;
}
 
void solve(){
    int n;
    cin>>n;
    ll e;
    total = 0;
    fore(i,0,n){
        cin>>e;
        nums.push_back(e);
        total += e;
    }
    fore(i,0,n/2 + 1){
        dif(i,0,0,n);
    }
    show(res);
}
 
int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}