#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

ll n,m;


int main(){
    FIN;
    //ifstream cin("lucky.in");
    //ofstream cout("lucky.out");

    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    fore(i,0,n) fore(j,0,m) cin >> a[i][j];

    ll res = 0;
    
    fore(i,0,n) fore(j,0,m) {
        bool l = false,u = false,d = false,r = false;
        // chequeo bordes
        if(i==0){
             l = true; res++;
        }
        else if(i==n-1){
            r = true; res++;
        }

        if(j==0){
            u = true; res++;
        }
        else if(j==m-1){
            d = true; res++;
        }

        // si no estoy en un borde busco para la izquirda
        if(!l){
            bool ag = true;
            ll iaux = i;
            while(iaux>0 && ag){
                if(a[iaux-1][j] <= a[i][j]) ag = false;
                iaux--;
            }
            if(ag) res++;
        }

        // si no estoy en un borde busco para la derecha
        if(!r){
            bool ag = true;
            ll iaux = i;
            while(iaux<n-1 && ag){
                if(a[iaux+1][j] <= a[i][j]) ag = false;
                iaux++;
            }
            if(ag) res++;
        }

        // si no estoy en un borde busco para arriba
        if(!u){
            bool ag = true;
            ll jaux = j;
            while(jaux>0 && ag){
                if(a[i][jaux-1] <= a[i][j]) ag = false;
                jaux--;
            }
            if(ag) res++;
        }

        // si no estoy en un borde busco para abajo
        if(!d){
            bool ag = true;
            ll jaux = j;
            while(jaux<m-1 && ag){
                if(a[i][jaux+1] <= a[i][j]) ag = false;
                jaux++;
            }
            if(ag) res++;
        }

    }

    cout << res << "\n";
    //cin.close();
    //cout.close();
}

// GRACIAS DURAN.