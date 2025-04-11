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

bool f(vector<ll> &nums, int splits, int mx){
    set<int> llevo;
    //DGB(splits);DGB(mx);
    fore(i,0,SZ(nums)){
        if(nums[i]<mx)llevo.insert(nums[i]);
        if(SZ(llevo)>=mx){
            --splits;
            llevo.clear();
        }
    }
    return splits<=0;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll> nums(n);
    input(nums);
    int l=0,r=n+1;
    while(l+1<r){
        int m = (l+r)/2;
        //DGB(m);DGB(f(nums,k,m));
        if(f(nums,k,m))l=m;
        else r=m;
    }
    show(l);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"