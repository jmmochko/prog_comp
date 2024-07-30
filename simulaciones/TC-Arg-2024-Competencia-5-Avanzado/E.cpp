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
#define MAXN 100005
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
struct UF {
	vector<int> e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

vector<int> g[MAXN];

void solve(){
    int n,m;
    cin>>n>>m;
    fore(i,0,m){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(m<n-1||m==0){
        show(0);
        return;
    }
    fore(i,0,n)sort(all(g[i]));
    int cmps = 1;
    UF uf(n);
    uf.e[0]=1;
    fore(i,1,n){
        int j = 0;
        ++cmps;
        vector<int> cnt(cmps+1,0),exs(cmps+1);
        while(g[i][j]<i){
            int u = g[i][j];
            int c = uf.find(u);
            cnt[c]++;
            exs[c] = u;
            ++j;
        }
        DGB(i);
        showAll(cnt);
        fore(k,0,cmps){
            if(cnt[k]<uf.size(exs[k])){
                DGB(exs[k]);
                uf.join(exs[k],i);
                --cmps;
            }
        }
        showAll(uf.e);
    }
    show(cmps-1);
}

int main(){
    //FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Escuchen, corran la bola...