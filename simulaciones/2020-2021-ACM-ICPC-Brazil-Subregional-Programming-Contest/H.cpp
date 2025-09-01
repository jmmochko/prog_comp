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

const int MD = 62;

ll pascal[MD][MD];

ll permu(vector<ll> &nums, ll x){// primera mascara que es mayor o igual que x
    ll l = 0, r = 1ll<<SZ(nums);
    while(l+1<r){
        ll m = (l+r)/2;
        ll acc = 0;
        fore(i,0,SZ(nums)){
            if((1ll<<i) & m)acc += nums[i];
        }
        if(acc>=x)r = m;
        else l = m;
    }
    return r;
}

ll cntk(ll x, int k){
    ll res = 0;
    int kcpy = k;
    dfore(i,MD-1,0){
        if(kcpy>i)break;
        if((1ll<<i) & x){
            res += pascal[i][min(i,kcpy)];
            --kcpy;
        }
    }
    int acc = 0;
    fore(i,0,MD){
        if((1ll<<i) & x)acc++;
    }
    if(acc == k)++res;
    return res;
}

int main(){
    FIN;
    fore(i,0,MD){
        pascal[i][0] = 1;
        pascal[i][i] = 1;
    }
    fore(i,1,MD)fore(j,1,i){
        pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        //DGB(i);DGB(j);DGB(pascal[i][j]);
    }
    ll n,k,a,b;
    cin>>n>>k;
    vector<ll> nums(n);input(nums);
    sort(all(nums));
    cin>>a>>b;
    while(!nums.empty() && nums[SZ(nums)-1]>b)nums.pop_back();
    if(SZ(nums)==0){
        show(0);
        return 0;
    }
    ll la = permu(nums,a),lb = permu(nums,b);
    //cuantas mascaras con k bits hay entre [la,lb]
    show(cntk(lb,k)-cntk(la-1,k));
    return 0;
}

//Sobrevivimos al pabellon