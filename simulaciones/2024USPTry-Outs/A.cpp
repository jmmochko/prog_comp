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
    vector<pair<pii,pii>> nums(n);//<t.m><c,i>
    fore(i,0,n){
        cin>>nums[i].first.first>>nums[i].first.second>>nums[i].second.first;
        nums[i].second.second = i+1;
    }
    sort(all(nums));
    deque<pii> runnin;
    vector<int> res;
    runnin.push_back({nums[0].first.second,nums[0].second.second});
    fore(i,1,n){
        int passed = nums[i].first.first-nums[i-1].first.first;
        while(SZ(runnin) && runnin.front().first<=passed){
            passed -= runnin.front().first;
            runnin.pop_front();
        }
        if(SZ(runnin)){
            pii prev = runnin.front();
            prev.first-=passed;
            runnin.pop_front();
            runnin.push_front(prev);
        }
        if(nums[i].second.first && SZ(runnin)){
            res.push_back(runnin.front().second);
            runnin.pop_front();
            runnin.push_front({nums[i].first.second,nums[i].second.second});
        }
        else{
            runnin.push_back({nums[i].first.second,nums[i].second.second});
        }
    }
    show(SZ(res));
    showAll(res);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo