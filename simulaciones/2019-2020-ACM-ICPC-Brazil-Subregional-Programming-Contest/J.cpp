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

string cartas = "A23456789DQJK";

int main(){
    //FIN;
    int n,k;
    cin>>n>>k;
    --k;
    vector<multiset<int>> cr(n);
    map<char,int> pos;
    fore(i,0,SZ(cartas))pos[cartas[i]] = i;
    fore(i,0,n){
        fore(k,0,4){
            char a;
            cin>>a;
            cr[i].insert(pos[a]);
        }
    }
    cr[k].insert(100);
    bool paso = false;
    int ganador = -1;
    //int ppp = 0;
    fore(p,0,n){
        fore(i,0,SZ(cartas)){
            if(cr[p].count(i)==4 && SZ(cr[p])==4){
                ganador = p;
            }
        }
        if(ganador != -1)break;
    }
    while(1){
        //DGB(k);
        //showAll(cr[k]);
        //elijo carta player k
        fore(i,0,SZ(cartas)){
            if(cr[k].count(i)==4 && SZ(cr[k])==4){
                ganador = k;
            }
        }
        if(ganador != -1)break;
        int card;
        bool flag = false;
        if(paso && cr[k].count(100)){
            card = 100;flag = true;
        }
        else{
            int mn = 20;
            fore(i,0,SZ(cartas)){
                if(cr[k].count(i)<mn && cr[k].count(i)){
                    mn = cr[k].count(i);
                    card = i;
                }
            }
        }
        if(cr[k].count(100))paso = true;
        auto it = cr[k].find(card);
        cr[k].erase(it);
        fore(i,0,SZ(cartas)){
            if(cr[k].count(i)==4 && SZ(cr[k])==4){
                ganador = k;
            }
        }
        //DGB(card);
        //RAYA;
        if(ganador != -1)break;
        ++k;
        if(k>=n)k-=n;
        cr[k].insert(card);
        if(card==100)paso = false;
        //++ppp;
    }
    show(ganador + 1);
    return 0;
}

//Sobrevivimos al pabellon