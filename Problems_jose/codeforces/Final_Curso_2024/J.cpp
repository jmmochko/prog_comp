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
#define MAXll (1ll<<59)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

// g[i][j]: weight of edge (i, j) or INF if there's no edge
// g[i][i]=0

ll g[ALPH][ALPH];int n;
void floyd(){ // O(n^3) . Replaces g with min distances
	fore(k,0,n)fore(i,0,n)if(g[i][k]<MAXll)fore(j,0,n)if(g[k][j]<MAXll)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
bool inNegCycle(int v){return g[v][v]<0;}
bool hasNegCycle(int a, int b){ // true iff there's neg cycle in between
	fore(i,0,n)if(g[a][i]<MAXll&&g[i][b]<MAXll&&g[i][i]<0)return true;
	return false;
}

void solve(){
    string s,t;
    cin>>s>>t;
    int N;
    cin>>N;
    n = ALPH;
    fore(i,0,ALPH){
        fore(j,0,ALPH){
            g[i][j] = MAXll;
        }
    }
    fore(i,0,ALPH){
        g[i][i]=0ll;
    }
    fore(i,0,N){
        char u,v;
        ll c;
        cin>>u>>v>>c;
        g[u-'a'][v-'a'] = min(c,g[u-'a'][v-'a']);
    }
    if(SZ(s)!=SZ(t)){
        show(-1);
        return;
    }
    floyd();
    ll res = 0;
    fore(i,0,SZ(s)){
        ll cur = MAXll;
        char ccur;
        fore(j,0,ALPH){//cost of bringing both to i
            if(g[s[i]-'a'][j] + g[t[i]-'a'][j]<cur){
                cur=g[s[i]-'a'][j] + g[t[i]-'a'][j];
                ccur=(char)j+'a';
            }
        }
        if(cur>=MAXll){
            show(-1);
            return;
        }
        s[i] = ccur;
        res += cur;
    }
    show(res);
    show(s);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.