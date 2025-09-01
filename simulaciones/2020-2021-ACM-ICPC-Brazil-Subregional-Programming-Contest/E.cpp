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
#define MAXN 100004
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

vector<int> tr[MAXN];
int age[MAXN];
vector<int> ls,rs;
bool vis[MAXN];
vector<int> parties[MAXN]; //nodo -> fiestas de las que es dueño
vector<int> ancestorParties[MAXN]; //nodo -> fiestas de las que es ancestro
vector<int> res(MAXN,0);
vector<int> aux;

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

void subir(int u){
    aux.pb(u);
    //resolver parties de este nodo
    for(auto p: parties[u]){
        int l = -1, r = SZ(aux);
        while(l+1<r){
            int m = (l+r)/2;
            if(age[aux[m]]>rs[p])l = m;
            else r = m;
        }
        ancestorParties[aux[r]].pb(p);
    }
    for(auto v: tr[u])subir(v);
    aux.pop_back();
}

STree st(MAXN);

void contar(int u){
    for(auto p: ancestorParties[u]){
        st.upd(ls[p],st.query(ls[p],ls[p]+1) + 1);
    }
    res[u] = st.query(0,age[u]+1);
    for(auto v: tr[u])contar(v);
    for(auto p: ancestorParties[u]){
        st.upd(ls[p],st.query(ls[p],ls[p]+1) - 1);
    }
}

int main(){
    FIN;
    int n,m;
    cin>>n>>m;
    fore(i,0,n){
        int a,b;
        cin>>a>>b;--b;
        age[i] = a;
        if(b!=i){
            tr[b].pb(i);
        }
    }
    fore(i,0,m){
        int l,r,o;
        cin>>o>>l>>r;--o;
        ls.pb(l);rs.pb(r);
        parties[o].push_back(i);
    }
    subir(0);
    contar(0);
    fore(i,0,n)cout<<res[i]<<" ";
    cout<<'\n';
    return 0;
}

//Sobrevivimos al pabellon