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

bool isP(ll n, ll b){
    vector<ll> num;
    while(n>0){
        num.pb(n%b);
        n/=b;
    }
    int i=0,j=SZ(num)-1;
    while(i<j){
        if(num[i]!=num[j])return false;
        ++i;--j;
    }
    //showAll(num);
    return true;
}

void solve(){
    ll n;cin>>n;
    vector<int> res;
    fore(i,2,17){
        if(isP(n,i))res.pb(i);
    }
    if(SZ(res)==0){cout<<"-1"<<'\n';return;}
    else showAll(res);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"