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

bool mat[100][100];

int main(){
    FIN;
    int n;
    cin>>n;
    fore(_,0,n){
        int d,l,r,c;
        cin>>d>>l>>r>>c;
        if(d==0){
            if(c+l-1>10){
                show("N");
                return 0;
            }
            fore(i,c,c+l){
                if(mat[r][i]){
                    show("N");
                    return 0;
                }
                mat[r][i] = true;
            }
        }
        else{
            if(r+l-1>10){
                show("N");
                return 0;
            }
            fore(i,r,r+l){
                if(mat[i][c]){
                    show("N");
                    return 0;
                }
                mat[i][c] = true;
            }
        }
    }
    show("Y");
    return 0;
}

//Sobrevivimos al pabellon