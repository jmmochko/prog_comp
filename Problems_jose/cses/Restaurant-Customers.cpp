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
    int n;
    cin>>n;
    vector<pii> nums(n);
    fore(i,0,n){
        cin>>nums[i].first>>nums[i].second;
    }
    set<int> leavin;
    sort(all(nums));
    int res=0, in=0;
    fore(i,0,n){
        ++in;
        leavin.insert(nums[i].second);
        auto it = leavin.lower_bound(nums[i].first);
        if(it!=leavin.begin())--it;
        while(*it<nums[i].first){
            leavin.erase(*it);
            it = leavin.lower_bound(nums[i].first);
            --in;
        }
        res = max(res,in);
    }
    show(res);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo