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

// f(i,s,k) = cantidad de pares numeros validos
// f(digito en el que estoy, quiero sumar con los que quedan del segundo, el primero tiene en esa posicion)
// f(800,800*9,10)

int n;

int dp[800][2*(791*9)][10];

int f(int i, int s, int k){
    //digito que elijo poner
    //DGB(i);DGB(s);DGB(k);RAYA;
    if(dp[i][s][k]!=-1)return dp[i][s][k];
    int sposta = s-(791*9);
    if(i==n-1){
        if(k==sposta || sposta>9 || sposta<0)return 0;
        return 1;
    }
    dp[i][s][k] = 0;
    fore(d,0,10){//dgito que elijo poner el el segundo
        if(d==k)continue;
        fore(nk,0,10){//dgito que elijo poner en la prox pos del primero
            dp[i][s][k] += f(i+1,(s-d)+nk,nk);
            dp[i][s][k] = dp[i][s][k]%M;
        }
    }
    dp[i][s][k];
    return dp[i][s][k];
}

void solve(){
    cin>>n;
    int res = 0;
    fore(i,0,n)fore(j,0,2*791*9)fore(k,0,10)dp[i][j][k] = -1;
    fore(p,1,10)fore(k,1,10)fore(sp,0,10){//arranco desde i+1 para no poner 0s al principio
        if(k!=p)res += f(1,(791*9)+p+sp-k,sp);
        res = res%M;
    }
    show(res);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"