#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
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
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

ll mod_sub(ll a, ll b){
    ll res = a-b;
    if(res<0)res+=M;
    return res%M;
}

ll mod_pot(ll b, ll e){
    if(e==0||b==1)return 1;
    ll aux = mod_pot(b,e/2);
    if(e&1)return ((aux*aux)%M*b)%M;
    return (aux*aux)%M;
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> nums(n);
    input(nums);
    ll tot = 0;
    fore(i,0,n)tot=(tot+nums[i])%M;
    tot = tot%M;
    ll p = 0;
    fore(i,0,n){
        p += (mod_sub(tot,nums[i])*nums[i])%M;
        p = p%M;
        tot = mod_sub(tot,nums[i]);
    }
    ll q=(n*(n-1))%M, inv2 = mod_pot(2,M-2);
    q = (q*inv2)%M;
    q = mod_pot(q,M-2);
    show((p*q)%M);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//ESTOY SOLO YO