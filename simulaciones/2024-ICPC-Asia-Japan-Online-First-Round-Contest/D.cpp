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

pll nxt(vector<pll> &nums, ll a, ll b, ll dir){
    if(dir == 0){//derecha
        ll na = MAXll;
        fore(i,0,SZ(nums)){
            if(nums[i].snd!=b || nums[i].fst<a)continue;
            if(nums[i].fst<na)na = nums[i].fst;
        }
        return {na,b};
    }
    if(dir == 1){//arriba
        ll nb = MAXll;
        fore(i,0,SZ(nums)){
            if(nums[i].fst!=a || nums[i].snd<b)continue;
            if(nums[i].snd<nb)nb = nums[i].snd;
        }
        return {a,nb};
    }
    if(dir == 2){//izq
        ll na = -MAXll;
        fore(i,0,SZ(nums)){
            if(nums[i].snd!=b || nums[i].fst>a)continue;
            if(nums[i].fst>na)na = nums[i].fst;
        }
        return {na,b};
    }
    ll nb = -MAXll;
    fore(i,0,SZ(nums)){
        if(nums[i].fst!=a || nums[i].snd>b)continue;
        if(nums[i].snd>nb)nb = nums[i].snd;
    }
    return {a,nb};
}

ll cycle(vector<pll> &nums, ll a, ll b, ll dir, pll start){
    ll res = 0;
    pll nx = nxt(nums,a,b,dir);
    DGB(nx.fst);DGB(nx.snd);
    while(nx!=start){
        res += abs(a-nx.fst) + abs(b-nx.snd) - 1;
        if(dir==0){
            a = nx.fst - 1;
        }
        if(dir==1){
            b = nx.snd - 1;
        }
        if(dir==2){
            a = nx.fst + 1;
        }
        if(dir==3){
            b = nx.snd + 1;
        }
        dir = (dir+1)%4;
        nx = nxt(nums,a,b,dir);
        }
    return res;
}

void solve(){
    while(true){
        ll n;
        cin>>n;if(n==0)break;
        ll a,b,d;
        cin>>a>>b>>d;
        vector<pll> nums(n);
        fore(i,0,n){
            cin>>nums[i].fst>>nums[i].snd;
        }
        set<pll> vis;
        ll dir = 0;
        while(d){
            pll nx = nxt(nums,a,b,dir);
            ll nd = abs(a-nx.fst) + abs(b-nx.snd)-1;
            if(d<=nd){
                if(dir==0){
                    cout<<a+d<<" "<<b<<'\n';
                }
                if(dir==1){
                    cout<<a<<" "<<b+d<<'\n';
                }
                if(dir==2){
                    cout<<a-d<<" "<<b<<'\n';
                }
                if(dir==3){
                    cout<<a<<" "<<b-d<<'\n';
                }
                break;
            }
            if(dir==0){
                a = nx.fst - 1;
            }
            if(dir==1){
                b = nx.snd - 1;
            }
            if(dir==2){
                a = nx.fst + 1;
            }
            if(dir==3){
                b = nx.snd + 1;
            }
            dir = (dir+1)%4;
            d -= nd;
            if(vis.count(nx)){
                ll clen = cycle(nums,a,b,dir,{a,b});
                d = d%clen;
            }
            vis.insert(nx);
        }
    }
}

int main(){
    //FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"