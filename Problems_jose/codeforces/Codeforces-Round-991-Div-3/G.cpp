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

vector<vector<int>> g(MAXN);

int dp[MAXN];
int f[MAXN];
bool vis[MAXN];

int dfs(int u){
    if(vis[u])return dp[u];
    vis[u] = true;
    int res = 0;
    for(auto v: g[u]){
        if(!vis[v])f[v] = u;
        res = max(res,dfs(v));
    }
    dp[u] = max(res + SZ(g[u])-2,SZ(g[u]));
    return dp[u];
}

int branchPath(int u){
    vector<int> nums;
    for(auto v: g[u]){
        if(v!=f[u]){
            nums.pb(dfs(v));
        }
    }
    sort(all(nums));
    if(SZ(nums)<2)return 0;
    return (nums[SZ(nums)-1]-1) + (nums[SZ(nums)-2]-1) + (SZ(g[u]) - 2);
}

void solve(){
    int n;
    cin>>n;
    fore(i,0,n){g[i].clear();vis[i]=false;dp[i]=0;}
    fore(i,0,n-1){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vis[0] = true;
    int res = SZ(g[0]);
    f[0] = 0;
    for(auto v: g[0]){
        f[v] = 0;
        res = max(res,dfs(v)+(SZ(g[0])-1)-1);
    }
    fore(i,1,n){
        //DGB(i);DGB(dfs(i));DGB(branchPath(i));RAYA;
        res = max(max(res,branchPath(i)),dfs(i));
    }
    //DGB(branchPath(0));
    show(max(res,branchPath(0)));
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//El año que viene soy GOD