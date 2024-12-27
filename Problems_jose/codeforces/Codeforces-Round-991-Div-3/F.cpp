#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define show(a) cout<<a<<" "
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

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}

#define oper(a,b) gcd(a,b)
#define K 20
int n;  // K such that 2^K>n
ll st[K][1<<K];
void st_init(int *a){
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
ll st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
    return oper(st[k][s],st[k][e-(1<<k)]);
}

void solve(){
    int q;
    cin>>n>>q;
    vector<int> nums(n);
    input(nums);
    --n;
    int diff[n],prev,cur;
    prev = nums[0];
    fore(i,0,n){
        cur = nums[i+1];
        diff[i] = abs(prev-cur);
        prev = cur;
    }
    st_init(diff);
    while(q--){
        int l,r;
        cin>>l>>r;
        --l;--r;
        if(l==r)show('0');
        else show(st_query(l,r));
    }
    cout<<'\n';
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--){solve();}
    return 0;
}

//El año que viene soy GOD