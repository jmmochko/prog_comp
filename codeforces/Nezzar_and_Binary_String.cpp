//https://codeforces.com/problemset/problem/1477/B

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

//El vasito is love, El vasito is life

string f;

#define oper(a,b) a+b
#define NEUT 0 //Operation 
#define LNEUT -1 //Neutral chosen for lazy op
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
		st[k]=(e-s)*lazy[k]; // update st according to lazy
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
    int n,q,l,r,d;
    ll p;
    bool res = true;
    cin>>n>>q;
    string s;
    cin>>s;
    cin>>f;
    int to_tree[n];
    fore(i,0,n){
        to_tree[i] = f[i] - '0';
    }
    STree tree(n);
    tree.init(to_tree);
    vector<pii> qs(q);
    fore(i,0,q){
        cin>>qs[i].first>>qs[i].second;
        --qs[i].first;
    }
    dfore(i,q-1,0){
        l = qs[i].first; r = qs[i].second;
        p = tree.query(l,r);
        d = r-l;
        if(p==d-p){
            show("NO");
            return;
        }
        if(p>d/2){
            tree.upd(l,r,1);
        }
        else{
            tree.upd(l,r,0);
        }
    }
    fore(i,0,n){
        if(s[i]!=(char)(tree.query(i,i+1)+'0')){
            show("NO");
            return;
        }
    }
    show("YES");
    return;
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

//Escuchen Joy Division