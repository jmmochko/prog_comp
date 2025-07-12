#include <bits/stdc++.h>
#define fore(a,b,c) for(int a = b; a<c; ++a)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second 
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;

int main(){
    FIN;
    int n;
    cin>>n;
    vector<ll> nums(n);
    fore(i,0,n)cin>>nums[i];
    ll res = 0, llevo = 1e10;
    for(int i = n-1; i>=0; --i){
        --llevo;
        llevo = min(llevo,nums[i]);
        llevo = max(llevo, 0ll);
        res += llevo;
    }
    cout<<res<<'\n';
    return 0;
}