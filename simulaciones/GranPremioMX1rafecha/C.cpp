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
    vector<ll> a(3),b(3);
    input(a);input(b);
    sort(all(a));sort(all(b));
    fore(i,0,3){
        if(b[i]>a[i]){
            show(0);return 0;
        }
    }
    ll res = 0;
    fore(j,0,3){
        fore(k,0,3){
            ll cur = 1;
            if(k==j)continue;
            cur *= a[0]/b[j];
            cur *= a[1]/b[k];
            if(j+k==1){
                cur *= a[2]/b[2];
            }
            if(j+k==2){
                cur *= a[2]/b[1];
            }
            if(j+k==3){
                cur *= a[2]/b[0];
            }
            res = max(res,cur);
        }
    }
    show(res);
}

//Cue "Eye of the Tiger"