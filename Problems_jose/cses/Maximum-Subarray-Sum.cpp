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
 
vector<int> bds;
 
void solve(){
    int n;
    cin>>n;
    vector<ll> nums(n), psums(n+1);
    input(nums);
    psums[0] = 0;
    fore(i,1,n+1){
        psums[i] = psums[i-1] + nums[i-1];
    }
    ll res = nums[0], prevmin = 0;
    fore(i,1,n+1){
        res = max(res,psums[i]-prevmin);
        prevmin = min(prevmin, psums[i]);
    }
    show(res);
}
 
int main(){
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}