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
    ll l,r,g;
    cin>>l>>r>>g;
    ll left = (l/g) + (bool)(l%g);
    ll right = (r/g);
    int i = 0;
    bool flag = true;
    while(flag){
        fore(k,0,i+1){
            if(gcd(left+k,right-(i-k))==1){
                if(right-(i-k)<left)cout<<-1<<" "<<-1<<'\n';
                else cout<<(left+k)*g<<" "<<(right-(i-k))*g<<'\n';
                flag = false;
                break;
            }
        }
        ++i;
    }
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"