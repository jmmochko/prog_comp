#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define fore(i,a,b) for(int i=a;i<b;i++)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n;

bool can(vector<vector<pair<ll,ll>>> &corridos, ll z){
    priority_queue<pair<ll,ll>> q;
    fore(i,0,n){
        for(auto p: corridos[i]){
            q.push({-p.fst,p.snd});
        }
        ll acc = 0;
        if(!q.empty()){
            pair<ll,ll> p = q.top();
            if(-p.fst < i)return false;
        }
        while(!q.empty() && acc + (q.top()).snd<=z){
            pair<ll,ll> p = q.top();
            q.pop();
            acc += p.snd;
        }
        if(!q.empty()){
            pair<ll,ll> p = q.top();
            q.pop();
            ll sobran = z-acc;
            q.push({p.fst,p.snd-sobran});
        }
    }
    if(!q.empty())return false;
    return true;
}

int main(){
    FIN;
    cin>>n;
    vector<ll> a(n),d(n);
    fore(i,0,n)cin>>a[i];
    fore(i,0,n)cin>>d[i];
    vector<vector<pair<ll,ll>>> corridos(n);//hacia atras, <hasta que casilla pueden ir, cuantos son>
    fore(i,0,n){
        corridos[max(0ll,i-d[i])].pb({min(n-1,i+d[i]),a[i]});
    }
    ll l = -1, r = 1e9 + 5;
    while(l+1<r){
        ll m = (l+r)/2;
        if(can(corridos,m))r = m;
        else l = m;
    }
    cout<<r<<'\n';
    return 0;
}