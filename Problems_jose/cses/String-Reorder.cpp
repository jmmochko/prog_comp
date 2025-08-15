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

int main(){
    FIN;
    string s;
    cin>>s;
    vector<int> occs(ALPH,0);
    fore(i,0,SZ(s))occs[s[i]-'A']++;
    fore(i,0,ALPH)if(occs[i]>(SZ(s) + 1)/2){
        show(-1);
        return 0;
    }
    string res = "=";
    fore(i,0,SZ(s)){
        fore(k,0,ALPH){
            if(occs[k]>(SZ(s)-i)/2){
                res.pb(k+'A');
                --occs[k];
                break;
            }
        }
        if(SZ(res)>i+1)continue;
        int k = 0;
        while(!occs[k] || k+'A' == res[SZ(res)-1])++k;
        res.pb(k+'A');
        --occs[k];
    }
    fore(i,1,SZ(res))cout<<res[i];
    cout<<'\n';
    return 0;
}

//Sobrevivimos al pabellon