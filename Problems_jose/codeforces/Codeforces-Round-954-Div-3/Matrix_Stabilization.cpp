//https://codeforces.com/problemset/problem/1986/B

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
int n,m;

bool can(int i, int j){
    if(i>=n || i<0 || j>=m || j<0){
        return false;
    }
    return true;
}

void solve(){
    
    cin>>n>>m;
    ll mat[n][m];
    fore(i,0,n){
        input(mat[i]);
    }
    fore(i,0,n){
        fore(j,0,m){
            ll aux = 0;
            if(can(i+1,j)){
                aux = max(mat[i+1][j],aux);
            }
            if(can(i-1,j)){
                aux = max(mat[i-1][j],aux);
            }
            if(can(i,j+1)){
                aux = max(mat[i][j+1],aux);
            }
            if(can(i,j-1)){
                aux = max(mat[i][j-1],aux);
            }
            mat[i][j] = min(aux,mat[i][j]);
        }
    }
    fore(i,0,n){
        showAll(mat[i]);
    }
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.