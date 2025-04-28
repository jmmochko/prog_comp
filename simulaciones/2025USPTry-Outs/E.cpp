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
vector<int> g[MAXN*MAXN];

vector<pii> Ds = {{0,1},{1,0},{-1,0},{0,-1}};

int n,m;

bool valid(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}

int pos(int i, int j){
    return i*m + j;
}

int D[MAXN*MAXN];

void bfs(int s){
    queue<int> q;
    q.push(s);
    D[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: g[u]){
            //DGB(v);
            if(D[u] + 1 < D[v]){
                q.push(v);
                D[v] = D[u] + 1;
            }
        }
    }
}

void solve(){    
    cin>>n>>m;
    string mat[n];
    input(mat);
    int S,E;
    vector<int> Fs;
    fore(i,0,pos(n-1,m-1)+1){g[i].clear();D[i]=MAXINT;}
    fore(i,0,n)fore(j,0,m){
        if(mat[i][j]=='E')E = pos(i,j);
        if(mat[i][j]=='F')Fs.pb(pos(i,j));
        if(mat[i][j]=='S')S = pos(i,j);
        if(mat[i][j]=='#')continue;
        for(auto d: Ds){
            int ni = i + d.first ,nj = j + d.second;
            if(valid(ni,nj)&&mat[ni][nj]!='#'){
                int u = pos(i,j),v = pos(ni,nj);
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
    }
    bfs(E);
    //DGB(D[E]);DGB(D[S]);
    fore(i,0,SZ(Fs)){
        if(D[S]>=D[Fs[i]]){show("N");return;}
    }
    show("Y");
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"