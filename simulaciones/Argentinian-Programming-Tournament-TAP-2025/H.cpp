#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){return a?gcd(b%a,a):b;}
ll mulmod(ll a,ll b,ll m){
    ll r=a*b-(ll)((long double)a*b/m+ .5)*m;
    return r<0?r+m:r;
}
ll expmod(ll b,ll e,ll m){
    if(!e)return 1;
    ll q=expmod(b,e/2,m);q=mulmod(q,q,m);
    return e&1?mulmod(b,q,m):q;
}
    
bool is_prime_prob(ll n,int a){
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

bool rabin(ll n){
    if(n==1)return false;
    int ar[]={2,3,5,7,11,13,17,19,23};
    fore(i,0,9)if(!is_prime_prob(n,ar[i]))return false;
    return true;
}

const int MAXP=1e6+1;
int sv[MAXP];
ll add(ll a,ll b,ll m){return (a+=b)<m?a:a-m;}
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

void fact(ll n,map<ll,int>& f){
    for(auto&& p:f){
        while(n%p.first==0){
            p.snd++;
            n/=p.fst;
        }
    }
    if(n<MAXP)while(n>1)f[sv[n]]++,n/=sv[n];
    else if(rabin(n))f[n]++;
    else{ll q=rho(n);fact(q,f);fact(n/q,f);}
}

//////GENERQATE DIVISORS
void div_rec(vector<ll>& r,vector<pair<ll,int> >& f,int k,ll c){
    if(k==f.size()){r.pb(c);return;}
    fore(i,0,f[k].snd+1)div_rec(r,f,k+1,c),c*=f[k].fst;
}
vector<ll> divisors(vector<pair<ll,int>> f){
    vector<ll> r;
    div_rec(r,f,0,1);
    return r;
}

int main(){
    FIN;
    init_sv();
    int n;
    cin>>n;
    vector<ll> nums(n);
    fore(i,0,n)cin>>nums[i];
    sort(all(nums));
    bool soy = true;
    fore(i,0,n-1)if(nums[n-1]%nums[i]!=0)soy = false;
    if(soy){
        map<ll,int> f;
        fact(nums[n-1],f);
        vector<pair<ll,int>> ff;
        for(auto p: f){
            ff.pb(p);
        }
        ll falta = -1;
        vector<ll> divs = divisors(ff);
        sort(all(divs));
        fore(i,0,SZ(nums)){
            if(nums[i]!=divs[i]){
                falta = divs[i];
                break;
            }
        }
        if(falta == -1){
            if(SZ(nums)==1 && nums[0]==1){cout<<"*\n";return 0;}
            if(SZ(nums)==1 && nums[0]!=1){cout<<nums[0]<<" "<<1<<'\n';return 0;}
            falta = nums[n-1]*nums[1];
            cout<<falta<<" "<<falta<<'\n';
        }
        else cout<<nums[n-1]<<" "<<falta<<'\n';
        return 0;
    }
    ll num = nums[0];
    fore(i,1,n)num = num*(nums[i]/gcd(num,nums[i]));
    cout<<num<<" "<<num<<'\n';
    return 0;
}