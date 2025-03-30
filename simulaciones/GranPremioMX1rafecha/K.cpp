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
#define MAXN (25*25)+1
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
int n,m,K;
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
vector<pii> D = {{1,2},{-1,-2},{-1,2},{1,-2},{2,1},{-2,-1},{2,-1},{-2,1}};

int solve(int nn, int k, vector<int> *mat){
    set<int> seen;
    fore(i,0,nn)fore(j,0,nn){
        if(mat[i][j]==-1)continue;
        for(auto d: D){
            int ni = i + d.fst, nj = j + d.snd;
            if(ni<0 || ni>=nn || nj<0 || nj>=nn || mat[ni][nj]==-1 || seen.count(mat[ni][nj]))continue;
            g[mat[i][j]].push_back(mat[ni][nj]);
            g[mat[ni][nj]].push_back(mat[i][j]);
            seen.insert(mat[i][j]);
        }
    }
    vector<pii> mtch = max_matching();
    return SZ(mtch)/2;
}

int main(){
    FIN;
    cin>>n>>K;
    n = K;
    m = K;
    int N = n;
    vector<int> mat[N];
    fore(i,0,N)fore(j,0,N)mat[i].pb(-1);
    int cnt = 0;
    fore(i,0,K){
        int a,b;
        cin>>a>>b;
        --a;--b;
        mat[a][b] = cnt;
        ++cnt;
    }
    show(solve(N,K,mat));
    return 0;
}

//Cue "Eye of the Tiger"