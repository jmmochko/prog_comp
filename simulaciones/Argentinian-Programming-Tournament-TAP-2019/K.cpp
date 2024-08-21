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
    vector<pll> D,J;
    fore(i,0,n){
        char t;
        pll e;
        cin>>t>>e.first>>e.second;
        if(t=='D'){
            D.push_back(e);
        }
        else{
            J.push_back(e);
        }
    }
    sort(all(D));
    sort(all(J));
    int d = 0, j = 0;
    ll res = 0;
    while(d<SZ(D)){
        while(d<SZ(D)-1&&D[d].first==D[d+1].first)++d;
        while(j<SZ(J) && J[j].second<D[d].first)++j;
        while(j<SZ(J)-1&&J[j].first==J[j+1].first)++j;
        int jcpy = j;
        while(jcpy<SZ(J)&&J[jcpy].first<=D[d].second){
            res = max(res,min(D[d].second,J[jcpy].second)-max(J[jcpy].first,D[d].first));
            ++jcpy;
        }
        ++d;
    }
    show(res);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//ESTOY SOLO YO