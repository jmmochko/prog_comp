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
    vector<ll> nums(n),sp(n+1,0);
    fore(i,0,n)cin>>nums[i];
    ll tot = 0;
    fore(i,0,n){
        tot += nums[i]*(i+1);
    }
    //reverse(all(nums));
    fore(i,0,n)sp[i+1] = sp[i] + nums[i];
    //pruebo moverme a la der
    ll res = tot;

    return 0;
}