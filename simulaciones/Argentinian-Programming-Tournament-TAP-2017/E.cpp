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
    bool res = false;
    vector<ll> h(3);
    cin >> h[0] >> h[1] >> h[2];
    sort(all(h));
    ll a = h[0];
    ll b = h[1];
    ll c = h[2];
    // showAll(a);

    if(a==1){
        if(b==2 || b == 3) res = true;
        else if(b == 4 && c == 5) res = true;
    } else if(a == 2){
        if(b == 3 && c == 4) res = true;
    }

    if(res) cout << "S\n";
    else cout << "N\n";
}

int main(){
    FIN;
    int t = 1;
    // cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo