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

string p;

int vis[7][7];

bool cant(int i, int j){
    return (i<0 || j<0 || i>6 || j>6 || vis[i][j]);
};

int dfs(int i, int j, int m){//ways of reaching the end having made m moves
    if(cant(i,j))return 0;
    if(m==SZ(p))return i==0&&j==6;
    if(i==0 && j==6)return 0;
    vis[i][j]=true;
    int res = 0;
    if(p[m]=='D'||p[m]=='?'){
        if(cant(i+1,j+1) || cant(i+1,j-1) || !cant(i+2,j))res+=dfs(i+1,j,m+1);
    }
    if(p[m]=='U'||p[m]=='?'){
        if(cant(i-1,j+1) || cant(i-1,j-1) || !cant(i-2,j))res+=dfs(i-1,j,m+1);
    }
    if(p[m]=='L'||p[m]=='?'){
        if(cant(i+1,j-1) || cant(i-1,j-1) || !cant(i,j-2))res+=dfs(i,j-1,m+1);
    }
    if(p[m]=='R'||p[m]=='?'){
        if(cant(i+1,j+1) || cant(i-1,j+1) || !cant(i,j+2))res+=dfs(i,j+1,m+1);
    }
    vis[i][j] = false;
    return res;
};

void solve(){    
    cin>>p;
    show(dfs(0,0,0));
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo