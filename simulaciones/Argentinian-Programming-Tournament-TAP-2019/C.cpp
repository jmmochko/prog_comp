#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
    FIN;
    ll n,m; cin >> n >> m;
    vector<vector<bool>> vis(n,vector<bool>(m));
    vector<vector<char>> mat(n, vector<char>(m));
	fore(i,0,n){
		fore(j,0,m){
            cin >> mat[i][j];
        }
	}

    ll res = 0;
    fore(i,0,n) fore(j,0,m){
        if(mat[i][j]=='.') continue;
        else{
            if(vis[i][j]) continue;
            ll u = 0,l = 0, d = 0, r = 0;
            bool flag;

            flag = false;
            // cehqueo para izquierda
            ll auxj = j-1;
            while(auxj>=0 && mat[i][auxj]=='*'){
                if(i!=0 && i!=n-1){
                    if(mat[i-1][auxj]=='*' || mat[i+1][auxj]=='*') flag = true;
                }
                l++;
                auxj--;
            }
            if(flag) continue;
            if(l==0) continue;

            flag = false;
            // cehqueo para derecha
            auxj = j+1;
            while(auxj<m && mat[i][auxj]=='*'){
                if(i!=0 && i!=n-1){
                    if(mat[i-1][auxj]=='*' || mat[i+1][auxj]=='*') flag = true;
                }
                r++;
                auxj++;
            }

            if(flag) continue;
            if(l != r)continue;
            // l y r son iguales

            flag = false;
            // chequeo para arriba
            ll auxi = i-1;
            while(auxi>=0 && mat[auxi][j]=='*'){
                if(j!= 0 && j != m-1){
                    if(mat[auxi][j-1]=='*' || mat[auxi][j+1]=='*') flag = true;
                }
                u++;
                auxi--;
            }

            if(flag) continue;
            if(u != l) continue;

            flag = false;

            // chequeo para abajo
            auxi = i+1;
            while(auxi<n && mat[auxi][j]=='*'){
                if(j!= 0 && j != m-1){
                    if(mat[auxi][j-1]=='*' || mat[auxi][j+1]=='*') flag = true;
                }
                d++;
                auxi++;
            }

            if(flag) continue;
            if(d>u){
                res++;
                // marcar visitados los *
                fore(hi,i-u,i+d+1) vis[hi][j] = true;
                fore(hj,j-l,j+r+1) vis[i][hj] = true;
            }

        }
    }

    show(res);
}
