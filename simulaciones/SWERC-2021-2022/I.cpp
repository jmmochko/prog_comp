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

int main(){
    FIN;
    int n,m;
    cin>>n>>m;
    vector<ll> casa(n),heladero(m),cercano(n);input(casa);input(heladero);
    fore(i,0,m)heladero[i]*=2;
    heladero.pb(MAXll);heladero.pb(-MAXll);
    sort(all(heladero));
    int i = 0;
    int pcasa = 0;
    fore(c,0,n){
        while(heladero[i]<pcasa)++i;
        cercano[c] = min(abs(heladero[i-1]-pcasa),abs(heladero[i]-pcasa));
        if(cercano[c] == 0)cercano[c] = -1;
        pcasa += 200;
    }
    i = 0;
    int j = 0;ll estoy = cercano[0]-1, res = 0, cur = 0;
    while(j<n){
        //pruebo avanzar el j
        if(cercano[j] == -1){
            ++j;
            i=j;
            cur=0;
            continue;
        }
        if(cercano[j] >= abs(j*200 - estoy)){
            cur += casa[j];
            res = max(res,cur);
            ++j;
            continue;
        }
        cur += casa[j];
        estoy = j*200 - cercano[j] + 1;
        while(cercano[i] < abs(i*200-estoy)){
            cur -= casa[i];
            ++i;
        }
        res = max(res,cur);
        ++j;
    }
    show(res);
    return 0;
}

//Returneamos al pabellón