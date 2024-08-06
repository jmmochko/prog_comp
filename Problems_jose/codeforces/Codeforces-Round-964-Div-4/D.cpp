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
    string s,t;
    cin>>s>>t;
    int i=0;
    fore(j,0,SZ(t)){
        while(i<SZ(s) && s[i]!=t[j] && s[i]!='?')++i;
        if(i>=SZ(s))break;
        s[i]=t[j];
        ++i;
    }
    fore(k,0,SZ(s))if(s[k]=='?')s[k]='z';
    bool res = false;
    int j = 0;
    fore(k,0,SZ(s))if(j<SZ(t) && s[k]==t[j])++j;
    if(j>=SZ(t)){
        show("YES");
        show(s);
    }
    else{
        show("NO");
    }
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo