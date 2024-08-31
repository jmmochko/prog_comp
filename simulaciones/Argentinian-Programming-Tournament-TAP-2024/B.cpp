#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define all(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define show(a) cout<<a<<'\n'
#define showAll(a) for(auto b: a)cout<<b<<" ";cout<<'\n'
#define MAXN 1000001
typedef long long ll;
using namespace std;

int cr[MAXN];
void init_sieve(){
    memset(cr,-1,sizeof(cr));
    fore(i,2,MAXN)if(cr[i]<0)for(ll j = 1ll*i*i; j<MAXN; j+=i)cr[j] = i;
}
map<int,int> fact(int n){
    map<int,int> r;
    while(cr[n]>=0)r[cr[n]]++,n/=cr[n];
    if(n>1)r[n]++;
    return r;
}

int main(){
    int n;
    cin>>n;
    init_sieve();
    map<int,int> f = fact(n);
    if(SZ(f)==1){
        for(auto e: f){
            if(e.second==1){
                show(1);
                show("1 1");
            }
            else{
                show(1);
                cout<<1<<" "<<n/e.first<<'\n';
            }
        }
    }
    else{
        show(SZ(f));
        for(auto e: f){
            cout<<1<<" "<<n/e.first<<'\n';
        }
    }
    return 0;
}