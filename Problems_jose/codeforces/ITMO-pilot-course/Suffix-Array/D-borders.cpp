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

#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}

vector<int> constructSA(string& s){ // O(n logn)
	int n=s.size(),rank;
	vector<int> sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0);
		t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	return sa;
}

vector<int> computeLCP(string& s, vector<int>& sa){
	int n=s.size(),L=0;
	vector<int> lcp(n),plcp(n),phi(n);
	phi[sa[0]]=-1;
	fore(i,1,n)phi[sa[i]]=sa[i-1];
	fore(i,0,n){
		if(phi[i]<0){plcp[i]=0;continue;}
		while(s[i+L]==s[phi[i]+L])L++;
		plcp[i]=L;
		L=max(L-1,0);
	}
	fore(i,0,n)lcp[i]=plcp[sa[i]];
	return lcp; // lcp[i]=LCP(sa[i-1],sa[i])
}

#define oper(a,b) a+b
#define NEUT 0 //Operation 
#define LNEUT -1 //Neutral chosen for lazy op
struct STreeSum { // example: range sum with range set
	vector<ll> st,lazy;int n;
	STreeSum(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
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
	void upd(int k, int s, int e, int a, int b, ll v){
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
	void upd(int a, int b, ll v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

#define oper2(a,b) max(a,b)
#define NEUT2 (-MAXINT) //Oper2ation 
#define LNEUT2 -1 //Neut2ral chosen for lazy op
struct STreeMax { // range min with range set
	vector<int> st,lazy;int n;
	STreeMax(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=LNEUT2;  // lazy neut2ral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper2(st[2*k],st[2*k+1]); // oper2ation
	}
	void push(int k, int s, int e){
		if(lazy[k]==LNEUT2)return; // if neut2ral, nothing to do
		st[k]=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=lazy[k];
			lazy[2*k+1]=lazy[k];
		}
		lazy[k]=LNEUT2; // clear node lazy
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
		st[k]=oper2(st[2*k],st[2*k+1]); // oper2ation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // oper2ation neut2ral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper2(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // oper2ation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int fnd(STreeMax &st, int x, int r){//find first pos greater than x
	int l = -1;
	while(l+1<r){
		int m = (r+l)/2;
		if(st.query(0,m+1)<x)l = m;
		else r = m;
	}
	return r;
}

ll solve(string &s){
	ll n = (ll)SZ(s);
    s.pb('$');
    vector<int> sa = constructSA(s);
    vector<int> lcp = computeLCP(s, sa);
	//using lazy st for sum with range set to accumulate previous lcp value.
	//fore(i,1,n+1):
	//	use bsearch on lazy st for max with range set to find first previous pos that is bigger.
	//	set sts from fst to i-1 inclusive to lcp in i
	//	acc sum over al sum st
	STreeSum acc(n+1);
	STreeMax stmax(n+1);
	ll res = 0;
	fore(i,2,n+1){
		if(lcp[i]<lcp[i-1]){
			int bg = fnd(stmax, lcp[i], i);
			acc.upd(bg,i,lcp[i]);
			stmax.upd(bg,i,lcp[i]);
		}
		acc.upd(i,i+1,lcp[i]);
		stmax.upd(i,i+1,lcp[i]);
		res += (ll)acc.query(0,n+1);
	}
	ll gauss;
	if(n%2==0){
		gauss = n/2ll;
		gauss *= n+1ll;
	}
	else{
		gauss = (n+1)/2ll;
		gauss *= n;
	}
	res += gauss;
	return res;
}

ll brute(string &s){
	int n = SZ(s);
	ll res = 0;
	fore(i,0,n)fore(j,i,n){
		//count borders
		res++;//empty string
		fore(k,1,j-i+1){//SZ of border to check
			fore(p,0,k){
				if(s[i+p]!=s[j-k+p+1]){
					--res;
					break;
				}
			}
			++res;
		}
	}
	return res;
}


int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--){
		string s;
		cin>>s;
		show(solve(s));
	}
    return 0;
}

/*
//test vs brute force
int main(){
	FIN;
    int t = 1000000;
    //cin>>t;
    while(t--){
		string s;
		fore(i,0,15){
			s.push_back('a'+(rand()%26));
		}
		ll bforce = brute(s), res = solve(s);
		if(bforce!=res){
			DGB(s);DGB(bforce);DGB(res);RAYA;
		}
		
	}
    return 0;
}
*/
//Cue "Eye of the Tiger"