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
#define MAXN 2005
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
int n,l;

ll dp[MAXN];//amount of people reached from ml i

ll cnt(int i, vector<vector<ll>> &ls){
    if(i>=SZ(ls))return 1;
    if(dp[i]!=-1)return dp[i];
    dp[i] = 0;
    fore(k,0,SZ(ls[i])){
        dp[i] += cnt(ls[i][k],ls);
        dp[i] = dp[i]%M;
    }
    return dp[i];
}

set<ll> cur;

bool vis[MAXN];

void walk(int i, vector<vector<ll>> &ls){
    if(i>=SZ(ls))return;
    vis[i] = true;
    fore(k,0,SZ(ls[i])){
        if(ls[i][k]>=l){
            cur.insert(ls[i][k]);
        }
        else if(!vis[ls[i][k]]){
            walk(ls[i][k],ls);
        }
    }
}

void solve(){
    cin>>n>>l;
    fore(i,0,MAXN)dp[i] = -1;
    vector<vector<ll>> ls(l);
    fore(i,0,l){
        ll k,e;
        cin>>k;
        fore(j,0,k){
            cin>>e;
            ls[i].push_back(e-1);
        }
    }
    cout<<cnt(0,ls)<<" ";
    walk(0,ls);
    show(SZ(cur));
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?