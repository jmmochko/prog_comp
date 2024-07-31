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
#define MAXll (1ll<<61)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

ll equalize(int v, vector<vector<int>> &tree, vector<ll> &nums){
    ll res = nums[v];
    if(SZ(tree[v])==0)return res;
    ll small = MAXll;
    for(int u: tree[v]){
        small = min(small,equalize(u,tree,nums));
    }
    if(small>res){
        res = (small+res)/2ll;
    }
    return min(res,small);
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> tree(n);
    vector<ll> nums(n);
    input(nums);
    fore(i,1,n){
        int p;
        cin>>p;
        --p;
        tree[p].push_back(i);
    }
    ll small = MAXll;
    for(int v: tree[0]){
        small = min(small,equalize(v,tree,nums));
    }
    show(nums[0]+small);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Escuchen, corran la bola...