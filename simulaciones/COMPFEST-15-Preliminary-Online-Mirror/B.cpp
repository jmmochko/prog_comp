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

const ll M = 998244353;

int main(){
    //FIN;
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    fore(i,0,n){
        cin>>a[i];
    }
    fore(i,0,n)cin>>b[i];
    int m;
    cin>>m;
    vector<ll> c(m),d(m);
    fore(i,0,m)cin>>c[i];
    fore(i,0,m)cin>>d[i];
    map<ll,ll> diff;
    set<ll> iny;
    fore(i,0,n)diff[a[i]] += b[i];
    fore(i,0,m){diff[c[i]] += d[i];iny.insert(c[i]);}
    ll res = 1;
    for(auto p: diff){
        if(!iny.count(p.fst))res = (res*2)%M;
    }
    fore(i,0,m){
        ll llevo = d[i], hay = diff[c[i]];
        ll sobran = hay - llevo;
        if(sobran<llevo){
            res = 0;
            break;
        }
        if(sobran>llevo){
            res = (2*res)%M;
        }
    }
    cout<<res<<'\n';
    return 0;
}