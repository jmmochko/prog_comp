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
    ifstream cin("class.in");
    ofstream cout("class.out");
    int n,r,c;
    cin>>n>>r>>c;
    char room[r][c];
    fore(i,0,r){
        fore(j,0,c){
            room[i][j] = '.';
        }
    }
    int am = n/2;
    fore(j,0,min(c,am)){
        room[0][j] = '#';
        --n;
    }
    fore(i,1,min(r,am)){
        room[i][0] = '#';
        --n;
    }
    if(am<r){
        room[am][0] = '#';
        --n;
    }
    fore(i,0,r){
        fore(j,0,c){
            if(room[i][j]!='#' && n>0){
                room[i][j]='#';
                --n;
            }
        }
    }
    int i=0,j=0;
    while(i<r && room[i][0]=='#'){
        ++i;
    }
    while(j<c && room[0][j]=='#'){
        ++j;
    }
    show(min(i,j));
    fore(ii,0,r){
        fore(jj,0,c){
            cout<<room[ii][jj];
        }
        cout<<'\n';
    }
    cin.close();
    cout.close();
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.