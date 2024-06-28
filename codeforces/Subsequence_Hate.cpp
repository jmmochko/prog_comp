//https://codeforces.com/problemset/problem/1363/B

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
#define MAXll (1<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

void solve(){
    string s;
    cin>>s;
    if(SZ(s)<=2){
        show(0);
        return;
    }
    vector<int> cnt(SZ(s)+1,0);
    fore(i,1,SZ(s)+1){
        cnt[i] = cnt[i-1];
        if(s[i-1]=='1')++cnt[i];
    }
    int res = min(cnt[SZ(s)],SZ(s)-cnt[SZ(s)]),cur,oi,ui,of,uf;
    fore(i,1,SZ(s)+1){
        oi=i-cnt[i];
        ui=cnt[i];
        uf=(cnt[SZ(s)]-cnt[i]);
        of=(SZ(s)-i) - (cnt[SZ(s)]-cnt[i]);
        //tr hasta i en 1s, resto 0s o vice
        cur = min(oi + uf, of + ui);
        res = min(res,cur);
    }
    show(res);
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

//Escuchen Joy Division