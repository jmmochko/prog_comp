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
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
const ll M = 1e9+7;

//El Vasito is love, El Vasito is life

int dp[100][1000001];
int modk[1000001];
int nums[100];

int main(){
    FIN;
    int n,x;
    cin>>n>>x;
    fore(i,0,n)cin>>nums[i];
    int jj = 0;
    while(jj<=x){
        dp[0][jj] = 1;
        jj += nums[0];
    }
    fore(i,1,n){
        int k = nums[i], mk = 1;
        fore(kk,0,k)modk[kk] = 0;
        modk[0] = 1;
        fore(j,1,x+1){
            if(mk>=k)mk-=k;
            modk[mk] = (modk[mk] + dp[i-1][j])%M;
            dp[i][j] = modk[mk];
            ++mk;
        }
    }
    show(dp[n-1][x]);
    return 0;
}

//Sobrevivimos al pabellon