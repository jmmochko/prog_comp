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

void solve(){
    int n;
    cin>>n;
    vector<ll> nums(n);
    input(nums);
    vector<int> dp(n,MAXINT),pseudo(n,1);
    vector<pair<ll,int>> ord(n);
    fore(i,0,n)ord[i] = {-nums[i],i};
    sort(all(ord));
    fore(k,0,n){
        int j = ord[k].second,i=pseudo[ord[k].second];
        DGB(j);
        ll maxi = nums[j];
        dp[j]=0;
        while(i<2*n){
            if(dp[(j+i)%n]<MAXINT)dp[j]+=dp[(i+j)%n];
            maxi = max(maxi,nums[(i+j)%n]);
            if(nums[(i+j)%n]<maxi/2+(maxi%2)){
                DGB((j+i)%n);
                show("BREAKEE");
                break;
                }
            i++;
        }
        dp[j] += i;
        fore(a,1,dp[j]+1){
            pseudo[(j+a)%n] = max(pseudo[(j+a)%n],dp[j]-a);
        }
        showAll(dp);
        showAll(pseudo);
        RAYA;
    }
    showAll(dp);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Escuchen, corran la bola...