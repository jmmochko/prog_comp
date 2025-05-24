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
#define MAXN 100005
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

int crear[MAXN],NCrear[MAXN],borre[MAXN];//el n-esimo crear está en el nodo NCrear[i]
bool tipo[MAXN];
vector<int> tree[MAXN];

void llenar(int u, int cntE, int cntD){
    if(u==0){
        crear[0] = MAXINT;
    }
    else if(tipo[u]){
        cntE++;
        NCrear[cntE] = u;
    }
    else{
        cntD++;
        borre[u] = crear[NCrear[cntD]];
    }
    for(auto v: tree[u]){
        llenar(v,cntE,cntD);
    }
}

int main(){
    //FIN;
    int q;
    cin>>q;
    fore(i,1,q+1){
        char t;
        cin>>t;
        int v;
        cin>>v;
        if(t=='E'){
            tipo[i] = true;
            int x;
            cin>>x;
            crear[i] = x;
        }
        else{
            tipo[i] = false;
        }
        tree[v].pb(i);
    }
    llenar(0,0,0);
    fore(i,1,q+1){
        if(!tipo[i])show(borre[i]);
    }
    return 0;
}

//Cue "Eye of the Tiger"