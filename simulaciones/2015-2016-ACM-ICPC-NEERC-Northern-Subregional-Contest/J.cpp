#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll n,t;


#define oper min
#define NEUT LONG_LONG_MAX
struct STree { // segment tree for min over integers
	vector<ll> st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void init(ll k, ll s, ll e, vector<ll> &a){
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(vector<ll> &a){init(1,0,n,a);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

bool can(vector<ll> &re, ll range){
    // arrancamos de atras hacia adelante
    STree st(n);
    st.upd(n-1,n-1); // start position
    for(ll i=n-2; i>=0 ;--i){
        ll res = st.query(i + 1, min(n, i + range + 1)) - i; // obtenemos la posicion minima
        if(i>0) st.upd(i,res+re[i]+i); // actualizamos la posicion, sumandole el valor de reentrada
        else st.upd(0,res); // caso final
    }

    return st.query(0,1)<=t;
}
 

int main(){
    FIN;
    ifstream cin("journey.in");
    ofstream cout("journey.out");
    cin >> n >> t;

    vector<ll> c(n-1);
    vector<ll> re;

    re.pb(0);

    fore(i,0,n-1) cin >> c[i];

    fore(i,0,n-2){
        ll aux; cin >> aux; re.pb(aux);
    }

    re.pb(0);

    ll l = 0, r = n;
    while(l <= r){
        ll m = (l+r)/2;
        if(can(re,m)) r = m-1;
        else l = m+1;
    }
 
    ll res = c[n-2];
    fore(i,l-1,n-1) res = min(c[i], res);
    // cout << l << "\n";
 
    cout << res << "\n";

    cin.close();
    cout.close();
}
