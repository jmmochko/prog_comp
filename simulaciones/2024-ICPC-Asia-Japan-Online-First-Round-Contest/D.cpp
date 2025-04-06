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
#define MAXN 101
#define ALPH 26
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1ll<<61)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

map<pair<pll,ll>,pair<pair<pll,ll>,ll>> g;
map<pair<pll,ll>,bool> vis;
map<pair<pll,ll>,ll> dp; //tamaño del ciclo que arranca acá
pair<pll,ll> arrancaciclo = {{-1,-1},-1};

ll f(pair<pll,ll> actual){
    if(abs(actual.fst.fst)>=MAXll-1000)return MAXll;
    if(vis[actual]){arrancaciclo = actual;return 0;}
    vis[actual] = true;
    pair<pair<pll,ll>,ll> nxt = g[actual];
    ll res = nxt.snd + f(nxt.fst);
    dp[actual] = res;
    return res;
}

int main(){
    FIN;
    while(true){
        //tomar el input
        int n;
        cin>>n;if(n==0)break;
        ll a,b,d;
        cin>>a>>b>>d;
        g.clear();
        dp.clear();
        vector<pll> obs(n);
        fore(i,0,n){
            cin>>obs[i].fst>>obs[i].snd;
        }
        //armar grafo en forma de map[<posicion,direccion>] -> <<posicion,direccion>, costo>
        fore(i,0,MAXN)fore(j,0,MAXN){
            pll actual = {i,j};
            //derecha
            pll mejor = {MAXll,MAXll};
            fore(k,0,n){
                if(obs[k].snd==actual.snd && obs[k].fst>actual.fst && obs[k].fst<mejor.fst){
                    mejor = obs[k];
                }
            }
            mejor.fst--;
            g[{actual,0}] = {{mejor,1},abs(actual.fst-mejor.fst)};
            //arriba
            mejor = {MAXll,MAXll};
            fore(k,0,n){
                if(obs[k].fst==actual.fst && obs[k].snd>actual.snd && obs[k].snd<mejor.snd){
                    mejor = obs[k];
                }
            }
            mejor.snd--;
            g[{actual,1}] = {{mejor,2},abs(actual.snd-mejor.snd)};
            //izq
            mejor = {-MAXll,-MAXll};
            fore(k,0,n){
                if(obs[k].snd==actual.snd && obs[k].fst<actual.fst && obs[k].fst>mejor.fst){
                    mejor = obs[k];
                }
            }
            mejor.fst++;
            g[{actual,2}] = {{mejor,3},abs(actual.fst-mejor.fst)};
            //abajo
            mejor = {-MAXll,-MAXll};
            fore(k,0,n){
                if(obs[k].fst==actual.fst && obs[k].snd<actual.snd && obs[k].snd>mejor.snd){
                    mejor = obs[k];
                }
            }
            mejor.snd++;
            g[{actual,3}] = {{mejor,0},abs(actual.snd-mejor.snd)};
            fore(dd,0,4)vis[{actual,dd}] = false;
        }
        //precalculo de si hay un ciclo
        f({{a,b},0});
        //recorro hasta encontrar el ciclo o salirme
        pair<pll,ll> actual = {{a,b},0};
        while(d>0){
            if(actual==arrancaciclo)d = d%dp[arrancaciclo];
            pair<pair<pll,ll>,ll> nxt = g[actual];
            ll nd = d - nxt.snd;
            if(nd<=0){
                if(actual.snd == 0){
                    actual.fst.fst = actual.fst.fst + d;
                }
                if(actual.snd == 1){
                    actual.fst.snd = actual.fst.snd + d;
                }
                if(actual.snd == 2){
                    actual.fst.fst = actual.fst.fst - d;
                }
                if(actual.snd == 3){
                    actual.fst.snd = actual.fst.snd - d;
                }
                break;
            }
            d = nd;
            actual = nxt.fst;
        }
        cout<<actual.fst.fst<<" "<<actual.fst.snd<<'\n';
    }
    return 0;
}

//Cue "Eye of the Tiger"