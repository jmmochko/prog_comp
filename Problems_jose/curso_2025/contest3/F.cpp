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
string a,b;
ll mod,D;

ll dpa[2001][2001][2];
ll dpb[2001][2001][2];

ll fa(int i, ll j, int l){
    if(dpa[i][j][l]!=-1)return dpa[i][j][l];
    dpa[i][j][l] = 0;
    int d = a[i] - '0';
    bool par = (SZ(a) - i)%2 == 0;
    if(i==0){
        fore(e,0,10){
            DGB(e);
            if(l && d<e)break;
            if(par && d != D)continue;
            if(!par && d == D)continue;
            if(e%mod == j)++dpa[i][j][l];
        }
        return dpa[i][j][l];
    }
    return dpa[i][j][l];
}

ll fb(int i, ll j, int l){
    if(dpb[i][j][l]!=-1)return dpb[i][j][l];
    dpb[i][j][l] = 0;
    int d = b[i] - '0';
    bool par = (SZ(b) - i)%2 == 0;
    if(i==0){
        fore(e,0,10){
            DGB(e);
            if(l && d<e)break;
            if(par && d != D)continue;
            if(!par && d == D)continue;
            if(e%mod == j)++dpb[i][j][l];
        }
        return dpb[i][j][l];
    }
    return dpb[i][j][l];
}

int main(){
    FIN;
    cin>>mod>>D;
    cin>>a>>b;
    fore(i,0,2001)fore(j,0,2001)fore(t,0,2){dpa[i][j][t] = -1;dpb[i][j][t] = -1;}
    show(fb(SZ(a)-1,mod,true)-fa(SZ(a)-1,mod,true));
    return 0;
}

//Cue "Eye of the Tiger"