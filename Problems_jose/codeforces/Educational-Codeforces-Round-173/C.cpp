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
    vector<int> nums(n);
    input(nums);
    vector<int> p(n+1);
    p[0] = 0;
    int diff = n;
    fore(i,0,n){
        if(abs(nums[i])==1)p[i+1] = p[i] + nums[i];
        else{
            p[i+1] = 0;
            diff = i;
        } 
    }
    int mn = 0, mx = 0, mxres = 0, mnres = 0;
    fore(i,0,diff+1){
        mxres = max(mxres, p[i]-mn);
        mnres = min(mnres, p[i]-mx);
        mx = max(mx,p[i]);
        mn = min(mn,p[i]);
    }
    int mn2 = 0, mx2 = 0, mx2res = 0, mn2res = 0;
    fore(i,diff+2,n+1){
        mx2res = max(mx2res, p[i]-mn2);
        mn2res = min(mn2res, p[i]-mx2);
        mx2 = max(mx2,p[i]);
        mn2 = min(mn2,p[i]);
    }
    set<int> res;
    fore(i,mnres,mxres+1){
        res.insert(i);
    }
    fore(i,mn2res,mx2res+1){
        res.insert(i);
    }
    if(diff==n){
        show(SZ(res));
        showAll(res);
        return;
    }
    //now including diff
    int lcnt = 0, rcnt = 0, mxcnt = 0, mncnt = 0;
    dfore(i,diff-1,0){
        lcnt += nums[i];
        mxcnt = max(mxcnt,lcnt);
        mncnt = min(mncnt,lcnt);
    }
    int mx2cnt = 0, mn2cnt = 0;
    fore(i,diff+1,n){
        rcnt += nums[i];
        mx2cnt = max(mx2cnt,rcnt);
        mn2cnt = min(mn2cnt,rcnt);    
    }
    fore(i,min(mncnt,mn2cnt),max(mxcnt,mx2cnt)+1){
        res.insert(i+nums[diff]);
    }
    fore(i,nums[diff],nums[diff]+mx2cnt+mxcnt+1){
        res.insert(i);
    }
    fore(i,nums[diff]+mn2cnt+mncnt,nums[diff]+1){
        res.insert(i);
    }
    show(SZ(res));
    showAll(res);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"