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

ll t;
int n;

ll f(int i, int r, vector<ll> &dp, vector<ll> &meenter){//minimum cost in time at position i
    if(dp[i]!=MAXll)return dp[i];
    if(i>=n-1)return 0;
    if(i+r>=n-1){
        dp[i] = 0;
        return 0;
    } 
    fore(j,i+1,i+r+1)dp[i] = min(meenter[j]+f(j,r,dp,meenter),dp[i]);
    return dp[i];
}

bool can(vector<ll> &meenter, int r){
    if(r>=n-1)return true;
    vector<ll> dp(n,MAXll);
    ll res = f(0,r,dp,meenter);
    return res<=t;
}

int main(){
    FIN;
    //ifstream cin("journey.in");
    //ofstream cout("journey.out");
    cin>>n>>t;
    vector<ll> cards(n-1);
    input(cards);
    int a[n];
    fore(i,0,n)a[i]=MAXINT;
    vector<ll> meenter;
    meenter.push_back(0);
    fore(i,0,n-2){
        ll e;
        cin>>e;
        meenter.push_back(e);
    }
    meenter.push_back(0);
    int l = -1, r = n;
    while(l+1<r){
        int m = (l+r)/2;
        if(can(meenter,m))r = m;
        else l = m;
    }
    ll res = MAXll;
    fore(i,l,n-1)res = min(cards[i],res);
    show(res);
    //cin.close();
    //cout.close();
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.