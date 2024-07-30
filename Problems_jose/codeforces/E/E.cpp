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
#define N 200005
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

vector<int> dp;//min k such that monster is not fought
multiset<int> seg[4*N+5];
void build(int node,int l,int r){
    if (l==r){
        seg[node].insert(dp[l]);
        return;
    }int mid=(l+r)/2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    for (int i=l;i<=r;i++) seg[node].insert(dp[i]);
    return;
}
void edit(int node,int l,int r,int idx,int val){
    if (l==r){
        seg[node].erase(dp[idx]);
        seg[node].insert(val);
        return;
    }int mid=(l+r)/2;
    if (idx<=mid) edit(node*2,l,mid,idx,val);
    else edit(node*2+1,mid+1,r,idx,val);
    seg[node].erase(dp[idx]);
    seg[node].insert(val);
    return;
}
int query(int node,int l,int r,int lx,int rx,int x){
    if (l>rx || r<lx) return INT_MAX;
    if (l>=lx && r<=rx){
        auto it=seg[node].lower_bound(x);
        if (it==seg[node].end()) return INT_MAX;
        return *it;
    }int mid=(l+r)/2;
    return min(query(node*2,l,mid,lx,rx,x),query(node*2+1,mid+1,r,lx,rx,x));
}

void solve(){
    dp.clear();
    int n,q,e;
    cin>>n>>q;
    vector<int> nums(n);
    input(nums);
    fore(i,0,n)dp.push_back(MAXINT);
    dp[0] = nums[0]+1;
    build(0,0,n-1);
    fore(i,1,n){
        int l = -1,r=N;
        while(l+1<r){
            int m = (l+r)/2;
            if(1+query(1,0,n-1,0,i,m)>nums[i]){
                l = m;
            }
            else r = m;
        }
        if(r!=N){
            dp[i] = r;
            edit(0,0,n-1,i,r);
        }
    }
    while(q--){
        int i,x;
        cin>>i>>x;
        if()
    }
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Escuchen, corran la bola...