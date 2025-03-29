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
#define MAXN 200005
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

int N,K;

vector<pii> D = {{1,2},{-1,-2},{-1,2},{1,-2}};

int brute(int n, int k, vector<int> *mat){
    vector<set<int>> ks(k*k);
    fore(i,0,n)fore(j,0,n){
        if(mat[i][j]==-1)continue;
        for(auto d: D){
            int ni = i + d.fst, nj = j + d.snd;
            if(ni<0 || ni>=n || nj<0 || nj>=n || mat[ni][nj]==-1)continue;
            ks[mat[i][j]].insert(mat[ni][nj]);
            ks[mat[ni][nj]].insert(mat[i][j]);
            int nii = i + d.snd, njj = j + d.fst;
            if(nii<0 || nii>=n || njj<0 || njj>=n || mat[nii][njj]==-1)continue;
            ks[mat[i][j]].insert(mat[nii][njj]);
            ks[mat[nii][njj]].insert(mat[i][j]);
        }
    }
    int res = 0;
    while(true){
        int mx = 0, mxpos = 0;
        fore(i,0,SZ(ks)){
            if(SZ(ks[i])>mx){
                mx = SZ(ks[i]);
                mxpos = i;
            }
        }
        if(mx == 0)break;
        ++res;
        for(auto e: ks[mxpos]){
            ks[e].erase(mxpos);
        }
        ks[mxpos].clear();
    }
    return res;
}

int main(){
    FIN;
    cin>>N>>K;
    vector<int> mat[N];
    fore(i,0,N)fore(j,0,N)mat[i].pb(-1);
    int cnt = 0;
    fore(i,0,K){
        int a,b;
        cin>>a>>b;
        --a;--b;
        mat[a][b] = cnt;
        ++cnt;
    }
    show(brute(N,K,mat));
    return 0;
}

//Cue "Eye of the Tiger"