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
int n;
int color[1000][1000];

void fill(){
    queue<pii> q;
    q.push({0,0});
    int i=0,j=0;
    while(!q.empty()){
        i = q.front().fst;
        j = q.front().snd;
        q.pop();
        fore(k,1,3)fore(kk,1,3){
            if(k==kk)continue;
            int ni = i + k,nj = j + kk;
            if(!(ni<0 || nj<0 || ni>=n || nj>=n || color[ni][nj] != MAXINT)){
                color[ni][nj] = color[i][j] + 1;
                q.push({ni,nj});
            }
            ni = i - k,nj = j + kk;
            if(!(ni<0 || nj<0 || ni>=n || nj>=n || color[ni][nj] != MAXINT)){
                color[ni][nj] = color[i][j] + 1;
                q.push({ni,nj});
            }
            ni = i + k,nj = j - kk;
            if(!(ni<0 || nj<0 || ni>=n || nj>=n || color[ni][nj] != MAXINT)){
                color[ni][nj] = color[i][j] + 1;
                q.push({ni,nj});
            }
            ni = i - k,nj = j - kk;
            if(!(ni<0 || nj<0 || ni>=n || nj>=n || color[ni][nj] != MAXINT)){
                color[ni][nj] = color[i][j] + 1;
                q.push({ni,nj});
            }
        }
    }
}

int main(){
    FIN;
    cin>>n;
    fore(i,0,n)fore(j,0,n)color[i][j] = MAXINT;
    color[0][0] = 0;
    fill();
    fore(i,0,n){fore(j,0,n)cout<<color[i][j]<<" ";cout<<'\n';}
    return 0;
}

//Sobrevivimos al pabellon