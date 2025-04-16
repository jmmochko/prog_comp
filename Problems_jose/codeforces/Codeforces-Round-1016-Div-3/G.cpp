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

struct SearchTree{
    vector<pair<int,vector<int>>> tree;
    void init(){
        tree.push_back({MAXINT,{}});
    }
    void add(int num){
        int p = 0;
        fore(i,0,31){
            int ahora = num&(1<<30-i);
            int nxt = SZ(tree);
            for(auto e: tree[p].snd){
                if(tree[e].fst==ahora)nxt = e;
            }
            if(nxt==SZ(tree)){
                tree.push_back({ahora,{}});
            }
            tree[p].snd.pb(nxt);
            p = nxt;
        }
    }
    int query(int num){//returns res such that res +
        int p = 0;
        int res = 0;
        fore(i,0,31){
            int ahora = num&(1<<30-i);
            int nxt = tree[p].snd[0];
            for(auto e: tree[p].snd){
                if(tree[e].fst!=ahora)nxt = e;
            }

        }
    }
};


void solve(){
    int n,k;
    cin>>n>>k;

}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"