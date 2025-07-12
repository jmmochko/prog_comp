#include <bits/stdc++.h>
#define fore(a,b,c) for(int a = b; a<c; ++a)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second 
#define all(a) a.begin(),a.end()
#define MAXN 300040
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll modsub(ll a, ll b){
    ll res = a-b;
    if(res<0)res+=MOD;
    return res%MOD;
}

ll mul(ll a, ll b){
    return a*b%MOD;
}

ll fpow(ll a, ll b){ // iterativa (mas rapida)
    ll res=1;
    while(b>0){
        if(b%2==1){
            res=(res*a)%MOD;
        }
        a=(a*a)%MOD,b/=2;
    }
    return res;
}
ll fc[MAXN],fci[MAXN];
void factoriales(){
    fc[0]=1;
    fore(i,1,MAXN)fc[i]=mul(fc[i-1],i);
    fci[MAXN-1]=fpow(fc[MAXN-1],MOD-2);
    for(ll i=MAXN-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
}

ll comb(ll n, ll k){
    return mul(fc[n],mul(fci[k],fci[n-k]));
}

int main(){
    FIN;
    int n;
    cin>>n;
    vector<ll> nums(2*n);
    fore(i,0,2*n)cin>>nums[i];
    sort(all(nums));
    fore(i,0,2*n)nums[i] = nums[i]%MOD;
    ll totizq = 0, totder = 0;
    fore(i,0,n){
        totizq += nums[i]; totder += nums[n+i];
        totizq = totizq%MOD;totder = totder%MOD;
    }
    factoriales();
    ll tot = modsub(totder,totizq);
    ll pos = comb(2*n,n)%MOD;
    ll res = mul(pos,tot);
    cout<<res<<'\n';
    return 0;
}