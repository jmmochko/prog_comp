#include <bits/stdc++.h>
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define MAXN 505
#define MAXll (1ll<<57)
typedef long long ll;
using namespace std;
// g[i][j]: weight of edge (i, j) or INF if there's no edge
// g[i][i]=0
ll g[MAXN][MAXN];int n;
void floyd(){ // O(n^3) . Replaces g with min distances
	fore(k,1,n+1)fore(i,1,n+1)if(g[i][k]<MAXll)fore(j,1,n+1)if(g[k][j]<MAXll)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

int main(){
    int m,q;
    cin>>n>>m>>q;
    fore(i,0,MAXN)fore(j,0,MAXN)g[i][j] = MAXll;
    fore(i,1,n+1)g[i][i] = 0;
    fore(_,0,m){
        int a,b;ll c;
        cin>>a>>b>>c;
        g[a][b]=min(g[a][b],c);
        g[b][a]=min(g[b][a],c);
    }
    floyd();
    while(q--){
        int a,b;
        cin>>a>>b;
        if(g[a][b]>=MAXll)g[a][b]=-1;
        cout<<g[a][b]<<'\n';
    }
    return 0;
}