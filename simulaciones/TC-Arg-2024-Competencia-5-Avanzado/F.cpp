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

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> subs(m);
    fore(i,0,n){
        ll s,r;
        cin>>s>>r;
        subs[s-1].push_back(-r);
    }
    ll res = 0,maxm=0;
    fore(i,0,m){
        maxm=max(maxm,(ll)SZ(subs[i]));
        sort(all(subs[i]));
    }
    vector<vector<ll>> subsV(m);
    vector<pii> ord(m);
    fore(i,0,m)subsV[i].push_back(0);
    fore(i,0,m){
        ord[i].first = SZ(subs[i]);
        ord[i].second = i;
        fore(j,0,SZ(subs[i])){
            subsV[i].push_back(subsV[i][SZ(subsV[i])-1]+subs[i][j]);
        }
    }
    sort(all(ord));
    int i = 0,j = 0;
    while(j<m){
        while(i<ord[j].first){
            ll cur = 0;
            fore(k,j,m){
                if(subsV[ord[k].second][i+1]<0)cur-=subsV[ord[k].second][i+1];
            }
            res = max(res,cur);
            ++i;
        }
        ++j;
    }
    show(res);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Escuchen, corran la bola...