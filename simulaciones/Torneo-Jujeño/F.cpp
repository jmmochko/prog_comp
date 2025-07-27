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


struct UF {
	vector<ll> e;
	UF(ll n) : e(n, -1) {}
	bool sameSet(ll a, ll b) { return find(a) == find(b); }
	ll size(ll x) { return -e[find(x)]; }
	ll find(ll x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(ll a, ll b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b], e[b] = a;
		return true;
	}
};

int main(){
    FIN;
    int n,m;
    cin>>n>>m;
    vector<ll> nums(n);
    input(nums);
    UF uf(n+1);
    ll res = 0;
    fore(i,0,n)res += nums[i];
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            show(res);
        }
        else{
            int a,b;
            cin>>a>>b;--a;--b;
            if(uf.sameSet(a,b))continue;
            ll ca = uf.find(a), cb = uf.find(b);
            ll mn = min(nums[ca],nums[cb]);
            res -= uf.size(a)*nums[ca] + uf.size(b)*nums[cb];
            nums[ca] = mn;
            nums[cb] = mn;
            uf.join(a,b);
            res += uf.size(a)*mn;
        }
    }
    return 0;
}

//Sobrevivimos al pabellon