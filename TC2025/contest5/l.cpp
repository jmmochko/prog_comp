#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first 
#define snd second
#define all(a) a.begin() a.end()
#define pb push_back
using namespace std;
typedef long long ll;
const int MAXN = 2000*2001;

int main(){
    FIN;
    int n,m,r,c,x,y;
    cin>>n>>m>>r>>c>>y>>x;
    --r;--c;
    char mat[n][m];
    bool vis[n][m];
    fore(i,0,n)fore(j,0,m){cin>>mat[i][j];vis[i][j] = false;}
    queue<pair<pair<int,int>,pair<int,int>>> q0, q1;//<<i,j>,<movs que me quedan a la derecha, izq>>
    q0.push({{r,c},{x,y}});
    vis[r][c] = true;
    while(!q0.empty() || !q1.empty()){
        if(q0.empty())swap(q0,q1);
        pair<pair<int,int>,pair<int,int>> estoy = q0.front();
        q0.pop();
        int ni = estoy.fst.fst,nj = estoy.fst.snd;
        int mov1 = estoy.snd.fst, mov2 = estoy.snd.snd;
        if(ni + 1 < n && ni + 1 >= 0 && nj < m && nj >= 0 && !vis[ni+1][nj] && mat[ni+1][nj] != '*'){
            q0.push({{ni+1,nj},{mov1,mov2}});
            vis[ni+1][nj] = true;
        }
        if(ni - 1 < n && ni - 1 >= 0 && nj < m && nj >= 0 && !vis[ni-1][nj] && mat[ni-1][nj] != '*'){
            q0.push({{ni-1,nj},{mov1,mov2}});
            vis[ni-1][nj] = true;
        }
        if(ni < n && ni >= 0 && nj+1 < m && nj+1 >= 0 && !vis[ni][nj+1] && mat[ni][nj+1] != '*' && mov1>0){
            q1.push({{ni,nj+1},{mov1-1,mov2}});
            vis[ni][nj+1] = true;
        }
        if(ni < n && ni >= 0 && nj-1 < m && nj-1 >= 0 && !vis[ni][nj-1] && mat[ni][nj-1] != '*' && mov2>0){
            q1.push({{ni,nj-1},{mov1,mov2-1}});
            vis[ni][nj-1] = true;
        }
    }
    int res = 0;
    //fore(i,0,n){fore(j,0,m){if(vis[i][j]){++res;cout<<"X";}else cout<<".";}cout<<'\n';}
    fore(i,0,n)fore(j,0,m)if(vis[i][j])++res;
    cout<<res<<'\n';
    return 0;
}