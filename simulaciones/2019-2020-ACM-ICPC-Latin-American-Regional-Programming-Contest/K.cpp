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

vector<ll> mp(vector<ll> &a,vector<ll> &b){
    ll sa = SZ(a);
    ll sb = SZ(b);
    
    vector<ll> res((sa-1)+(sb-1)+1,0);
    fore(i,0,sa){
        fore(j,0,sb){
            res[i+j] = res[i+j] + a[i] * b[j];
        }
    }

    return res;
}

int main(){
    FIN;
    string s; cin >> s;
    vector<vector<ll>> roots;

    fore(i,1,SZ(s)){
        if(s[i]!=s[i-1]){
             roots.pb({1,-(2*i+1)});
        }
    }

    ll n = SZ(roots);

    if(n==0){
        show(0);
        if(s[0]=='A') show(-1);
        else show(1);
        return 0;
    }
    vector<ll> aux = roots[0];
    fore(i,1,n){
        aux = mp(aux,roots[i]);
    }
    // chequear el valor del polinomio en 2
    reverse(all(aux));
    ll acc = aux[0];
    ll pot = 1;
    fore(i,1,SZ(aux)){
        acc +=  2*pot*aux[i];
        pot = 2*pot;
    }
    if(s[0]=='A' && acc > 0){
        // lo invierto
        fore(i,0,SZ(aux)){
            aux[i] = (-1ll) * aux[i];
        }
    } 
    else if(s[0]=='H' && acc < 0){
        //lo invierto
        fore(i,0,SZ(aux)){
            aux[i] = (-1ll) * aux[i];
        }
    }
    reverse(all(aux)); 
    show(n);
    showAll(aux);
    return 0;
}

//Sale regional?