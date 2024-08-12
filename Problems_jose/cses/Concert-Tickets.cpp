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
    int n,m;
    cin>>n>>m;
    set<ll> nums;
    map<ll,int> cnt;
    fore(i,0,n){
        ll e;
        cin>>e;
        nums.insert(e);
        if(cnt.find(e)==cnt.end()){
            cnt[e] = 0;
        }
        cnt[e]++;
    }
    while(m--){
        ll t;
        cin>>t;
        auto it = nums.lower_bound(t);
        if(SZ(nums)==0){
            show(-1);
            continue;
        }
        if(it==nums.begin()){
            if(*it>t){
                show(-1);
                continue;
            }
            show(*it);
            cnt[*it]--;
            if(cnt[*it]==0)nums.erase(*it);
            continue;
        }
        if(it==nums.end()){
            --it;
            show(*it);
            cnt[*it]--;
            if(cnt[*it]==0)nums.erase(*it);
            continue;
        }
        if(*it!=t){
            --it;
        }
        show(*it);
        cnt[*it]--;
        if(cnt[*it]==0)nums.erase(*it);
        continue;
    }
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo