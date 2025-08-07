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

bool can(int k, ll m, vector<ll> &nums){
    int n = SZ(nums);
    vector<int> ps(n+1);
    ps[0] = 0;
    fore(i,0,n){
        ps[i+1] = ps[i];
        if(nums[i]>m)++ps[i+1];
        if(nums[i]<m)--ps[i+1];
    }
    vector<bool> vistos(2*(n+1),false);
    vistos[n] = true;
    fore(i,k-1,n){
        if(vistos[n + ps[i+1]])return true;
        vistos[n + ps[i-k+2]] = true;
    }
    return false;
}

ll brute(int k, vector<ll> &nums){
    ll res = 0;
    fore(i,1,SZ(nums)+1){
        if(can(k,i,nums))res = i;
    }
    return res;
}

void solve(){
    int k,n;
    cin>>n>>k;
    vector<ll> nums(n);
    input(nums);
    ll l = 0,r = n;
    while(l+1<r){
        ll m = (l+r)/2;
        if(can(k,m,nums))l = m;
        else r = m;
    }
    if(can(k,r,nums))show(r);
    else show(l);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--){
        int k,n;
        cin>>n>>k;
        vector<ll> nums(n);
        input(nums);
        show(brute(k,nums));
    }
    return 0;
}

//Sobrevivimos al pabellon