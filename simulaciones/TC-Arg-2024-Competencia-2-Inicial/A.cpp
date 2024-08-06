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
    vector<pll> nums(n);
    fore(i,0,n){
        cin>>nums[i].fst;
        nums[i].second = i+1;
    }
    sort(all(nums));
    int i = 1;
    while(i<n && nums[i].fst==nums[0].fst)++i;
    if(i==n||nums[i].fst==nums[n-1].fst){
        fore(i,0,3)cout<<-1<<" ";cout<<'\n';
        return;
    }
    cout<<nums[0].second<<" "<<nums[i].second<<" "<<nums[n-1].second<<'\n';
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo