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
#define conv(a,b,c) ((a>=b&&c>=b)||(a<=b&&c<=b))
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//Sale regional?

ll areaT(vector<pll> base){
    return base[0].first*(base[1].second-base[2].second) + base[1].first*(base[2].second-base[0].second) + base[2].first*(base[0].second-base[1].second);
}

bool convex(vector<pll> base){
    return conv(base[0].first,base[1].first,base[2].first) || conv(base[0].second,base[1].second,base[2].second);
}

ll find_area(vector<pll> base){
    DGB(SZ(base));
    if(SZ(base)<=2){
        return 0;
    }
    ll res = 0;
    int i = 0;
    vector<pll> nextV;
    while(i<=SZ(base)-2){
        nextV.push_back(base[i]);
        if(convex({base[i],base[i+1],base[i+2]}))res += abs(areaT({base[i],base[i+1],base[i+2]}));
        else res -= abs(areaT({base[i],base[i+1],base[i+2]}));
        i+=2;
    }
    ll nt = find_area(nextV);
    DGB(nt);
    return res + nt;
}

int main(){
    FIN;
    int n;
    cin>>n;
    vector<pll> base(n);
    fore(i,0,n)cin>>base[i].first>>base[i].second;
    base.push_back(base[0]);
    show(abs(find_area(base)));
    return 0;
}