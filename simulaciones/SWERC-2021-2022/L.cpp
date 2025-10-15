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

int lis(vector<ll> &nums){
    int n = SZ(nums);
    vector<ll> aux(n+1,MAXll);
    aux[0] = -MAXll;
    int res = 0;
    fore(i,0,n){
        auto it = upper_bound(all(aux),nums[i]);
        int p = it - aux.begin();
        if(nums[i]<aux[p]){
            aux[p] = nums[i];
            res = max(res,p);
        }
    }
    return res;
}

int main(){
    FIN;
    ll n,v;
    cin>>n>>v;
    vector<ll> t(n),a(n);
    input(t);
    input(a);
    vector<pll> nums;
    fore(i,0,n){
        if(v*t[i]>=abs(a[i])){
            nums.push_back({v*t[i] - a[i],v*t[i] + a[i]});
        }
    }
    sort(all(nums));
    vector<ll> coso(SZ(nums));
    fore(i,0,SZ(nums))coso[i] = nums[i].snd;
    show(lis(coso));
    return 0;
}

//Returneamos al pabellón