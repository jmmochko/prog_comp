//https://codeforces.com/contest/1986/problem/E

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

ll n,k;

ll solve_group(vector<ll> &group){
    sort(all(group));
    if(SZ(group)%2==0){
        ll res = 0;
        for(int i = 0; i<SZ(group); i+=2){
            res += group[i+1]-group[i];
        }
        return res;
    }
    if(SZ(group)==1)return 0;
    vector<ll> prefev(1,0), prefodd(1,0);
    for(int i = 0; i<SZ(group)-1; i+=2){
        prefev.push_back(group[i+1]-group[i] + prefev[SZ(prefev)-1]);
        prefev.push_back(prefev[SZ(prefev)-1]);
    }
    for(int i = 1; i<SZ(group); i+=2){
        prefodd.push_back(prefodd[SZ(prefodd)-1]);
        prefodd.push_back(group[i+1]-group[i] + prefodd[SZ(prefodd)-1]);
    }
    ll res = min(prefev[SZ(prefev)-1],prefodd[SZ(prefodd)-1]);
    /*showAll(group);
    showAll(prefev);
    showAll(prefodd);*/
    fore(i,1,SZ(group)-1){
        if(i%2==0)res = min(res,prefev[i] + (prefodd[SZ(prefodd)-1]-prefodd[i+1]));
        else res = min(res,prefev[max(i-2,0)] + (group[i+1]-group[i-1]) + (prefodd[SZ(prefodd)-1]-prefodd[min(i+2,SZ(prefodd)-1)]));
    }
    return res;
}

void solve(){
    cin>>n>>k;
    ll e;
    map<ll,vector<ll>> groups;
    fore(i,0,n){
        cin>>e;
        groups[e%k].push_back(e);
    }
    ll res = 0;
    int odd = 0;
    for(auto g: groups){
        if(SZ(g.second)%2!=0)++odd;
        if(odd>=2){
            show(-1);
            return;
        }
        res += solve_group(g.second);
    }
    show(res/k);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.