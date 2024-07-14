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
string s;
int n,m,k;

int dp[MAXN];

int f(int i){//amount of meters swam to reach this point
    //DGB(i);
    if(i<0)return 0;
    if(i==0){
        if(s[i]!='C')dp[i]=0;
    }
    if(dp[i]!=MAXINT)return dp[i];
    dfore(p,i-1,i-m){
        //DGB(p);
        if(p<0||s[p]=='L'){
            //show("ENTRÉ");
            dp[i] = min(dp[i],f(p));
        }
    }
    //RAYA;
    if(s[i-1]=='W')dp[i] = min(dp[i],f(i-1)+1);
    return dp[i];
}

void solve(){
    cin>>n>>m>>k;
    cin>>s;
    fore(i,0,n+2)dp[i]=MAXINT;
    int res = f(n);
    if(res<=k && res!=MAXINT)show("YES");
    else show("NO");
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.