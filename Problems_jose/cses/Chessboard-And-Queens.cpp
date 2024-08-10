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

vector<string> b(8);
int cnt = 0;

void mark(int i, int j, char e){
    fore(k,1,8-i){
        if(b[i+k][j]=='.')b[i+k][j] = e;
        if(j+k<8 && b[i+k][j+k]=='.')b[i+k][j+k] = e;
        if(j-k>=0 && b[i+k][j-k]=='.')b[i+k][j-k] = e;
    }
}

void unmark(char e){
    fore(i,0,8)fore(j,0,8)if(b[i][j]==e)b[i][j]='.';
}

void place_row(int i, char e){
    if(i==8){
        ++cnt;
        return;
    }
    fore(j,0,8){
        if(b[i][j]=='.'){
            mark(i,j,e);
            place_row(i+1,e+1);
            unmark(e);
        }
    }
}

void solve(){
    input(b);
    place_row(0,'a');
    show(cnt);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo
