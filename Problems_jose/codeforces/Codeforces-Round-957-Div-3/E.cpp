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

string s,aux;

void solve(){
    ll n;
    cin>>n;
    s = to_string(n);
    vector<pll> ppairs;
    fore(a,1,10001){
        fore(b,max(1,SZ(s)*a-5),SZ(s)*a){
            ll x = n*a-b,y=0;
            fore(i,0,SZ(s)*a-b){
                y = y *10 + (s[i%SZ(s)]-'0');
            }
            if(x==y)ppairs.push_back({a,b});
        }
    }
    show(SZ(ppairs));
    fore(i,0,SZ(ppairs)){
        cout<<ppairs[i].first<<" "<<ppairs[i].second<<'\n';
    }
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.