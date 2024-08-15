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

//from https://github.com/mhunicken/icpc-team-notebook-el-vasito

//El Vasito is love, El Vasito is life

#define NEUT 0 //Operation 
#define LNEUT -1 //Neutral chosen for lazy op

int oper(int a, int b){
    if(a==b)return a;
    return a+b;
}

struct STree { // example: range sum with range set
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
		if(lazy[k]==LNEUT)return; // if neutral, nothing to do
		st[k] += lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=lazy[k];
			lazy[2*k+1]=lazy[k];
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
    int q;
    cin>>q;
    STree lz(100001);
    map<int,pii> ids;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int i,v,f;
            cin>>i>>f>>v;
            lz.upd(i,f,v);
            ids[SZ(ids)+1] = {i,f};
        }
        if(t==2){
            int k;
            cin>>k;
            lz.upd(ids[k].first, ids[k].second, -lz.query(ids[k].first, ids[k].second));
        }
        if(t==3){
            int a,b;
            cin>>a>>b;
            show(lz.query(a,b));
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