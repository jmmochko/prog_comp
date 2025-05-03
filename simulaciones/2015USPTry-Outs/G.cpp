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

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll> nums(k);
    fore(i,0,k)cin>>nums[i];
    if(n==1){
        show("Y");
        return;
    }
    sort(all(nums));
    fore(i,0,k){
        ll coso = gcd(nums[i],n);
        while(n!=1 && nums[i]!=1 && coso != 1){
            n /= coso;
            coso = gcd(nums[i],n);
        }
    }
    if(n==1)show("Y");
    else show("N");
}

int main(){
    //FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"