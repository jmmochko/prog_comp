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
#define MAXll (1<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

typedef ll T; typedef pll L; // T: data type, L: lazy type
// neutrals
constexpr static T tneut = 0; constexpr static L lneut = {0,-1};
T f(T a, T b) {
   return a + b;
} // operation
// new st according to lazy
T apply(T v, L l, ll s, ll e) { return v + l.fst * (e - s); }
// cumulative effect of lazy
L comb(L a, L b) {
    if(a.second==b.second)return a;
    return {a.first + b.first, a.snd};
}

struct Tree { // example: range sum with range addition
	ll n;
	vector<T> st;
	vector<L> lazy;
	Tree(ll n) : n(n), st(4*n, tneut), lazy(4*n, lneut) {}
	Tree(vector<T> &a) : n(SZ(a)), st(4*n), lazy(4*n, lneut) {
		init(1, 0, n, a);
	}
	void init(ll k, ll s, ll e, vector<T> &a) {
		lazy[k] = lneut;
		if (s + 1 == e) { st[k] = a[s]; return; }
		ll m = (s + e) / 2;
		init(2*k, s, m, a), init(2*k+1, m, e, a);
		st[k] = f(st[2*k], st[2*k+1]);
	}
	void push(ll k, ll s, ll e) {
		if (lazy[k] == lneut) return; // if neutral, nothing to do
		st[k] = apply(st[k], lazy[k], s, e);
		if (s + 1 < e) { // propagate to children
			lazy[2*k] = comb(lazy[2*k], lazy[k]);
			lazy[2*k+1] = comb(lazy[2*k+1], lazy[k]);
		}
		lazy[k] = lneut; // clear node lazy
	}
	void upd(ll k, ll s, ll e, ll a, ll b, L v) {
		push(k, s, e);
		if (s >= b || e <= a) return;
		if (s >= a && e <= b) {
			lazy[k] = comb(lazy[k], v); // accumulate lazy
			push(k, s, e);
			return;
		}
		ll m = (s + e) / 2;
		upd(2*k, s, m, a, b, v), upd(2*k+1, m, e, a, b, v);
		st[k] = f(st[2*k], st[2*k+1]);
	}
	T query(ll k, ll s, ll e, ll a, ll b) {
		if (s >= b || e <= a) return tneut;
		push(k, s, e);
		if (s >= a && e <= b) return st[k];
		ll m = (s + e) / 2;
		return f(query(2*k, s, m, a, b),query(2*k+1, m, e, a, b));
	}
	void upd(ll a, ll b, L v) { upd(1, 0, n, a, b, v); }
	T query(ll a, ll b) { return query(1, 0, n, a, b); }
};

//El Vasito is love, El Vasito is life

void solve(){
    ll n; cin >> n;
    Tree st(MAXN);
    vector<pll> posid(MAXN, {-1,-1});
    ll currid = 1;
    fore(i,0,n){
        ll t; cin >> t;
        if(t==1){
            ll a,b,v;
            cin >> a >> b >> v;
            st.upd(a,b,{v,currid});
            // DGB(st.query(a,a+1).first);
            posid[currid] = {a,b};
            currid++;
        }
        if(t==2){
            ll k; cin >> k;
            st.upd(posid[k].fst,posid[k].snd,{0,-1});
        }
        if(t==3){
            ll a,b;
            cin >> a >> b;
            ll aux = st.query(a,b);
            cout << aux << "\n";
        }
    }
}

int main(){
    FIN;
    int t = 1;
    // cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo

// st de pair <val,id> 
