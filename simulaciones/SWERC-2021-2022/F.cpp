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

struct Tree {
	typedef pll T;
	static constexpr T unit = {-MAXll,-MAXll};
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    --a;--b;
    vector<int> p(n);
    input(p);
	Tree stmx(n), stmn(n);//stmn todo con -
    fore(i,0,n){
        stmx.update(i,{i+p[i],i});
		stmn.update(i,{-(i-p[i]),i});
    }
    queue<pii> q;
    q.push({a,0});
    while(!q.empty()){
        pii u = q.front();q.pop();
		int i = u.fst;
        if(i == b){
            show(u.snd);
            return;
        }
		while(true){
			pll nxt = stmx.query(max(i-p[i],0),i);
			if(i > nxt.fst || nxt.fst == -MAXll)break;
			stmx.update(nxt.snd,{-MAXll,-MAXll});
			q.push({nxt.snd,u.snd + 1});
		}
		while(true){
			pll nxt = stmn.query(i+1,min(i+p[i]+1,n));
			nxt.fst = -nxt.fst;
			if(nxt.fst > i || nxt.fst == -MAXll)break;
			stmn.update(nxt.snd,{-MAXll,-MAXll});
			q.push({nxt.snd,u.snd + 1});
		}
    }
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Returneamos al pabellón