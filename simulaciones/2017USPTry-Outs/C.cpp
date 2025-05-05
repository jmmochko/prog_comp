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
#define MAXN 500001
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

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}

int dp[MAXN],nums[MAXN];

int main(){
    FIN;
    int n,m;
    cin>>n>>m;
    fore(i,0,n)cin>>nums[i];
    dp[n-1] = MAXINT;
    vector<pii> qs(m);
    int mn = MAXINT;
    fore(i,0,m){
        cin>>qs[i].fst>>qs[i].snd;
        mn = min(mn,qs[i].fst);
    }
    dfore(i,n-2,mn-1){
        dp[i] = dp[i+1]+1;
        //primer cop a la derecha de i (<dp[i])
        fore(j,i+1,min(i+dp[i],n)){
            if(nums[i]%nums[j]==0)break;
            int a = gcd(nums[i],nums[j]);
            if(a==1){
                dp[i] = (j-i);
                break;
            }
        }
    }
    fore(i,0,m){
        int l = qs[i].fst,r = qs[i].snd;
        if(dp[l-1]<=(r-l))show("S");
        else show("N");
    }
    return 0;
}

//Cue "Eye of the Tiger"