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

int main(){
    FIN;
    int n,x;
    cin>>n>>x;
    vector<int> h(n),s(n);
    input(h);input(s);
    int dp[2][x+1];//mejor sol pagando <= j
    fore(i,0,min(h[0],x+1))dp[0][i] = 0;
    fore(i,h[0],x+1)dp[0][i] = s[0];
    fore(i,0,x+1)dp[1][i] = 0;
    fore(i,1,n){
        int est = (i&1);
        int prev = 1-est;
        fore(j,0,min(h[i],x+1))dp[est][j] = dp[prev][j];
        fore(j,h[i],x+1)dp[est][j] = max(dp[prev][j],dp[prev][j-h[i]] + s[i]);
    }
    show(max(dp[0][x],dp[1][x]));
    return 0;
}

//Sobrevivimos al pabellon