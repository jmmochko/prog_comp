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
 
int n,m;
vector<string> B;
 
int vis[MAXN][MAXN];
 
vector<pii> D = {{1,0},{-1,0},{0,1},{0,-1}};
 
string durl = "UDLR";

bool valid(int i, int j){
    return (i<n && i>=0 && j>=0 && j<m && B[i][j]!='#');
}

pii f[MAXN][MAXN];

void markM(int u, int v){
    vis[u][v] = 0;
    queue<pii> bfs;
    bfs.push({u,v});
    while(!bfs.empty()){
        pii nod = bfs.front();
        bfs.pop();
        for(auto d: D){
            int ni = nod.first + d.first, nj = nod.second + d.second;
            if(!valid(ni,nj) || vis[ni][nj] <= vis[nod.first][nod.second]+1)continue;
            vis[ni][nj] = vis[nod.first][nod.second] + 1;
            if(B[ni][nj]=='M') vis[ni][nj] = 0;
            bfs.push({ni,nj});
        }
    }
}

pii salida;

bool walked[MAXN][MAXN];

bool walk(int i, int j, int c){
    if(vis[i][j]<=c)return false;
    if(i==0||j==0||i==n-1||j==m-1){
        salida = {i,j};
        return true;
    }
    walked[i][j] = true;
    for(auto d: D){
        int ni = i + d.first, nj = j + d.second;
        if(!valid(ni,nj)||walked[ni][nj])continue;
        f[ni][nj] = {i,j};
        if(walk(ni,nj,c+1))return true;
    }
    walked[i][j] = false;
    return false;
}

void solve(){
    cin>>n>>m;
    fore(i,0,n){
        string s;
        cin>>s;
        B.push_back(s);
    }
    pii A;
    fore(i,0,n)fore(j,0,m)vis[i][j] = MAXINT;
    fore(i,0,n)fore(j,0,m){
        if(B[i][j]=='M'){
            markM(i,j);
        }
        if(B[i][j]=='A'){
            A = {i,j};
        }
    }
    if(!walk(A.first,A.second,0)){
        show("NO");
        return;
    }
    show("YES");
    string path = "";
    for(pii v = salida; v != A; v = f[v.first][v.second]){
        //DGB(v.first);DGB(v.second);
        fore(i,0,4){
            pii d = D[i];
            pii ni {v.first + d.first, v.second + d.second};
            if(f[v.first][v.second]==ni)path.push_back(durl[i]);
        }
    }
    reverse(all(path));
    show(SZ(path));
    show(path);
}
 
int main(){
    //FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}
 
//Sale regional?