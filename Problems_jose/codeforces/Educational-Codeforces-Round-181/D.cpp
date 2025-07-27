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
#define M 998244353
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life
int n,m;
vector<pair<pll,pll>> rs;//<r,l>,<p,q>

ll pow(ll a, ll b){
    if(b==0){
        return 1;
    }
    ll medio = pow(a,b/2);
    if(b&1)return ((medio * medio)%M * a)%M;
    return (medio*medio)%M;
}

int main(){
    FIN;
    cin>>n>>m;
    fore(i,0,n){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        rs.pb({{b,a},{c,d}});
    }
    sort(all(rs));
    pll dp[m+1];//prob de que pase con rangos hasta exactamente i
    dp[0] = {1,1};
    int rango = 0;
    fore(i,1,m+1){
        int primerrango = rango;
        while(rango<n && rs[rango].fst.fst <= i)++rango;
        pll todosfalsos = {1,1};
        fore(k,primerrango,rango){
            ll p = rs[k].snd.fst,q = rs[k].snd.snd;
            todosfalsos.fst *= q;
            todosfalsos.snd *= p;
            todosfalsos = {todosfalsos.fst % M, todosfalsos.snd % M};
        }
        dp[i] = {0,0};
        fore(k,primerrango,rango){
            ll p = rs[k].snd.fst,q = rs[k].snd.snd;
            ll peste = ((todosfalsos.fst * p)%M * p)%M;
            ll qeste = ((todosfalsos.snd * q)%M *q)%M;
            if(dp[i].snd == 0){
                dp[i] = {peste,qeste};
            }
            else{
                ll muleste = dp[i].snd;
                ll mulotro = qeste;
                peste = (peste * muleste)%M;
                qeste = (qeste * muleste)%M;
                dp[i].fst = (dp[i].fst * mulotro)%M;
                dp[i].snd = (dp[i].snd * mulotro)%M;
                dp[i] = {(dp[i].fst + peste)%M,(dp[i].snd + qeste)%M};
            }
        }
    }
    fore(i,0,m+1){
        DGB(i);DGB(dp[i].fst);DGB(dp[i].snd);RAYA;
    }
    ll resEnum = dp[m].fst;
    ll resDen = pow(dp[m].snd,M-2);
    ll res = (resEnum * resDen)%M;
    DGB(resEnum);
    DGB(resDen);
    DGB(res);
    if(dp[m].fst == 0){
        show(0);
    }
    else show(res);
    return 0;
}

//Sobrevivimos al pabellon