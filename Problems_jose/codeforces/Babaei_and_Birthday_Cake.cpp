//https://codeforces.com/problemset/problem/629/D

#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define sz(a) ((int)a.size())
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
#define fst first
#define snd second
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

long double pi=3.1415926535897932384626433;

//El vasito is love, El vasito is life

#define oper max
#define NEUT 0
struct STree { // segment tree for oper over lls
	vector<ll> st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void init(ll k, ll s, ll e, ll *a){
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
	void init(ll *a){init(1,0,n,a);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

void solve(){
    int n;
    cin>>n;
    ll vol[n],to_tree[n],r,h;
    vector<pll> to_sort(n);
    vector<ll> order(n);
    fore(i,0,n){
        cin>>r>>h;
        vol[i] = r*r*h;
        to_sort[i] = {vol[i],i};
    }
    sort(all(to_sort));
    fore(i,0,n){
        order[to_sort[i].second] = i;
    }
    memset(to_tree,0,n*8);
    STree tree(n);
    tree.init(to_tree);
    fore(i,0,n){
        ll prevm = tree.query(0,order[i]);
        tree.upd(order[i],prevm + vol[i]);
    }
    long double res = ((long double)tree.query(0,n))*pi;
    cout<<setprecision(20)<<res<<'\n';
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

//Escuchen Joy Division