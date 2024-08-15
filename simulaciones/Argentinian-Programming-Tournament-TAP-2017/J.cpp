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
#define MAXN 4001
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

int g[MAXN][MAXN]; // [0,n)->[0,m)
int nn,mm;
int mat[MAXN];bool vis[MAXN];
int match(int x){
	if(vis[x])return 0;
	vis[x]=true;
	fore(y,0,mm)if(g[x][y]==1)if(mat[y]<0||match(mat[y])){mat[y]=x;return 1;}
	return 0;
}
vector<pair<int,int> > max_matching(){
	vector<pair<int,int> > r;
	memset(mat,-1,sizeof(mat));
	fore(i,0,nn)memset(vis,false,sizeof(vis)),match(i);
	fore(i,0,mm)if(mat[i]>=0)r.pb({mat[i],i});
	return r;
}

void solve(){
    int n,m;
    cin>>n>>m;
    map<string,int> stoint;
    fore(i,0,2*m)fore(j,0,2*m)g[i][j] = 1;
    fore(i,0,n){
        vector<string> ss(m);
        input(ss);
        fore(k,0,m){
            if(stoint.find(ss[k])==stoint.end()){
                stoint[ss[k]] = SZ(stoint);
            }
        }
        fore(k,0,m){
            fore(p,0,m){
                g[stoint[ss[k]]][stoint[ss[p]]]=0;
            }
        }
    }
    if(SZ(stoint)>2*m){
        show("N");
        return;
    }
    nn = 2*m;
    mm = 2*m;
    vector<pair<int,int> > aaa = max_matching();
    if(SZ(aaa)==2*m)show("S");
    else show("N");
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo