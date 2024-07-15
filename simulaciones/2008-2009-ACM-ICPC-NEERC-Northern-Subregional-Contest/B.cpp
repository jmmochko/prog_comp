#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(ll a=b; a<c; ++a)
#define dfore(a,b,c) for(ll a=b; a>=c; --a)
#define SZ(a) ((ll)a.size())
#define fst first
#define snd second
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define MAXN 200005ll
#define ALPH 26
#define M 1000000007
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

#define oper min
#define NEUT 1000000001
struct STree { // segment tree for min over llegers
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
	ll find(ll k, ll s, ll e, ll v){
        if(s+1>=e){
            if(st[k]<=v)return s;
            return -1;
        }
        ll m = (s+e)/2;
		if(st[2*k]<=v){
            return find(2*k, s, m, v);
        }
        else{
            return find(2*k+1, m, e, v);
        }
	}
    ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll find(ll v){return find(1,0,n,v);}
    ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int main(){
    FIN;
    ifstream cin("billboard.in");
    ofstream cout("billboard.out");
    ll t = 1;
    //cin>>t;
    while(t--){
        ll h,w,n;
        ll e,cur=0;
        cin>>h>>w>>n;
        h = min(MAXN,h);
        ll to_tree[h];
        fore(i,0,h){
            to_tree[i] = 0;
        }
        STree tree(h);
        tree.init(to_tree);
        fore(i,0,n){
            cin>>e;
            ll res = tree.find(w-e);
            if(res == -1){
                show(-1);
                continue;
            }
            tree.upd(res,tree.query(res,res+1)+e);
            show(res+1);
        }
    }
    cin.close();
    cout.close();
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.