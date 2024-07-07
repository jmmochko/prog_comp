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
#define fact2(a) __builtin_ctz(a)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

ll solve(int a){
    ll res = 1;
    while(a%2==0){
        a/=2;
        res*=2;
    }
    while(a%3==0){
        a/=3;
        res*=3;
    }
    return res;
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int res = 0;
        vector<ll> r;
        while(n>0){
            r.push_back(solve(n));
            n -= r[SZ(r)-1];
            DGB(n);
        }
        show(SZ(r));
        showAll(r);
    }
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.