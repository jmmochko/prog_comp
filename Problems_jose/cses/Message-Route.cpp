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

int vis[MAXN];

vector<int> g[MAXN];

void solve(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        --x;--y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x==n)break;
        for(auto y:g[x]){
            if(!vis[y]&&y!=0){
                q.push(y);
                vis[y] = vis[x] + 1;
            }
        }
    }
    if(!vis[n-1]){
        show("IMPOSSIBLE");
        return;
    }
    vector<int> res;
    int i = n-1;
    while(i!=0){
        res.push_back(i+1);
        for(auto x:g[i]){
            if(vis[x]==vis[i]-1){
                i = x;
                break;
            }
        }
    }
    res.push_back(1);
    reverse(all(res));
    show(SZ(res));
    showAll(res);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?