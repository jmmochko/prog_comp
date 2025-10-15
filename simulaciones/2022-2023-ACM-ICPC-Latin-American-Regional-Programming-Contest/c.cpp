#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst frist
#define snd second
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;

bool mitad(ll estoy, ll n){//true if arriba
    if(estoy >= (1ll<<n-1))return true;
    return false;
}

string res;

vector<int> estoys;

void primer(ll estoy, int n){
    while(n>1){
        ll d = min(abs((1ll<<n)- 1 - estoy), estoy);
        if(mitad(estoy,n) && mitad(estoy%(1ll<<(n-1)),n-1)){
            //estaba abajo
            estoy = min(d, (1ll<<(n-1)-d));
            estoys.push_back(0);
        }
        else if(!mitad(estoy,n) && !mitad(estoy%(1ll<<(n-1)),n-1)){
            //estaba abajo
            estoy = d;
            estoys.push_back(0);
        }
        else if(mitad(estoy,n) && !mitad(estoy%(1ll<<(n-1)),n-1)){
            //estaba arriba
            estoy = abs(estoy-(1ll<<n-1));
            estoys.push_back(1);
        }
        else if(!mitad(estoy,n) && mitad(estoy%(1ll<<(n-1)),n-1)){
            //estaba arriba
            estoy = abs(estoy-(1ll<<n-1));
            estoys.push_back(1);
        }
        n-=1;
    }
}

int main(){
    FIN;
    int n,p,h;
    cin>>n>>p>>h;
    --p;--h;
    estoys.push_back(!mitad(p,n));
    primer(p,n);
    reverse(ALL(estoys));
    int ni = n;
    fore(i,0,ni){
        bool estoy_derecha = p >= (1<<n-1);
        if(!estoys[i]){
            if(estoy_derecha){ // HICE UN RIGHT
                cout<<'R';
                p = (1ll<<n) - p - 1;
            }
            else{ // HICE UN LEFT
                cout<<'L';
                p = (1ll<<n-1)-1-p;
            }
        } 
        else{
            if(estoy_derecha){ // HICE UN LEFT
                cout<<"L";
                p = p - (1ll<<(n-1));
            }
            else{ // HICE UN RIGHT
                cout<<"R";
            }
        }
        --n;
    }
    
    return 0;
}