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
#define MAXN 1001
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

vector<int> g[MAXN]; // [0,n)->[0,m)
int n,m;
int mat[MAXN];bool vis[MAXN];
int match(int x){
	if(vis[x])return 0;
	vis[x]=true;
	for(int y:g[x])if(mat[y]<0||match(mat[y])){mat[y]=x;return 1;}
	return 0;
}
vector<pair<int,int> > max_matching(){
	vector<pair<int,int> > r;
	memset(mat,-1,sizeof(mat));
	fore(i,0,n)memset(vis,false,sizeof(vis)),match(i);
	fore(i,0,m)if(mat[i]>=0)r.pb({mat[i],i});
	return r;
}

void solve(){
    cin>>n;
    string mat[n];
    bool vis[n][n];
    fore(i,0,n)fore(j,0,n)vis[i][j] = false;
    fore(i,0,n)cin>>mat[i];
    vector<set<int>> clqs;//max cliques
    set<int> used;//shirts that have at least one incompatible pairing
    fore(i,0,n)fore(j,i+1,n){
        if(vis[i][j] || mat[i][j] == '0')continue;
        vis[i][j] = true;
        set<int> cur;
        cur.insert(i);
        cur.insert(j);
        used.insert(i);
        used.insert(j);
        fore(k,0,n){
            if(k==i || k==j)continue;
            if(mat[k][i]=='0' || mat[k][j]=='0')continue;
            vis[k][i] = true;
            vis[k][j] = true;
            vis[i][k] = true;
            vis[j][k] = true;
            cur.insert(k);
            used.insert(k);
        }
        clqs.pb(cur);
    }
    int res = 0;
    if(SZ(clqs) == 0){
        show(n);
        return;
    }
    vector<set<int>> lside, rside;//sides of matching
    lside.pb(clqs[0]);
    fore(i,1,SZ(clqs)){
        bool found = false;
        fore(k,0,SZ(lside)){
            for(auto e: clqs[i]){
                if(lside[k].count(e)){
                    rside.pb(clqs[i]);
                    found = true;
                    break;
                }
            }
            if(found)break;
        }
        if(!found)lside.pb(clqs[i]);
    }
    // :-(
    vector<bool> f(n,false);
    fore(i,0,SZ(lside)){
        for(auto e: lside[i])f[e] = true;
    }
    fore(i,0,SZ(f)){
        if(!f[i])lside.pb({i});
        f[i] = false;
    }
    fore(i,0,SZ(rside)){
        for(auto e: rside[i])f[e] = true;
    }
    fore(i,0,SZ(f))if(!f[i])rside.pb({i});
    n = SZ(lside);
    m = SZ(rside);
    //fill matching
    fore(i,0,SZ(lside)){
        fore(j,0,SZ(rside)){
            //hago arista <i,j> si comparten por lo menos un elemento
            for(auto e: lside[i]){
                if(rside[j].count(e)){g[i].pb(j);break;}
            }
        }
    }
    show(res+SZ(max_matching()));
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//El año que viene soy GOD