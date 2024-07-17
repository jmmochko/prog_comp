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
    int n,m,k,u,v;
    cin>>n>>m>>k;
    vector<vector<int>> g(n);
    vector<int> in(n,0);//in degree of edge i
    fore(i,0,m){
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        in[v]++;
    }
    showAll(in);
    vector<int> in0,out0;
    fore(i,0,n){
        if(SZ(g[i])==0)out0.push_back(i);
        if(in[i]==0)in0.push_back(i);
    }
    int i = n-1;
    vector<pii> ppairs;

    show(SZ(ppairs));
    fore(i,0,SZ(ppairs))cout<<ppairs[i].first<<" "<<ppairs[i].second<<'\n';
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.