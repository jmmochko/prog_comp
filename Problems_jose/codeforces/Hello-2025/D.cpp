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

struct T{
    ll max_left,max_right,min_left,min_right,val;
    T(ll val, ll l, ll r): max_left(l),max_right(r),min_left(l),min_right(r),val(0){}
    T(): max_left(-MAXll),max_right(-MAXll),min_left(MAXll),min_right(MAXll),val(0){}
};

T oper(T l, T r){
    T res;
    res.max_left = max(l.max_left, r.max_left);
    res.min_left = min(l.min_left, r.min_left);
    res.max_right = max(r.max_right, l.max_right);
    res.min_right = min(r.min_right, l.min_right);
    res.val = max(l.val,r.val);
    res.val = max(res.val,max(l.max_left - r.min_left, r.max_right - l.min_right));
    return res;
}

T NEUT;

struct STree { // segment tree for oper over lls
	vector<T> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, T *a){
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, T v){
		if(s+1==e){st[k]=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	T query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(T *a){init(1,0,n,a);}
	void upd(int p, T v){upd(1,0,n,p,v);}
	T query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

void solve(){
    int n,q;
    cin>>n>>q;
    T nums[n];
    fore(i,0,n){
        ll e;
        cin>>e;
        T k(e, e + i - n + 1, e-i);
        nums[i] = k;
    }
    STree st(n);
    st.init(nums);
    show(st.query(0,n).val);
    while(q--){
        int p;
        ll x;
        cin>>p>>x;
        --p;
        T nw(x, x + p - n + 1, x-p);
        st.upd(p,nw);
        show(st.query(0,n).val);
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