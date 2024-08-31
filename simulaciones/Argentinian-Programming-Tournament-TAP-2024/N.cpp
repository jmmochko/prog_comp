#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define all(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define show(a) cout<<a<<'\n'
#define showAll(a) for(auto b: a)cout<<b<<" ";cout<<'\n'
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<ll> nums(n);
    fore(i,0,n)cin>>nums[i];
    sort(all(nums));
    ll res = 0;
    fore(b,0,n){
        res = max(res,(nums[0]*nums[0] + nums[b]*nums[b] + nums[n-1]*nums[n-1]) - (nums[0]*nums[b] + nums[n-1]*nums[0] + nums[b]*nums[n-1]));
    }
    show(res);
    return 0;
}