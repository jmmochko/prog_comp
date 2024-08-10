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

ll fst_pow(ll b, ll e){
    if(e==0)return 1;
    ll aux = fst_pow(b,e/2);
    aux*=aux;
    if(e%2!=0)aux*=b;
    return aux;
}

void solve(){
    ll k,d=1,sz=9;
    cin>>k;
    while(k-d*sz>0){
        k -= d*sz;
        sz*=10;
        ++d;
    }
    ll i = k%d,res=fst_pow(10ll,d-1ll)+(k-1ll)/d;
    if(i)res = res / fst_pow(10ll,d-i);
    show(res%10);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo