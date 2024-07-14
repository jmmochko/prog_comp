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

vector<pii> solve(int n){
    string s,aux=to_string(n);
    fore(a,1,10001){
        fore(i,0,SZ(aux))s.push_back(aux[i]);
        fore(b,1,min(10001,a)){
            int res = (n*a) - b;
            if(res<0)continue;
            
        }
    }
}

int main(){
    FIN;
    int t = 100;
    while(t--){
        vector<pii> res = solve(t);
        show(SZ(res));
        fore(i,0,SZ(res))cout<<res[i].first<<" "<<res[i].second<<'\n';
    }
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.