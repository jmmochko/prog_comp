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
typedef pair<ll,ll> ii;
    
#define MAXN 200005
int uf[MAXN];
void uf_init(){memset(uf,-1,int(sizeof(uf)));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
    x=uf_find(x);y=uf_find(y);
    if(x==y)return false;
    if(uf[x]>uf[y])swap(x,y);
    uf[x]+=uf[y];uf[y]=x;
    return true;
}
    
vector<ii> kruskal(vector<ii> &es){  // assumes graph is connected
    sort(es.begin(),es.end());uf_init();
    vector<ii> r;
    fore(i,0,es.size()){ // without 1
        int x=es[i].fst,y=es[i].snd;
        if(uf_join(x,y))r.pb(es[i]); // (x,y,c) belongs to mst
    }
    return r; // vertexs
}
    
int main(){
    FIN;
    uf_init();
    ll n,m,D;
    cin>>n>>m>>D;
    vector<ii> edgesnotconnectedto1;
    vector<int> vertexesconnectedto1;
    fore(i,0,m){
        vector<int> uv(2);
        input(uv);
        sort(all(uv));
        if(uv[0]==1)vertexesconnectedto1.push_back(uv[1]);
        else {
            uf_join(uv[0],uv[1]);
            edgesnotconnectedto1.push_back({uv[0],uv[1]});
            edgesnotconnectedto1.push_back({uv[1],uv[0]});
        }
    }
    set<int> usededges;
    set<int> usedcomponents;
    fore(i,0,SZ(vertexesconnectedto1)){
        int v = vertexesconnectedto1[i];
        if(uf_find(v)==-1){
            --D;
            usededges.insert(v);
        }
        else if(usedcomponents.count(uf_find(v))==0){
            --D;
            usededges.insert(v);
            usedcomponents.insert(uf_find(v));
        }
    }
    fore(i,0,SZ(vertexesconnectedto1)){
        int v = vertexesconnectedto1[i];
        if(usededges.count(v)==0 && D>0){
            --D;
            usededges.insert(v);
        }
    }
    if(D!=0){
        show("NO");
    }
    else{
        vector<ii> usableedges;
        for(auto e: usededges){
            usableedges.pb({1,e});
        }
        for(auto e: edgesnotconnectedto1){
            usableedges.pb(e);
        }
        vector<ii> res = kruskal(usableedges);
        show("YES");
        for(auto e: res){
            cout<<e.first<<" "<<e.second<<'\n';
        }
    }
    return 0;
}

