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

vector<ll> lim(ll *nums, ll n, ll k){
    vector<ll> res(n,0);
    fore(i,k-1,n){res[i] = nums[i-k+1];}
    ll acc = 0;
    fore(i,k-1,n){
        res[i] -= acc;
        acc += res[i] - res[i-k+1];
    }
    fore(i,k,n){
        if(i%k != k-1)res[i%k] = max(res[i%k],-res[i]);
    }
    int i = k-1;
    res[k-1] = nums[0];
    while(i<n){
        res[k-1] = min(res[i],res[k-1]);
        i += k;
    }
    return res;
}

int main(){
    FIN;
    ll n,k;
    cin>>n>>k;
    ll nums[n-k+1];
    fore(i,0,n-k+1)cin>>nums[i];
    vector<ll> lims = lim(nums,n,k);
    ll suma = lims[k-1];
    fore(i,0,k-1)suma -= lims[i];
    if(suma<0){
        cout<<"0\n";
        return 0;
    }
    cout<<comb(k + suma - 1,k - 1)<<'\n';
    return 0;
}