#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) {cout<<i<<" ";cout<<"\n";}
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

vector<pii> Ds = {{0,1},{1,0},{-1,0},{0,-1}};
vector<pii> ADs = {{1,1},{-1,1},{1,-1},{-1,-1}};

void solve(){
    int n,m;
    char d1,d2;
    cin>>n>>m>>d1>>d2;
    vector<string> mat(n);
    input(mat);
    fore(i,0,n)fore(j,0,m){
        if(mat[i][j]=='V'){
            for(auto d: Ds){
                int ni = i + d.fst, nj = j + d.snd;
                if(ni>=0 && ni<n && nj >= 0 && nj<m){
                    if(mat[ni][nj]!='V'){
                        mat[ni][nj] = max(mat[ni][nj],d1);
                    }
                }
            }
            for(auto d: ADs){
                int ni = i + d.fst, nj = j + d.snd;
                if(ni>=0 && ni<n && nj >= 0 && nj<m){
                    if(mat[ni][nj]!='V'){
                        mat[ni][nj] = max(mat[ni][nj],d2);
                    }
                }
            }
        }
        else{
            mat[i][j] = max(mat[i][j],'0');
        }
    }
    showAll(mat);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    fore(i,1,t+1){cout<<"Airplane #"<<i<<':'<<'\n';solve();}
    return 0;
}

//El año que viene soy GOD