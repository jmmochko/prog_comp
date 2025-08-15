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
//robado xq es muy largo de codear
string s;
int res = 0;
ll setBit( ll vis,int x,int y ){
    int pos = x*7+y;
    return vis | (ll)1<<pos;
}
bool visited[7][7];
inline bool isVisited(int x,int y ){
    if( x< 0 or y<0 or x>=7 or y>=7  ) return true;
    return visited[x][y];
}
 
// L,R,U,D
void dfs(int x,int y,int pos){
    if( x == 6 and y == 0 and pos!=48 ) return;
    if( x == 6 and y == 0 and pos == 48){
        res++;
        return;
    }
    if( pos>=48 ) return;
    visited[x][y] = true;
    if( s[pos] == 'L' ){
        int tmpx = x;
        int tmpy = y-1;
        if( !isVisited(tmpx,tmpy) ){
            dfs(tmpx,tmpy,pos+1);
        }
    } else if( s[pos] == 'R' ){
        int tmpx = x;
        int tmpy = y+1;
        if( !isVisited(tmpx,tmpy) ){
            dfs(tmpx,tmpy,pos+1);
        }
    } else if( s[pos] == 'U' ){
        int tmpx = x-1;
        int tmpy = y;
        if( !isVisited(tmpx,tmpy) ){
            dfs(tmpx,tmpy,pos+1);
        }
    } else if( s[pos] == 'D' ){
        int tmpx = x+1;
        int tmpy = y;
        if( !isVisited(tmpx,tmpy) ){
            dfs(tmpx,tmpy,pos+1);
        }
    }else{
        if( !isVisited(x+1,y) and !isVisited(x-1,y) and isVisited(x,y+1) and isVisited(x,y-1) ) { visited[x][y] = false;return;}
        if( isVisited(x+1,y) and isVisited(x-1,y) and !isVisited(x,y+1) and !isVisited(x,y-1) ) { visited[x][y] = false;return;}
 
        if( !isVisited(x+1,y) ) dfs( x+1,y,pos+1);
        if( !isVisited(x-1,y) ) dfs( x-1,y,pos+1);
        if( !isVisited(x,y+1) ) dfs( x,y+1,pos+1);
        if( !isVisited(x,y-1) ) dfs( x,y-1,pos+1);
    }
    visited[x][y] = false;
}
 
int main(){
    int t = 1;
    FIN;
   // scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
       // s="????????????????????????????????????????????????";
        cin>>s;
        dfs(0,0,0);
        cout<<res<<endl;
    }
}

//Sobrevivmos al pabellon