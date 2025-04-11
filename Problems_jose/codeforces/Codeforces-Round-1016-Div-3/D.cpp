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

ll n;

ll f(ll x, ll y, ll t){
    //saco el quadrante
    if(t==0)return 1;
    
    bool izq=false,arr=false;
    ll medio = (1ll<<(t-1));
    ll total = (1ll<<t*2);
    ll quartodeltotal = total/4;
    if(y<medio)izq=true;
    if(x<medio)arr=true;
    if(izq && arr)return f(x,y,t-1);
    if(!izq && !arr)return quartodeltotal + f(x-medio,y-medio,t-1);
    if(izq && !arr)return 2*quartodeltotal + f(x-medio,y,t-1);
    if(!izq && arr)return 3*quartodeltotal + f(x,y-medio,t-1);
    return -MAXll;
}

pll fr(ll d, ll t){
    ll total = (1ll<<t*2);
    ll medio = (1ll<<(t-1));
    //DGB(d);DGB(t);DGB(total/4);DGB(medio);
    if(t==0)return {0,0};
    if(d<=(total/4))return fr(d,t-1);
    if(d<=(total/2)){
        pll res = fr(d-total/4,t-1);
        return {res.fst + medio, res.snd + medio};
    }
    //show("2");
    if(d<=3*(total/4)){
        pll res = fr(d-total/2,t-1);
        return {res.fst + medio, res.snd};
    }
    //show("3");
    pll res = fr(d-3*(total/4),t-1);
    return {res.fst , res.snd + medio };
}

void solve(){
    ll q;
    cin>>n>>q;
    while(q--){
        char t,v;
        cin>>t>>v;
        if(t=='-'){
            ll x,y;
            cin>>x>>y;
            --x;--y;
            show(f(x,y,n));
        }
        else{
            ll d;
            cin>>d;
            pll res = fr(d,n);
            cout<<res.fst+1<<" "<<res.snd+1<<'\n';
        }
    }
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"