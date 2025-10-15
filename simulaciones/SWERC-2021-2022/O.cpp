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

vector<pii> D = {{1,0},{0,1},{-1,0},{0,-1}};

void solve(){
    int n;
    cin>>n;
    bool mat[50][720];
    fore(i,0,50)fore(j,0,720)mat[i][j] = true;
    fore(_,0,n){
        char T;
        cin>>T;
        if(T=='C'){
            int r,t1,t2;
            cin>>r>>t1>>t2;
            r*=2; t1*=2; t2*=2;
            int t = t1;
            while(t!=t2){
                mat[r][t] = false;
                t = (t+1)%720;
            }
            mat[r][t] = false;
        }
        else{
            int r1,r2,t;
            cin>>r1>>r2>>t;
            r1*=2; r2*=2; t*=2;
            fore(r,r1,r2+1){
                mat[r][t] = false;
            }
        }
    }
    bool vis[50][720];
    fore(i,0,50)fore(j,0,720)vis[i][j] = false;
    //fore(i,0,50)fore(j,0,720)cout<<mat[i][j];cout<<'\n';
    queue<pii> q;
    q.push({0,0});
    vis[0][0] = true;
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        int i = u.fst, j = u.snd;
        if(i>45){
            show("YES");
            return;
        }
        for(auto d: D){
            int ni = i + d.fst, nj = j + d.snd;
            if(nj<0)nj+=720;
            nj = nj%720;
            if(ni<0 || vis[ni][nj] || !mat[ni][nj])continue;
            vis[ni][nj] = true;
            q.push({ni,nj});
        }
    }
    show("NO");
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Returneamos al pabellón