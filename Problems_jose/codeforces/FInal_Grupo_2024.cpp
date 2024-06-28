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
#define MAXN 1001
#define ALPH 26
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1ll<<59)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

ll C[MAXN + 1][MAXN + 1];

void solve(){
    int k;
    cin>>k;
    vector<ll> blls(k);
    ll res = 1,acc;
    cin>>blls[0];
    acc = blls[0];
    fore(i,1,k){
        cin>>blls[i];
        acc += blls[i];
        res *= C[acc-1][blls[i]-1];
        res = res%M;
    }
    show(res);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    C[0][0] = 1;
    for (int n = 1; n <= MAXN; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k){
            C[n][k] = (C[n - 1][k - 1] + C[n - 1][k])%M;
        }
    }
    while(t--){
        solve();
    }
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.