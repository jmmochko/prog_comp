#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")

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

// se pueden hacer pares con suma <= k

vector<ll> nums;

int n;

ll can(ll k){
    ll acc = 0;
    fore(i,0,n-1){
        if(nums[i]>k){
            break;
        }
        auto it = upper_bound(all(nums),k-nums[i]);
        --it;
        int pos = (it-nums.begin());
        if(pos<=i)continue;
        acc += pos - i;
    }
    return acc;
}

void solve(){
    ll k;
    cin>>n>>k;
    nums.resize(n);
    input(nums);
    sort(all(nums));
    if(k==1){
        show(nums[0]+nums[1]);
        return;
    }
    //quiero saber el k-esimo par ordenado entre n elementos
    ll l = (nums[0] + nums[1]) - 1, r = nums[n-1] + nums[n-2] + 1;
    while(l+1<r){
        int m = (l+r)/(2ll);
        if(can(m) >= k)r = m;
        else l = m;
    }
    // la respuesta esta en el minimo par tal que la suma es >= que r
    ll res = nums[n-1]+nums[n-2];
    fore(i,0,n){
        auto it = lower_bound(all(nums),(r-nums[i]));
        if(it==nums.end())continue;
        res = min(res,*it + nums[i]);
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

//Cue "Eye of the Tiger"