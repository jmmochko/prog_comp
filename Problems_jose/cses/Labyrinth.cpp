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

pii vis[MAXN][MAXN];

int n,m;

vector<string> B;

bool valid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m && B[i][j]!='#' && vis[i][j].first==-1);
}

vector<pii> D = {{1,0},{-1,0},{0,-1},{0,1}};
string dir = "UDRL";

queue<pii> bfs;
bool found=false;

void solve(){
    cin>>n>>m;
    fore(i,0,n){
        string s;
        cin>>s;
        B.push_back(s);
    }
    fore(i,0,n)fore(j,0,m)vis[i][j] = {-1,-1};
    int ia=-1,ja=-1,ib=-1,jb=-1;
    fore(i,0,n)fore(j,0,m){
        if(B[i][j]=='A'){
            ia = i; ja = j;
        }
        if(B[i][j]=='B'){
            ib = i; jb = j;
        }
    }
    queue<pii> bfs;
    bool found=false;
    bfs.push({ia,ja});
    while(!bfs.empty()&&!found){;
        pii c = bfs.front();
        bfs.pop();
        for(auto d:D){
            int ni=c.first+d.first,nj=c.second+d.second;
            if(!(valid(ni,nj)))continue;
            bfs.push({ni,nj});
            vis[ni][nj] = c;
            if(B[ni][nj]=='B')found = true;
        }
    }
    if(vis[ib][jb].first==-1){
        show("NO");
        return;
    }
    string path;
    int ci = ib,cj = jb;
    while(B[ci][cj]!='A'){
        fore(i,0,SZ(D)){
            int ni = ci+D[i].first, nj = cj+D[i].second;
            if(vis[ci][cj].first == ni && vis[ci][cj].snd == nj){
                path.push_back(dir[i]);
                ci = ni;
                cj = nj;
                break;
            }
        }
    }
    reverse(all(path));
    show("YES");
    show(SZ(path));
    show(path);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?