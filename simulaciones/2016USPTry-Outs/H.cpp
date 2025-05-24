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
#define M 1000000021
#define M2 1000000009
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

ll mbit(vector<ll> &nums, int k){
    ll res = 1;
    fore(i,0,SZ(nums)){
        if((k&(1<<i))!=0){
            res = res*nums[i];
            res = res % M;
        }
    }
    return res%M;
}

ll mbit2(vector<ll> &nums, int k){
    ll res = 1;
    fore(i,0,SZ(nums)){
        if((k&(1<<i))!=0){
            res = res*nums[i];
            res = res % M2;
        }
    }
    return res%M2;
}

bool isP(ll k){
    ll i = 3;
    while(i*i<=k){
        if(k%i==0)return false;++i;
    }
    return true;
}

void solve(vector<ll> &a, vector<ll> &b){
    int n=SZ(a),m=SZ(b);
    set<pll> mula, mulb;
    map<ll,ll> masca,mascb;
    fore(i,1,(1<<SZ(a))){
        ll ai = mbit(a,i);
        mula.insert({ai,mbit2(a,i)});
        masca[ai] = i;
    }
    fore(i,1,(1<<SZ(b))){
        ll bi = mbit(b,i);
        mulb.insert({bi,mbit2(b,i)});
        mascb[bi] = i;
    }
    for(auto jaja: mula){
        if(mulb.count(jaja)>0){
            ll e = jaja.fst;
            show("Y");
            vector<ll> resa,resb;
            ll ma = masca[e];
            ll mb = mascb[e];
            fore(i,0,SZ(a)){
                if(ma&(1<<i))resa.pb(a[i]);
            }
            fore(i,0,SZ(b)){
                if(mb&(1<<i))resb.pb(b[i]);
            }
            cout<<SZ(resa)<<" "<<SZ(resb)<<'\n';
            showAll(resa);
            showAll(resb);
            return;
        }
    }
    show("N");
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    int n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    input(a);
    input(b);
    while(t--)solve(a,b);
    return 0;
}

//Cue "Eye of the Tiger"