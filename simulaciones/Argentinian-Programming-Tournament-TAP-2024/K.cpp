#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define all(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define show(a) cout<<a<<'\n'
#define showAll(a) for(auto b: a)cout<<b<<" ";cout<<'\n'
#define pb push_back
typedef long long ll;
using namespace std;

bool ist(ll i, ll j, vector<vector<char>> & mat){
    bool flag = true;
    if(mat[i][j]!='#') flag = false;
    if(mat[i-1][j]!='#') flag = false;
    if(mat[i-2][j]!='#') flag = false;
    if(mat[i-3][j]!='#') flag = false;
    if(mat[i-4][j]!='#') flag = false;
    if(mat[i-4][j-1]!='#') flag = false;
    if(mat[i-4][j]!='#') flag = false;
    if(mat[i-4][j+1]!='#') flag = false;

    return flag;
}

bool isa(ll i, ll j, vector<vector<char>> & mat){
    bool flag = true;
    if(mat[i][j]!='#') flag = false;
    if(mat[i-1][j]!='#') flag = false;
    if(mat[i-2][j]!='#') flag = false;
    if(mat[i-3][j]!='#') flag = false;
    if(mat[i-4][j]!='#') flag = false;
    if(mat[i][j+2]!='#') flag = false;
    if(mat[i-1][j+2]!='#') flag = false;
    if(mat[i-2][j+2]!='#') flag = false;
    if(mat[i-3][j+2]!='#') flag = false;
    if(mat[i-4][j+2]!='#') flag = false;
    if(mat[i-2][j+1]!='#') flag = false;
    if(mat[i-4][j+1]!='#') flag = false;

    return flag;
}

bool isp(ll i, ll j, vector<vector<char>> & mat){
    bool flag = true;
    if(mat[i][j]!='#') flag = false;
    if(mat[i-1][j]!='#') flag = false;
    if(mat[i-2][j]!='#') flag = false;
    if(mat[i-3][j]!='#') flag = false;
    if(mat[i-4][j]!='#') flag = false;
    if(mat[i-2][j+2]!='#') flag = false;
    if(mat[i-3][j+2]!='#') flag = false;
    if(mat[i-4][j+2]!='#') flag = false;
    if(mat[i-2][j+1]!='#') flag = false;
    if(mat[i-4][j+1]!='#') flag = false;
    
    return flag;
}

void vist(ll i,ll j, vector<vector<bool>> & vis){
    vis[i][j] = true;
    vis[i-1][j] = true;
    vis[i-2][j] = true;
    vis[i-3][j] = true;
    vis[i-4][j] = true;
    vis[i-4][j-1] = true;
    vis[i-4][j] = true;
    vis[i-4][j+1] = true;
    return;
}
void visa(ll i,ll j, vector<vector<bool>> & vis){
    vis[i][j] = true;
    vis[i-1][j] = true;
    vis[i-2][j] = true;
    vis[i-3][j] = true;
    vis[i-4][j] = true;
    vis[i][j+2] = true;
    vis[i-1][j+2] = true;
    vis[i-2][j+2] = true;
    vis[i-3][j+2] = true;
    vis[i-4][j+2] = true;
    vis[i-2][j+1] = true;
    vis[i-4][j+1] = true;

    return;

}

void visp(ll i,ll j, vector<vector<bool>> & vis){
    vis[i][j]  = true;
    vis[i-1][j]  = true;
    vis[i-2][j]  = true;
    vis[i-3][j] = true;
    vis[i-4][j] =  true;
    vis[i-2][j+2] = true;
    vis[i-3][j+2] = true;
    vis[i-4][j+2] = true;
    vis[i-2][j+1] = true;
    vis[i-4][j+1] = true;
    return;
}


int main(){
    FIN;
    ll n,m; cin >> n >> m;
    vector<vector<char>> mat(n,vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    ll t = 0, a = 0, p = 0;
    fore(i,0,n) fore(j,0,m) cin >> mat[i][j];
    for(int i = n-1; i>=0; i--){
        fore(j,0,m){
            if(mat[i][j] == '.'  || vis[i][j]) continue;

            if(isa(i,j,mat)){
                a++;
                visa(i,j,vis);
            } else if(isp(i,j,mat)){
                p++;
                visp(i,j,vis);
            }
            else{
                t++;
                vist(i,j,vis);
            }
        }
    }

    cout << t << " " << a << " " << p << "\n";


    return 0;
}