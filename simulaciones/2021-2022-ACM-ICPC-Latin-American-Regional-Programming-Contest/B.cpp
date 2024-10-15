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
    vector<ll> f(n),c(n);
    input(f);input(c);
    sort(all(c));sort(all(f));
    ll acc = 0;
    int lf = 0,rf = n-1,lc = 0,rc = n-1;
    vector<ll> resmin;
    fore(i,0,n){
        //update min
        if(c[lc]*f[rf]>c[rc]*f[lf]){
            acc += c[rc]*f[lf];
            --rc;
            ++lf;
        }
        else{
            acc += c[lc]*f[rf];
            --rf;
            ++lc;
        }
        resmin.push_back(acc);
    }
    acc = 0;
    lf = 0,rf = n-1,lc = 0,rc = n-1;
    vector<ll> resmax;
    fore(i,0,n){
        //update max
        if(c[lc]*f[lf]>c[rc]*f[rf]){
            acc += c[lc]*f[lf];
            ++lc;
            ++lf;
        }
        else{
            acc += c[rc]*f[rf];
            --rf;
            --rc;
        }
        resmax.push_back(acc);
    }
    fore(i,0,n){
        cout<<resmin[i]<<" "<<resmax[i]<<'\n';
    }
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?