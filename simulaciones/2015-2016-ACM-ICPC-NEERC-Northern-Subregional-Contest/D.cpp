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
#define fact2(a) __builtin_ctz(a)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

vector<ll> solve(ll a){
    if(a<=3){
        vector<ll> res;
        res.push_back(a);
        return res;
    }
    if(a%2==0){
        vector<ll> res = solve(a/2);
        fore(i,0,SZ(res))res[i] = res[i]<<1;
        return res;
    }
    ll cmp = 3;
    while(cmp<a)cmp*=3;
    if(cmp>a)cmp/=3;
    vector<ll> res = solve(a-cmp);
    res.push_back(cmp);
    return res;
}

int main(){
    //FIN;
    /*fore(p,0,100){
        ll target = rand()%1000000000000000000;
        vector<ll> res = solve(target);
        ll acc = 0;
        fore(k,0,SZ(res))acc+=res[k];
        if(acc!=target)show("BAD ADDITION");
        sort(all(res));
        int i = 0;
        while(i<SZ(res) && res[i]==0){
            ++i;
        }
        DGB(target);
        show(SZ(res)-i);
        showAll(res);
    }*/
    ifstream cin("distribution.in");
    ofstream cout("distribution.out");
    int t = 1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n<=4){
            show(1);
            show(n);
            continue;
        }
        vector<ll> res = solve(n);
        sort(all(res));
        int i = 0;
        while(i<SZ(res) && res[i]==0){
            ++i;
        }
        show(SZ(res)-i);
        fore(k,i,SZ(res))cout<<res[k]<<" ";cout<<'\n';
    }
    cin.close();
    cout.close();
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.