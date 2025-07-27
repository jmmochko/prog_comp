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

void solve(){
    int n;
    cin>>n;
    ll mat[n][n];
    fore(i,0,n)fore(j,0,n)cin>>mat[i][j];
    ll res = mat[n/2][n/2];
    //minimo de cada cuadrante
    map<int,ll> cmin;
    cmin[0] = 1e9;
    fore(i,0,n/2 + 1){
        fore(j,0,n/2 + 1){
            cmin[0] = min(cmin[0],mat[i][j]);
        }
    }
    cmin[1] = 1e9;
    fore(i,n/2,n){
        fore(j,0,n/2+1){
            cmin[1] = min(cmin[1],mat[i][j]);
        }
    }
    cmin[2] = 1e9;
    fore(i,0,n/2 + 1){
        fore(j,n/2,n){
            cmin[2] = min(cmin[2],mat[i][j]);
        }
    } 
    cmin[3] = 1e9;
    fore(i,n/2,n){
        fore(j,n/2,n){
            cmin[3] = min(cmin[3],mat[i][j]);
        }
    }
    res = min(res,cmin[0] + cmin[1] + cmin[2] + cmin[3]);
    map<int,ll> hor;
    hor[0] = 1e9;
    fore(i,0,n/2 + 1){
        hor[0] = min(hor[0],mat[i][n/2]);
    }
    hor[1] = 1e9;
    fore(i,n/2,n){
        hor[1] = min(hor[1],mat[i][n/2]);
    }
    res = min({res,hor[0] + hor[1], hor[0] + cmin[1] + cmin[3], hor[1] + cmin[0] + cmin[2]});
    map<int,ll> vert;
    vert[0] = 1e9;
    fore(i,0,n/2 + 1){
        vert[0] = min(vert[0],mat[n/2][i]);
    }
    vert[1] = 1e9;
    fore(i,n/2,n){
        vert[1] = min(vert[1],mat[n/2][i]);
    }
    res = min({res,vert[0] + vert[1], vert[0] + cmin[2] + cmin[3], vert[1] + cmin[0] + cmin[1]});
    cout<<res<<'\n';
}

int main(){
    FIN;
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}