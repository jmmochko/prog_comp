#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first 
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back

using namespace std;
typedef long long ll;

int main(){
    FIN;
    int n,m;
    cin>>n>>m;
    bool g[n][n];
    fore(i,0,n)fore(j,0,n)g[i][j] = 0;
    fore(i,0,m){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    bool uso = !g[0][n-1];
    queue<int> q;
    q.push(0);
    vector<int> dist(n,-1);
    dist[0] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        fore(i,0,n){
            if(i==u || dist[i]!=-1 || g[i][u]!=uso)continue;
            dist[i] = dist[u]+1;
            q.push(i);
        }
    }
    if(dist[n-1]==-1){
        cout<<"-1\n";
    }
    else cout<<dist[n-1]<<'\n';
    return 0;
}