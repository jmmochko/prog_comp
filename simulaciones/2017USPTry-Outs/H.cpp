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

vector<char> Ds = {'N','E','S','O'};

void solve(){
    int a,b,x,y;
    char c;
    cin>>a>>b>>c>>x>>y;
    int u = a-x,v = b-y;
    int i = 0;
    while(Ds[i]!=c)++i;
    set<char> quiero;
    if(u>0)quiero.insert('O');
    else if(u<0) quiero.insert('E');
    if(v>0)quiero.insert('S');
    else if(v) quiero.insert('N');
    vector<string> res;
    while(!quiero.empty()){
        while(!quiero.count(Ds[i])){i = (i+1)%4;res.pb("D");}
        char dir = Ds[i];
        if(dir == 'E' || dir == 'O'){res.pb(to_string(abs(u)));}
        else {res.pb(to_string(abs(v)));}
        quiero.erase(dir);
    }
    show(SZ(res));
    fore(i,0,SZ(res)){
        if(res[i][0]=='D')show("D");
        else cout<<"A "<<res[i]<<'\n';
    }
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"