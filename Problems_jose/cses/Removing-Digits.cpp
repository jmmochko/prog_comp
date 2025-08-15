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
#define MAXN 1000005
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

int dp[MAXN];

int f(int n){
    //DGB(n);
    if(dp[n]!=0)return dp[n];
    if(n<10)return 1;
    int res = n, cmp = 1;
    while(cmp <= n){
        int d = (n/cmp)%10;
        if(d==0){cmp*=10;continue;}
        res = min(res,f(n-d));
        cmp*=10;
    }
    dp[n] = 1 + res;
    return dp[n];
}

int main(){
    //FIN;
    int n;
    cin>>n;
    show(f(n));
    return 0;
}

//Sobrevivimos al pabellon