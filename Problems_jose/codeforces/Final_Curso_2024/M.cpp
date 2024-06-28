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

struct node{
    ll ew,wc,uc;
};

node oper(node a, node b){
    node res;
    ll nc = min(b.uc,a.ew);
    res.ew = (a.ew - nc) + b.ew;
    res.wc = a.wc + nc + b.wc;
    res.uc = a.uc + (b.uc - nc);
    return res;
}

vector<ll> a,b,c;

node NEUT;

//Custom STree for problem
struct STree { // segment tree for oper over nodes
	vector<node> st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void init(ll k, ll s, ll e){
		if(s+1==e){
            if(s>=SZ(a)||s<0)return;
            st[k].ew = max(0ll,a[s]-b[s]);
            st[k].wc = min(a[s],b[s]);
            st[k].uc = max(0ll,b[s]-a[s]);
            return;
        }
		ll m=(s+e)/2;
		init(2*k,s,m);init(2*k+1,m,e);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(ll k, ll s, ll e, ll p){
		if(s+1==e){
            if(s>=SZ(a)||s<0)return;
            st[k].ew = max(0ll,a[s]-b[s]);
            st[k].wc = min(a[s],b[s]);
            st[k].uc = max(0ll,b[s]-a[s]);
            return;
        }
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p);
		else upd(2*k+1,m,e,p);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void init(){init(1,0,n);}
	void upd(ll p){upd(1,0,n,p);}
	ll query(){return st[1].wc;}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

void solve(){
    int n,q;
    ll e;
    cin>>n>>q;
    fore(i,0,n){
        cin>>e;
        a.push_back(e);
    }
    fore(i,0,n){
        cin>>e;
        b.push_back(e);
    }
    fore(i,0,n-1){
        cin>>e;
        c.push_back(e);
    }
    STree tree(n);
    tree.init();
    while(q--){
        int p;
        cin>>p;
        p--;
        cin>>a[p]>>b[p]>>c[p];
        tree.upd(p);
        show(tree.query());
    }
}

int main(){
    FIN;
    int t = 1;
    NEUT.ew=0; NEUT.uc=0; NEUT.wc=0;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.