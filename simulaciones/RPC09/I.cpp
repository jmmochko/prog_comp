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
    int ds[3][6];
    fore(i,0,3)input(ds[i]);
    map<pii,double> gana;//prob de q i gana a j
    fore(i,0,3)fore(j,0,3){
        if(i==j)continue;
        double v = 0, p = 0;
        fore(c,0,6){
            fore(c2,0,6){
                if(ds[i][c]>ds[j][c2])++v;
                if(ds[i][c]<ds[j][c2])++p;
            }
        }
        if(v==0)gana[{i,j}] = 0;
        else if (p==0)gana[{i,j}] = 1;
        else gana[{i,j}] = v/(v+p);
    }
    fore(i,0,3){
        int cnt = 0;
        fore(j,0,3){
            if(i==j)continue;
            if(gana[{i,j}]>=0.50000)++cnt;
        }
        if(cnt==2){
            show(i+1);
            return 0;
        }
    }
    show("No dice");
    return 0;
}

//Sobrevivimos al pabellon