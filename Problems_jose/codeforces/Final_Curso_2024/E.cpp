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
//LEI MAL EL PROBLEMA LMAO

void solve(){
    int n;
    cin>>n;
    vector<ll> nums(n,0);
    ll e;
    ll acc = 0;
    fore(i,0,n){
        cin>>e;
        while(!(e&1) && e){
            ++acc;
            e/=2;
        }
        e = i+1;
        while(!(e&1) && e){
            ++nums[i];
            e/=2;
        }
    }
    sort(all(nums));
    if(acc>=n){
        show(0);
        return;
    }
    dfore(i,n-1,0){
        acc+=nums[i];
        if(acc>=n){
            show(n-i);
            return;
        }
    }
    show(-1);
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