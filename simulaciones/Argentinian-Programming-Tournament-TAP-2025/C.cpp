#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    FIN;
    int n;
    cin>>n;
    vector<ll> nums(n);
    fore(i,0,n){cin>>nums[i];--nums[i];}
    vector<ll> cnt(n);
    fore(i,0,n)cnt[(nums[i]+i)%n]++;
    ll res = n;
    for(auto p: cnt){
        res += p*(p-1);
    }
    cout<<res<<'\n';
    return 0;
}