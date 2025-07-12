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

void solve(vector<vector<int>> &vsp){
    int l,r;
    cin>>l>>r;
    int res = MAXN;
    fore(i,0,31){
        res = min(res,vsp[r+1][i] - vsp[l][i]);
    }
    show(res);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    vector<vector<int>> vsp;
    vector<int> cnt(31,0);
    fore(i,0,MAXN){
        vsp.pb(cnt);
        fore(p,0,31){
            if(i&(1<<p))continue;
            ++cnt[p];
        }
    }
    vsp.pb(cnt);
    while(t--)solve(vsp);
    return 0;
}

//Cue "Eye of the Tiger"