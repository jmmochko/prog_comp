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

string n;

ll dp[18][(18*9)+1][2];

ll f(ll i, ll s, ll l){// cantidad de numeros que arrancan en la posiscion i, suma de digitos es s y estan limitados por n[i] sii l
    ll d = n[i]-'0';
    if(s<0)return 0;
    if(i==SZ(n)-1){
        if(l){
            if(s<=d)return 1;
            else return 0;
        }
        if(s<=9)return 1;
        else return 0;
    }
    if(dp[i][s][l]!=-1)return dp[i][s][l];
    dp[i][s][l]=0;
    if(l){
        fore(k,0,d){
            dp[i][s][l] += f(i+1,s-k,0);
        }
        dp[i][s][l] += f(i+1,s-d,1);
        return dp[i][s][l];
    }
    fore(k,0,10)dp[i][s][l] += f(i+1,s-k,0);
    return dp[i][s][l];
}

ll pos_de_K(ll k){
    // sea c = #numeros con suma de digitos < a digSum(k)
    // sea p = posicion de k entre los numeros con su misma suma
    // devolver c + p
    string kstr = to_string(k);
    ll s = 0,res = 0;
    fore(i,0,SZ(kstr))s += kstr[i]-'0';
    fore(i,1,s){
        res += f(0,i,1);
    }

    ll offset = SZ(n) - SZ(kstr);
    fore(i,0,SZ(kstr)-1){
        fore(d,0,kstr[i]-'0')res += f(offset+i+1,s-d,0);
        s -= kstr[i]-'0';
    }
    return res + 1;
}

ll posK(ll k){
    ll s = 1;
    while(k - f(0,s,true) >= 0){
        k -= f(0,s,true);
        ++s;
    }
    // ahora la respuesta es el k-esimo numero con suma s
    vector<ll> res(SZ(n));
    ll l = 1;
    fore(i,0,SZ(n)-1){
        //mientras poner este digito me dé menos opciones que k, trato de poner el siguiente
        ll d = 0;
        while(k - f(i+1,s-d, l && d==n[i]-'0') >= 0){
            k -= f(i+1,s-d, l && d==n[i]-'0');
            ++d;
        }
        if(d<f(i+1,s-d, l && d==n[i]-'0'))l = 0;
        res[i] = d;
        s -= d;
    }
    res[SZ(n)-1] = s;
    ll fnl = 0;
    ll pot = 1;
    dfore(ii,SZ(res)-1,0){
        fnl += res[ii]*pot;
        pot*=10;
    }
    return fnl;
}

void solve(){
    ll k;
    cin>>n>>k;
    fore(i,0,18){
        fore(j,0,18*9+1){
            fore(l,0,2){
                dp[i][j][l] = -1ll;
            }
        }
    }
    ll res1 = pos_de_K(k);
    ll res2 = posK(k-1);
    cout<<res1<<" "<<res2<<'\n';
}

int main(){
    //FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"
