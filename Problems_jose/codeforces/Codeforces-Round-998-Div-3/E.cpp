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
#define MAXN 200003
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

int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

int uf2[MAXN];
void uf2_init(){memset(uf2,-1,sizeof(uf2));}
int uf2_find(int x){return uf2[x]<0?x:uf2[x]=uf2_find(uf2[x]);}
bool uf2_join(int x, int y){
	x=uf2_find(x);y=uf2_find(y);
	if(x==y)return false;
	if(uf2[x]>uf2[y])swap(x,y);
	uf2[x]+=uf2[y];uf2[y]=x;
	return true;
}



int main(){
    FIN;
    int t = 1;
    cin>>t;
    uf_init();
    uf2_init();
    while(t--){
        int n,m1,m2;cin>>n>>m1>>m2;
        fore(i,0,n+1){
            uf[i] = -1;
            uf2[i] = -1;
        }
    vector<int> g[n];
    fore(i,0,m1){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    fore(i,0,m2){
        int u,v;
        cin>>u>>v;
        --u;--v;
        uf_join(u,v);
    }
    //elim all edges going to another cc and build resulting ccs
    int res = 0;
    fore(i,0,n){
        fore(j,0,SZ(g[i])){
            if(uf_find(g[i][j])!=uf_find(i)){
                ++res;
            }
            else uf2_join(i,g[i][j]);
        }
    }
    res = res/2;
    //add necesary edges
    set<int> ccs1, ccs2;
    fore(i,0,n){
        ccs1.insert(uf_find(i));
        ccs2.insert(uf2_find(i));
    }
    res += abs(SZ(ccs2) - SZ(ccs1));
    show(res);
    }
    return 0;
}

//Cue "Eye of the Tiger"