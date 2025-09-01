#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
#define oper(a,b) (a + b)
#define NEUT 0
using namespace std;
typedef long long ll;

struct STree {
    vector<ll> t; ll n;
    STree(ll n): n(n), t(2*n+5, NEUT){}
    void upd(ll p, ll v){
        p += n;
        for(t[p]=v;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
    }
    ll query(ll l, ll r){
        ll res = NEUT;
        for(l+=n,r+=n; l<r; l>>=1, r>>=1){
            if(l&1) res = oper(res,t[l++]);
            if(r&1) res = oper(res,t[--r]);
        }
        return res;
    }
};


const ll MAXN = 1e5 + 5;
const ll MAXM = 505;

ll dp[MAXN][MAXM];

ll n,g;

ll f(ll i, ll b, STree &st){
    if(i>n) return -1e12;
    if(b>450) return 0;
    if(i==n) return 0;
    if(dp[i][b] != -1) return dp[i][b];

    dp[i][b] = 0;
    if(i+b <= n){
        dp[i][b] = max(g - st.query(i, i+b) + f(i+b, b+1, st), f(i+1,b, st));
    } else{
        return dp[i][b];
    }
    return dp[i][b];
}


int main(){
    FIN;
    fore(i,0,MAXN) fore(j,0,MAXM) dp[i][j] = -1;
    cin >> n >> g;
    STree st(n);
    fore(i,0,n){
        ll aux; cin >> aux;
        st.upd(i,aux);
    }
    cout << max(0LL,f(0,1,st)) << "\n";

    return 0;
}