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
#define MAXN 1000001
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

int cr[MAXN]; // -1 if prime, some not trivial divisor if not
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN)if(cr[i]<0)for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=i;
}
map<int,int> fact(int n){  // must call init_cribe before
	map<int,int> r;
	while(cr[n]>=0)r[cr[n]]++,n/=cr[n];
	if(n>1)r[n]++;
	return r;
}

vector<int> divs(1000001,0);

void div_rec(vector<pair<ll,int> >& f, int k, ll c){
	if(k==f.size()){
        divs[c]++;
        return;
    }
	fore(i,0,f[k].snd+1)div_rec(f,k+1,c),c*=f[k].fst;
}
void divisors(vector<pair<ll,int> > f){
	vector<ll> r; // returns divisors given factorization
	div_rec(f,0,1);
	return;
}

int main(){
    FIN;
    ifstream cin("deposits.in");
    ofstream cout("deposits.out");
    init_sieve();
    int n,m;
    cin>>n;
    vector<int> a(n);
    input(a);
    cin>>m;
    vector<int> b(m);
    input(b);
    int i=0, j=0;
    ll res = 0;
    fore(i,0,n){
        map<int,int> facts = fact(a[i]);
        vector<pair<ll,int>> factss;
        for(auto e: facts){
            factss.push_back(e);
        }
        divisors(factss);
    }
    fore(j,0,m){
        res+=divs[b[j]];
    }
    show(res);
    cin.close();
    cout.close();
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.