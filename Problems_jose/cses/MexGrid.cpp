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
    int n;
    cin>>n;
    int res[n][n];
    fore(i,0,n)fore(j,0,n)res[i][j] = 0;
    set<int> filas[n],columnas[n];
    fore(i,0,n)fore(j,0,n){
        fore(k,0,n*n){
            if(!filas[i].count(k) && !columnas[j].count(k)){
                res[i][j] = k;
                filas[i].insert(k);
                columnas[j].insert(k);
                break;
            }
        }
    }
    fore(i,0,n){showAll(res[i]);}
    return 0;
}

//Sobrevivimos al pabellon

// 0 1 2 3
// 1 0 3
// 2 3 0
// 3     0