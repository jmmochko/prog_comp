#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;

int r,c;
int mat[101][101];
int vis[101][101];

vector<pair<int,int>> D = {{0,1},{1,0},{-1,0},{0,-1}};

int bfs(int si, int sj){
    fore(i,0,r)fore(j,0,c)vis[i][j] = 0;
    priority_queue<pair<int,pair<int,int>>> q;
    int estoy = mat[si][sj], res = 1;
    q.push({estoy,{si,sj}});
    vis[si][sj] = true;
    while(!q.empty()){
        pair<int,pair<int,int>> u = q.top();
        q.pop();
        estoy = u.first;
        si = u.snd.fst;
        sj = u.snd.snd;
        for(auto d: D){
            int i = si + d.fst, j = sj + d.snd;
            if(i<0 || i>=r || j<0 || j>=c)continue;
            if(vis[i][j] || mat[i][j]<estoy)continue;
            q.push({mat[i][j],{i,j}});
            vis[i][j] = true;++res;
        }
    } 
    return res;
}

int main(){
    FIN;
    cin>>r>>c;
    fore(i,0,r)fore(j,0,c){
        cin>>mat[i][j];
    }
    int res = 1;
    fore(i,0,r)fore(j,0,c)res = max(res,bfs(i,j));
    cout<<res<<'\n';
    return 0;
}