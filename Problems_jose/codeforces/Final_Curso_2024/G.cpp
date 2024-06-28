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

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
ll mulmod(ll a, ll b, ll m) {
	ll r=a*b-(ll)((long double)a*b/m+.5)*m;
	return r<0?r+m:r;
}
ll expmod(ll b, ll e, ll m){
	if(!e)return 1;
	ll q=expmod(b,e/2,m);q=mulmod(q,q,m);
	return e&1?mulmod(b,q,m):q;
}
bool is_prime_prob(ll n, int a){
	if(n==a)return true;
	ll s=0,d=n-1;
	while(d%2==0)s++,d/=2;
	ll x=expmod(a,d,n);
	if((x==1)||(x+1==n))return true;
	fore(_,0,s-1){
		x=mulmod(x,x,n);
		if(x==1)return false;
		if(x+1==n)return true;
	}
	return false;
}
bool rabin(ll n){ // true iff n is prime
	if(n==1)return false;
	int ar[]={2,3,5,7,11,13,17,19,23};
	fore(i,0,9)if(!is_prime_prob(n,ar[i]))return false;
	return true;
}
// optimized version: replace rho and fact with the following:
const int MAXP=1e6+1; // sieve size
int sv[MAXP]; // sieve
ll add(ll a, ll b, ll m){return (a+=b)<m?a:a-m;}
ll rho(ll n){
	static ll s[MAXP];
	while(1){
		ll x=rand()%n,y=x,c=rand()%n;
		ll *px=s,*py=s,v=0,p=1;
		while(1){
			*py++=y=add(mulmod(y,y,n),c,n);
			*py++=y=add(mulmod(y,y,n),c,n);
			if((x=*px++)==y)break;
			ll t=p;
			p=mulmod(p,abs(y-x),n);
			if(!p)return gcd(t,n);
			if(++v==26){
				if((p=gcd(p,n))>1&&p<n)return p;
				v=0;
			}
		}
		if(v&&(p=gcd(p,n))>1&&p<n)return p;
	}
}
void init_sv(){
	fore(i,2,MAXP)if(!sv[i])for(ll j=i;j<MAXP;j+=i)sv[j]=i;
}
void fact(ll n, map<ll,int>& f){ // call init_sv first!!!
	for(auto&& p:f){
		while(n%p.fst==0){
			p.snd++;
			n/=p.fst;
		}
	}
	if(n<MAXP)while(n>1)f[sv[n]]++,n/=sv[n];
	else if(rabin(n))f[n]++;
	else {ll q=rho(n);fact(q,f);fact(n/q,f);}
}

void solve(){
    ll n;
    cin>>n;
    map<ll,int> facto;
    fact(n,facto);
    vector<pll> factors;
    for(auto e: facto){
        factors.push_back({e.first,(ll)e.second});
    }
    if(SZ(factors)==0){
        show("NO");
        return;
    }
    if(SZ(factors)==1){
        if(factors[0].second<6){
            show("NO");
            return;
        }
        show("YES");
        cout<<factors[0].first<<" "<<factors[0].first*factors[0].first<<" "<<(ll)pow(factors[0].first,factors[0].second-3)<<'\n';
        return;
    }
    if(SZ(factors)==2){
        if(factors[0].second + factors[1].second<=3){
            show("NO");
            return;
        }
        if(factors[0].second==1){
            show("YES");
            cout<<factors[0].first<<" "<<(ll)pow(factors[1].first,factors[1].second-1)<<" "<<factors[1].first<<'\n';
            return;
        }
        if(factors[1].second==1){
            show("YES");
            cout<<factors[1].first<<" "<<(ll)pow(factors[0].first,factors[0].second-1)<<" "<<factors[0].first<<'\n';
            return;
        }
        show("YES");
        cout<<(ll)pow(factors[0].first,factors[0].second-1)<<" "<<(ll)pow(factors[1].first,factors[1].second-1)<<" "<<factors[0].first*factors[1].first<<'\n';
        return;
    }
    if(SZ(factors)==3){
        show("YES");
        fore(i,0,3)cout<<(ll)pow(factors[i].first,factors[i].second)<<" ";
        cout<<'\n';
        return;
    }
    ll acc = 1;
    fore(i,1,SZ(factors)-1){
        acc*=(ll)pow(factors[i].first,factors[i].second);
    }
    show("YES");
    cout<<(ll)pow(factors[0].first,factors[0].second)<<" "<<acc<<" "<<(ll)pow(factors[SZ(factors)-1].first,factors[SZ(factors)-1].second)<<'\n';
}

int main(){
    FIN;
    init_sv();
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.