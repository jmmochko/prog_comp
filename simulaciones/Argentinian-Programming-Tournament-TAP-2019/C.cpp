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

ll n,m;

bool valid(ll i, ll j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

vector<pair<ll, ll>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// void cont(vector<vector<char>> &mat, ll i, ll j, vector<vector<bool>> &vis){
//     vis[i][j] = true;
//     for (auto [di, dj] : dir) {
//         ll ni = i + di, nj = j + dj;
//         if (valid(ni, nj) && mat[ni][nj] == '*' && !vis[ni][nj]) {
//             cont(mat,ni,nj,vis);
//         }
//     }
// }

void cont(vector<vector<char>> &mat, ll i, ll j, vector<vector<bool>> &vis){
    queue<ii> q;
    vis[i][j] = true;
    q.push({i,j});
    while(!q.empty()){
        auto [i,j] = q.front();
        q.pop();

        for (auto [di, dj] : dir) {
            ll ni = i + di, nj = j + dj;
            if(valid(ni,nj)){
                if(!vis[ni][nj] && mat[i][j]=='*'){
                    vis[ni][nj] = true;
                    q.push({ni,nj});
                }
            }
        }
    }
}

int main(){
    FIN;
    
    cin >> n >> m;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<char>> mat(n, vector<char>(m));
	fore(i,0,n){
		fore(j,0,m){
            cin >> mat[i][j];
        }
	}

    ll res = 0;
    fore(i,0,n-1) fore(j,1,m-1){
        // si no es un * lo paso
        if(mat[i][j]=='.') continue;

        // si ya visite un * => ya analize su conjunto
        if(vis[i][j]) continue;

        // Encontramos un *, => es uno de arriba
        ll primer_i = i;
        ll ultimo_i = i;
        ll contador_izq = 0, contador_der = 0;
        ll pos_izq = -1, pos_der = -2;

        while(ultimo_i < n && mat[ultimo_i][j]=='*'){
            if(j>0){
                if(mat[ultimo_i][j-1]=='*'){
                    contador_izq++;
                    pos_izq = ultimo_i;
                }
            }
            if(j<m-1){
                if(mat[ultimo_i][j+1]=='*'){
                    contador_der++;
                    pos_der = ultimo_i;
                }
            }

            ultimo_i++;
        }
        // me fijo el ultimo estado del ultimo i
        while(ultimo_i>=n)ultimo_i--;
        if(mat[ultimo_i][j] == '.') ultimo_i--;
        ll i_central = pos_izq;

        //tenemos que ver que exista solo 1 * a la izq y 1 a la der y esten en la misma posicion
        if(contador_izq != 1 || contador_der != 1 || pos_izq != pos_der){
            // si no marcamos todos como visitados y continuamos
            cont(mat,i,j,vis);
            continue;
        }

        // veamos que si tiene una forma valida, la distancia del cental al primero sea < que la distancia del central al ultimo
        ll d1 = i_central - primer_i;
        ll d2 = ultimo_i - i_central;

        if(d1 >= d2 ){
            // si no marcamos todos como visitados y continuamos
            cont(mat,i,j,vis);
            continue;
        }

        //ahora veamos que los brazos contengan . a su alrededor y tengan el mismo largo que d1
        ll contador_brazo_izq = 0;
        ll contador_brazo_der = 0;

        ll brazo_izq = j-1;
        ll brazo_der = j+1;

        //usamos el flag para ver si lo rodea algun * al brazo
        bool flag = false;
        while(brazo_izq >= 0 && mat[i_central][brazo_izq] == '*'){
            // chequeo arriba
            if(i_central>0){
                if(mat[i_central-1][brazo_izq] == '*'){
                    flag = true;
                    break;
                }
            }

            // chequeo abajo
            if(i_central<n-1){
                if(mat[i_central+1][brazo_izq] == '*'){
                    flag = true;
                    break;
                }
            }

            contador_brazo_izq++;
            brazo_izq--;
        }

        if(flag){
            cont(mat,i,j,vis);
            continue;
        }

        while(brazo_der < m && mat[i_central][brazo_der] == '*'){
            // chequeo arriba
            if(i_central>0){
                if(mat[i_central-1][brazo_der] == '*'){
                    flag = true;
                    break;
                }
            }

            // chequeo abajo
            if(i_central<n-1){
                if(mat[i_central+1][brazo_der] == '*'){
                    flag = true;
                    break;
                }
            }

            contador_brazo_der++;
            brazo_der++;
        }

        if(flag){
            cont(mat,i,j,vis);
            continue;
        }

        if(contador_brazo_izq != d1 || contador_brazo_der != d1){
            cont(mat,i,j,vis);
            continue;
        }

        // todo los errores fueron chequeados, sumamos una cruz valida
        res++;
        cont(mat,i,j,vis);
    }

    show(res);
}
