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

vector<int> g[MAXN];
int c[MAXN];
int p[MAXN];
int cs,ce;

bool dfs(int u){
    c[u] = 1;
    bool res = false;
    for(int v: g[u]){
        if(v==p[u])continue;
        if(c[v]==1){
            ce = u;
            cs = v;
            return true;
        }p[v] = u;
        if(c[v]==0)res = res || dfs(v);
    }
    c[u] = 2;
    return res;
}

//returns empty vector if no cycle
vector<int> find_cycle(int gstart, int gend){
    cs = -1; ce = -1;
    fore(i,gstart,gend){
        if(c[i]==0 && dfs(i))break;
    }
    vector<int> res;
    if(cs == -1)return res;
    res.push_back(ce);
    for(int v = cs; v != ce; v = p[v]){
        res.push_back(v);
    }
    res.push_back(ce);
    reverse(all(res));
    return res;
}