#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(ll a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
using namespace std;
typedef long long ll;

const ll M = 998244353;

ll add(ll a, ll b){
    return (a+b)%M;
}

ll sub(ll a, ll b){
    ll res = a-b;
    while(res<0)res += M;
    return res%M;
}

ll mul(ll a, ll b){
    return (a*b)%M;
}

ll fpow(ll e, ll b){
    if(e==0)return 1;
    ll eso = fpow(e/2,b);
    eso = mul(eso,eso);
    if(e&1)return mul(eso,b);
    return eso;
}

ll dv(ll a, ll b){
    return mul(a,fpow(M-2,b));
}

ll fact(ll s, ll n){
    ll res = 1;
    fore(i,s,n+1){
        res = mul(res,i);
    }
    return res;
}

//en O(k)
ll comb(ll n, ll k){
    return dv(fact(n-k+1,n),fact(1,k));
}

int main(){
    //FIN;
    ll n,k;
    cin>>n>>k;
    vector<ll> nums(n-k+1);
    fore(i,0,n-k+1)cin>>nums[i];
    ll mn = nums[0];
    fore(i,1,n-k+1){
        mn = min(nums[i],mn);
    }
    DGB(mn);
    DGB(sub(add(k,mn),1));DGB(sub(mn,1));DGB(comb(4,2));DGB(dv(9,3));
    cout<<comb(sub(add(k,mn),1),sub(mn,1))<<'\n';
    return 0;
}