#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((ll)a.size())
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

int main(){
    FIN;
    ll n,k;
    cin>>n>>k;
    map<ll,vector<ll>> occs;
    fore(i,0,n){
        ll e;
        cin>>e;
        occs[e].pb(i);
    }
    ll res = (n*(n-1ll)*(n-2ll))/6ll;
    for (auto e: occs){
        if(SZ(e.second)==1)continue;
        vector<ll> nums = e.second;
        ll suma = 0;
        fore(i,0,SZ(nums))suma += nums[i];
        fore(i,0,SZ(nums)-1){
            suma -= nums[i];
            ll malos = suma - (nums[i] + 1ll)*(SZ(nums)-(i+1ll));
            res -= malos;
        }
    }
    show(res);
    return 0;
}

//Sobrevivimos al pabellon