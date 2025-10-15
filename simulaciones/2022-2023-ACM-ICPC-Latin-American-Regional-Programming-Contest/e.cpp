#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst frist
#define snd second
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;

int main(){
    FIN;
    ll a,b,c;
    ll n; cin >> n >> b >> a;
    ll mid = b, izq = a;
    ll der = n-b-a;
    vector<bool> tiles(n+1), tiles2(n+1);
    tiles[mid] = true;
    tiles2[mid] = true;
    ll res = n-mid, res2 = n - mid;
    
    // intento llenar la izq primero
    if(tiles[izq]){
        bool flag = true;
        fore(i,1,izq){
        ll j = izq - i;
        if(i==j) continue;
        if(!tiles[i] && !tiles[j]){
            res -= (i+j);
            tiles[i] = true;
            tiles[j] = true;
            // cout << "res:" << res <<" "<<i<<" "<< j << "\n";
            flag = false;
            break;
        }
        }
        if(flag){ // busco alguno que entre
            for(ll i = izq-1; i>0; i--){
                if(i>izq) continue;
                if(!tiles[i]){
                    tiles[i] = true;
                    res -= i;
                    izq-=i;
                }
            }
        }

    } else{
        tiles[izq] = true;
        res-=izq;
    }

    // ahora la der
    if(tiles[der]){
        bool flag = true;
        fore(i,1,der){
        ll j = der - i;
        if(i==j) continue;
        if(!tiles[i] && !tiles[j]){
            res -= (i+j);
            tiles[i] = true;
            tiles[j] = true;
            flag = false;
            break;
        }
        }
        if(flag){ // busco alguno que entre
            for(ll i = der-1; i>0; i--){
                if(i>der) continue;
                if(!tiles[i]){
                    tiles[i] = true;
                    res -= i;
                    der-=i;
                }
            }
        }

    } else{
        tiles[der] = true;
        res-=der;
    }
    

    // ===========================
    // intento la der primero
    mid = b, izq = a;
    der = n-b-a;
    if(tiles2[der]){
        bool flag = true;
        fore(i,1,der){
        ll j = der - i;
        if(i==j) continue;
        if(!tiles2[i] && !tiles2[j]){
            res2 -= (i+j);
            tiles2[i] = true;
            tiles2[j] = true;
            flag = false;
            break;
        }
        }
        if(flag){ // busco alguno que entre
            for(ll i = der-1; i>0; i--){
                if(i>der)continue;
                if(!tiles2[i]){
                    tiles2[i] = true;
                    res2 -= i;
                    der-=i;
                }
            }
        }

    } else{
        tiles2[der] = true;
        res2-=der;
    }

     // ahora la izq
    if(tiles2[izq]){
        bool flag = true;
        fore(i,1,izq){
        ll j = izq - i;
        if(i==j) continue;
        if(!tiles2[i] && !tiles2[j]){
            res2 -= (i+j);
            tiles2[i] = true;
            tiles2[j] = true;
            // cout << "res:" << res <<" "<<i<<" "<< j << "\n";
            flag = false;
            break;
        }
        }
        if(flag){ // busco alguno que entre
            for(ll i = izq-1; i>0; i--){
                if(i>izq) continue;
                if(!tiles2[i]){
                    tiles2[i] = true;
                    res2 -= i;
                    izq-=i;
                }
            }
        }

    } else{
        tiles2[izq] = true;
        res2-=izq;
    }


    cout << min(res,res2) << "\n";


}