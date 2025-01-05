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
    string sb;
    ll a,b,la,lb;
    cin>>la>>lb>>a>>sb;
    b = stoi(sb);
    pll x,y;//(n,d)
    x.fst = a;
    ll cmp = 1;
    fore(k,0,la){
        cmp*=10;
    }
    x.snd = cmp;

    ll lb10 = 1;
    fore(k,0,lb){
        lb10*=10;
    }

    int kk = 0;
    ll kkcmp = 1;
    while(kk<SZ(sb) && sb[kk] == '0'){
        kkcmp*=10;
        ++kk;
    }

    ll nb = b*lb10;

    b = nb;
    
    y.fst = b;
    y.snd = (lb10 - 1)*(cmp*10);

    ll den = y.snd * x.snd,num = (x.fst*y.snd) + (y.fst*x.snd);

    while(gcd(num,den)>1){
        ll coso = gcd(num,den);
        den/=coso;
        num/=coso;
    }

    cout<<num<<" "<<den<<'\n';
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//LEOOOOOOOOOOOOOOOOOOOOOOOOOOOOO