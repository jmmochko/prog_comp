#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i+1<<" ";
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 501
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

int modk(int a,int k){
    if(a<0)a+=k;
    return a%k;
}

void solve(){
    int n,t;
    cin>>n>>t;
    vector<int> rows(n),cols(n);
    fore(i,0,n){
        rows[i] = i;
        cols[i] = i;
    }
    fore(i,0,t){
        char e;
        int x,y;
        cin>>e>>x>>y;
        --x;--y;
        if(e=='R'){
            swap(rows[x],rows[y]);
        }
        else{
            swap(cols[x],cols[y]);
        }
    }

    vector<vector<int>> rowcyc, colcyc;
    // construct row cycles
    vector<bool> vis(n,false);
    fore(i,0,n){
        if(vis[i])continue;
        vis[i] = true;
        vector<int> cyc = {i};
        int cur = rows[i];
        while(cur!=cyc[0]){
            cyc.pb(cur);
            vis[cur] = true;
            cur = rows[cur];
        }
        rowcyc.pb(cyc);
    }
    // construct col cycles
    fore(i,0,n)vis[i] = false;
    fore(i,0,n){
        if(vis[i])continue;
        vis[i] = true;
        vector<int> cyc = {i};
        int cur = cols[i];
        while(cur!=cyc[0]){
            cyc.pb(cur);
            vis[cur] = true;
            cur = cols[cur];
        }
        colcyc.pb(cyc);
    }
    //check if answer exists
    if(SZ(colcyc)!=SZ(rowcyc)){
        show('*');
        return;
    }
    int k = SZ(colcyc[0]);
    fore(i,0,SZ(colcyc)){
        if(SZ(colcyc[i])!=k || SZ(rowcyc[i])!=k){
            show('*');
            return;
        }
    }
    //construct ans
    int res[n][n];
    fore(cycr,0,SZ(rowcyc)){
        fore(cycc,0,SZ(colcyc)){
            vector<int> newrows = rowcyc[cycr], newcols = colcyc[cycc];
            int offset = (cycr + cycc)%(n/k);
            fore(i,0,k)fore(j,0,k){
                res[newrows[i]][newcols[j]] = (offset*k) + (modk((i-j),k));
            }
        }
    }
    fore(i,0,n){showAll(res[i]);cout<<'\n';}
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//El año que viene soy GOD