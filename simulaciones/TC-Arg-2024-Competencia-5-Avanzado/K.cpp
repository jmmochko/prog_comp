#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)(a).size())
#define fst first
#define snd second
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";
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

vector<pair<vector<ll>,vector<ll>>> res(10);

void range_solve(int i, int l, int r){
    if(l+1>=r)return;
    int m = (r+l)/2;
    fore(k,l,m)res[i].first.push_back(k);
    fore(k,m,r)res[i].second.push_back(k);
    range_solve(i+1,l,m);range_solve(i+1,m,r);
}

void solve(){
    fore(i,0,10){res[i].first.clear();res[i].second.clear();}
    ll n,x=0,aux;
    cin>>n;
    range_solve(0,1,n+1);
    int i = 0;
    while(SZ(res[i].first)>0){
        cout<<SZ(res[i].first)<<" "<<SZ(res[i].second)<<" ";
        showAll(res[i].first);showAll(res[i].second);cout<<'\n';fflush(stdout);
        cin>>aux;
        x = max(x,aux);
        ++i;
    }
    cout<<"-1 ";
    show(x);
    fflush(stdout);
}

int main(){
    //FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Escuchen, corran la bola...