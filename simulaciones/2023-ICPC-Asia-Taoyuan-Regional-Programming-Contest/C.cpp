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
#define NEUT 0 //Operation 
#define LNEUT 0 //Neutral chosen for lazy op
struct STree { // range sum with range invert
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=LNEUT;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]); // operation
	}
	void push(int k, int s, int e){
		if(lazy[k]%2==LNEUT)return; // if neutral, nothing to do
		st[k]=(e-s)-st[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=(lazy[2*k] + lazy[k])%2;
			lazy[2*k+1]=(lazy[2*k+1] + lazy[k])%2;
		}
		lazy[k]=LNEUT; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]); // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

void solve(){
    ll n,m; cin >> n >> m;
    ll res = 0;
    vector<ll> nums(n), pos(n);
    vector<int> nums_fixed;
    fore(i,0,n){
        ll e;
        cin >> nums[i] >> e;
        res+=e;
        if(nums[i] != -1){
            pos[i] = SZ(nums_fixed);
            nums_fixed.pb(nums[i]);
        } 
        else if(SZ(nums_fixed)){ 
            pos[i] = SZ(nums_fixed)-1;
        }
        else{
            pos[i] = 0;
        }
    }
    int ttree[SZ(nums_fixed)];
    fore(i,0,SZ(nums_fixed)){
        ttree[i] = nums_fixed[i];
    }
    if(SZ(nums_fixed)==0){
        while(m--){
            char aux; cin >> aux;
            if(aux=='W'){int a,b; cin >> a >> b;}
            else {int a; cin>>a;}
        }
        show(res);
        return;
    }
    STree st(SZ(nums_fixed));
    st.init(ttree);
    while(m--){
        char t;
        cin>>t;
        if(t=='W'){
            int l,r;
            cin>>l>>r;
            l = pos[l];
            r = pos[r];
            ++r;
            st.upd(l,r,1);
        }
        else{
            ll e;
            cin>>e;
            res += e*(ll)st.query(0,SZ(nums_fixed));
        }
    }
    show(res);
}

int main(){
    //FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//LEOOOOOOOOOOOOOOOOOOOOO

// 0 1 -1 -1
//l = 0, r = 3
// pos[l] = 0, pos[r] = 1