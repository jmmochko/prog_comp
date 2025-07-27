#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;
typedef long long ll;

struct edge {int u,v,comp; bool bridge;};
vector<edge> e;
void add_edge(int u, int v){
    g[u].pb(e.size()); g[v].pb(e.size());
    e.pb((edge){u,v,-1,false});
}
int D[MAXN], B[MAXN], T;
int nbc;
int art[MAXN];
stack<int> st;
void dfs(int u, int pe){
    B[u]=D[u]=T++;
    for(int ne : g[u]) if(ne!=pe){
        int v = e[ne].u ^ e[ne].v ^ u;
        if(D[v]<0){
            st.push(ne); dfs(v, ne);
            if(B[v] > D[u]) e[ne].bridge = true;
            if(B[v] >= D[u]){
                art[u]++;
                int last;
                do{
                    last = st.top(); st.pop();
                    e[last].comp = nbc;
                } while(last!=ne);
                nbc++;
            }
            B[u] = min(B[u],B[v]);
        }
        else if(D[v] < D[u]) st.push(ne), B[u] = min(B[u], D[v]);
    }
}

void doit(){
    memset(D,-1,sizeof(D)); memset(art,0,sizeof(art));
    nbc=T=0;
    fore(i,0,n) if(D[i]<0) dfs(i,-1),art[i]--;
}

int main(){
    FIN;
}