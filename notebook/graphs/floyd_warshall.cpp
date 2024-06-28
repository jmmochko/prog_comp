#include <bits/stdc++.h>
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define MAXN 200005
#define MAXll (1ll<<60)
typedef long long ll;
using namespace std;
// g[i][j]: weight of edge (i, j) or INF if there's no edge
// g[i][i]=0
ll g[MAXN][MAXN];int n;
void floyd(){ // O(n^3) . Replaces g with min distances
	fore(k,0,n)fore(i,0,n)if(g[i][k]<MAXll)fore(j,0,n)if(g[k][j]<MAXll)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}