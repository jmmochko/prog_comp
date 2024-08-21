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
#define MAXN 2002
#define ALPH 26
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define c96 ((char)96)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

void sanitize(string &s){
    fore(i,0,SZ(s)){
        if(s[i]=='.')s[i]='z'+1;
        if(s[i]==',')s[i]='z'+2;
        if(s[i]=='_')s[i]='z'+3;
    }
}

ll pots[MAXN];

ll fst_pow(ll b, ll e){
    if(e==0)return 1;
    ll aux = fst_pow(b,e/2);
    aux*=aux;
    aux = aux%M;
    if(e&1)aux*=b;
    return aux%M;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    sanitize(s);
    int r,m;
    cin>>r>>m;
    ll acc = 0,inv = fst_pow(37,M-2);
    multiset<ll> ws;
    fore(i,0,m-1){
        acc = (acc + (((s[i]-c96)*pots[i])%M))%M;
    }
    fore(i,m-1,n){
        acc = (acc + (((s[i]-c96)*pots[m-1])%M))%M;
        ws.insert(acc);
        acc -= s[i-(m-1)]-c96;
        if(acc<0)acc+=M;
        acc = (acc*inv)%M;
    }
    ll res = 0;
    while(r--){
        string t;
        cin>>t;
        sanitize(t);
        ll tot = 0;
        fore(i,0,SZ(t)){
            tot = (tot + (((t[i]-c96)*pots[i])%M))%M;
        }
        res += ws.count(tot);
        fore(i,0,SZ(t)){
            ll ctot = tot;
            ctot -= (((t[i]-c96))*pots[i])%M;
            while(ctot<0)ctot+=M;
            for(char l = 'a'; l<='}'; ++l){
                if(l==t[i])continue;
                ll cctot = ctot;
                cctot = (cctot + ((l-c96)*pots[i])%M)%M;
                res += ws.count(cctot);
            }
        }
    }
    show(res);
}

int main(){
    FIN;
    int t = 1;
    pots[0] = 1;
    fore(i,1,MAXN){
        pots[i] = (pots[i-1]*37)%M;
        pots[i] = pots[i]%M;
    }
    //cin>>t;
    while(t--)solve();
    return 0;
}

//ESTOY SOLO YO