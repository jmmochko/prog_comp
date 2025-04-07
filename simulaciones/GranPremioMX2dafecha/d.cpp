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

// f(i,s) = cantidad de pares numeros validos
// f(digito en el que estoy, diferencia de la suma de digitos que llevo hasta ahora s2-s1)
// f(800,800*9)

ll n;

ll dp[801][800*9+2];

ll f(ll i, ll s){
    if(dp[i][s]!=-1)return dp[i][s];
    //DGB(i);DGB(n);DGB(s);DGB(sposta);RAYA;
    dp[i][s] = 0;
    if(i==800){
        fore(d,0,10)fore(e,0,10)if(d!=e && e-d == s)dp[i][s]++;
        return dp[i][s]%M;
    }
    fore(d,0,10){//dgito que elijo poner el primero
        fore(e,0,10){//digito para el segundo
            if(e==d)continue;
            dp[i][s] += f(i+1,abs(s+e-d));
            dp[i][s] = dp[i][s]%M;
        }
    }
    return dp[i][s];
}

void solve(){
    cin>>n;
    ll res = 0;
    if(n==1){
        show(0);
        return;
    }
    fore(p,1,10)fore(k,1,10){//arranco desde i+1 para no poner 0s al principio
        if(k!=p)res += f(800-(n-2),abs(k-p));
        res = res%M;
    }
    show(res);
}

int main(){
    FIN;
    int t = 1;
    fore(i,0,801)fore(j,0,800*9+2)dp[i][j] = -1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"