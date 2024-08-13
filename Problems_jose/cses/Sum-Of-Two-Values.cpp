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
    int n,x;
    cin>>n>>x;
    vector<pii> nums(n);
    fore(i,0,n){
        cin>>nums[i].first;
        nums[i].second = i+1;
    }
    sort(all(nums));
    if(nums[0].first>x/2){
        show("IMPOSSIBLE");
        return;
    }
    int i=0,j=n-1;
    while(i<j){
        while(nums[i].first+nums[j].first>x)--j;
        if(i==j)break;
        if(nums[i].first+nums[j].first==x){
            cout<<nums[i].second<<" "<<nums[j].second<<'\n';
            return;
        }
        ++i;
    }
    show("IMPOSSIBLE");
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo