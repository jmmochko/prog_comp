#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst frist
#define snd second
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;

vector<int> g[1001];

void dfs(int u, vector<bool> &vis){
    vis[u] = true;
    for(auto v: g[u]){
        if(!vis[v])dfs(v,vis);
    }
}

int main(){
    FIN;
    int n;
    cin>>n;
    int v[n][2];
    vector<int> ind(n,0);
    fore(i,0,n)fore(j,0,2){cin>>v[i][j];--v[i][j];ind[v[i][j]]++;g[v[i][j]].push_back(i);}
    fore(i,0,n){
        bool res = false;
        vector<bool> vis(n,false),vis1(n,false),vis2(n,false);
        vis1[i] = true;
        vis2[i] = true;
        dfs(i,vis);dfs(v[i][0],vis1);
        dfs(v[i][1],vis2);
        fore(j,0,n)if(vis[j] && vis1[j] && vis2[j] && i!=j){
            cout<<'Y';res = true;break;
        }
        if(!res)cout<<'N';
    }
    cout<<'\n';
    return 0;
}