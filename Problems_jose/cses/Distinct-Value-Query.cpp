#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<"\n";
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 1000001
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
 
#define oper(a,b) a+b
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
    int n,q;
    cin>>n>>q;
    vector<ll> nums(n);
    input(nums);
    vector<pair<pii,int>> qs(q); //<<termina, empieza>,i>
    fore(i,0,q){
        cin>>qs[i].fst.snd>>qs[i].fst.fst;
        qs[i].snd = i;
    }
    sort(all(qs));
    STree tree(n);
    ll to_tree[n];
    fore(i,0,n)to_tree[i] = 1;
    tree.init(to_tree);
    map<int,int> pos; //pos[num] = ultima aparicion
    int res[q];
    int nq = 0; //next query to answer
    //vamos respondiendo
    fore(i,0,n){
        //add nth element
        int e = nums[i];
        if(pos.count(e)){
            tree.upd(pos[e],0ll);
        }
        pos[e] = i;
        //answer queries ending here
        while(nq<q && qs[nq].fst.fst <= i+1){
            res[qs[nq].snd] = tree.query(qs[nq].fst.snd-1,qs[nq].fst.fst);
            ++nq;
        }
    }
    showAll(res);
}
 
int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
 
//El año que viene soy GOD