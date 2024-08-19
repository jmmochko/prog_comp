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

ll fastpow(ll b, ll e){
    if(e==0)return 1;
    ll aux = fastpow(b,e/2);
    if(e%2!=0)return (((aux*aux)%M)*e)%M;
    return (aux*aux)%M;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> cnt(n);
    cin>>cnt[0];
    fore(i,1,n){
        cin>>cnt[i];
        cnt[i]+=cnt[i-1];
    }
    ll fact[n+1];
    fact[0] = 1;
    fore(i,1,n+1){
        fact[i] = (fact[i-1]*i)%M;
    }
    ll res,zeros,ones;
    fore(i,k-1,n){
        ones = cnt[i];
        zeros = i-ones+1;
        if(k+1/2>ones)continue;
        fore(a,k+1/2,ones+1){
            if(zeros<k-a)continue;
            ll choose1 = (((fact[ones]*fastpow(ones-a,M-2))%M)*fastpow(a,M-2))%M;
            ll choose0 = (((fact[zeros]*fastpow(k-a,M-2))%M)*fastpow(zeros-(k-a),M-2))%M;
            res += (choose0*choose1)%M;
            res = res%M;
        }
    }
    show(res);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo