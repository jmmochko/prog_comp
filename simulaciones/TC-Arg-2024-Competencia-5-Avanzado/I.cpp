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

#define oper(a,b) min(a,b)
#define NEUT (1ll<<60)
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

int find(ll a, int l, int r, STree &tree){//finds first element smaller than a in range [l,r) -1 if none
    while(l+1<r){
        int m = (l+r)/2;
        if(tree.query(l,m)<a)r=m;
        else l = m;
    }
    if(tree.query(l,l+1)>=a)return -1;
    return l;
}

void solve(){
    int n;
    cin>>n;
    ll nums[n];
    input(nums);
    fore(i,0,n)nums[i]=nums[i]<<1;
    vector<pll> ord(n);
    fore(i,0,n)ord[i]={-nums[i],i};
    sort(all(ord));
    STree tree(n);
    tree.init(nums);
    vector<int> res(n,0);
    for(auto e: ord){
        int inicio = e.second;
        int nextp = find(nums[inicio]/2,inicio+1,n,tree);
        if(nextp == -1)nextp = find(nums[inicio]/2,0,inicio,tree);
        if(nextp == -1){
            fore(i,0,n)cout<<"-1 ";cout<<'\n';
            return;
        }
        if(nextp>inicio){
            res[inicio] = (nextp-inicio)+res[nextp];
            tree.upd(inicio,-MAXll);
            continue;
        }
        res[inicio] = (n-inicio)+nextp+res[nextp];
        tree.upd(inicio,-MAXll);
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

//Escuchen, corran la bola...