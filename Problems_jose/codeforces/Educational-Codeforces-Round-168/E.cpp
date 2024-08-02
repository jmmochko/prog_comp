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
    vector<int> nums(n),dp(n,0);//min k such that monster gets to fight, 0 if it always figths
    input(nums);
    STree tree(MAXN);//auxiliary stree :)
    dp[0] = 0;
    tree.upd(0,1);
    fore(i,1,n){
        DGB(i);
        int l = 1, r = n+1;
        while(l+1<r){
            int m = (l+r)/2;
            DGB(m);
            DGB(1+(tree.query(0,m))/m);
            if(1+tree.query(0,m)/m>nums[i])l=m;
            else r = m;
        }
        RAYA;
        if(r!=n+1){
            dp[i] = r;
            tree.upd(dp[i],tree.query(dp[i],dp[i]+1)+1);
            
        }
        else tree.upd(0,tree.query(0,1)+1);
        DGB(dp[i]);
        DGB(tree.query(dp[i],dp[i]+1));
    }
    showAll(dp);
    while(q--){
        int i,x;
        cin>>i>>x;
        --i;
        if(x>=dp[i])show("YES");
        else show("NO");
    }
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Escuchen, corran la bola...