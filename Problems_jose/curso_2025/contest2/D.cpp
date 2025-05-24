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
    int n,m;
    cin>>n;
    vector<ll> a(n);
    input(a);
    cin>>m;
    vector<ll> b(m);
    input(b);
    sort(all(a));
    sort(all(b));
    int i = 0, j = 0;
    ll tota = 3*n, totb = 3*m;
    ll res = tota - totb, resa = tota, resb = totb;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            tota--;
            ++i;
        }
        if(tota-totb > res){
            res = max(res,tota-totb);
            resa = tota; resb = totb;
        }
        if(a[i]>=b[j]){
            totb--;
            ++j;
        }
        if(tota-totb > res){
            res = max(res,tota-totb);
            resa = tota; resb = totb;
        }
    }
    while(j<m){
        ++j;
        --totb;
    }
    if(tota-totb > res){
        res = max(res,tota-totb);
        resa = tota; resb = totb;
    }
    cout<<resa<<":"<<resb<<'\n';
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"