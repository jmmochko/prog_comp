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

void solve(){
    int n;
    cin>>n;
    vector<pair<pll,int>> nums(n);
    fore(i,0,n){
        cin>>nums[i].fst.fst>>nums[i].fst.snd;//<d,p>
        nums[i].snd = i+1;
    }
    fore(i,1,n){
        ll xd=nums[i].fst.fst,xp=nums[i].fst.snd;
        while(i>0){
            ll yd=nums[i-1].fst.fst,yp=nums[i-1].fst.snd;
            if((yd * yp) + ((yd+xd)*xp) <= (xd * xp) + ((xd+yd)*yp))break;
            swap(nums[i],nums[i-1]);
            --i;
        }
    }
    fore(i,0,n){
        cout<<nums[i].snd<<" ";
    }cout<<'\n';
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//LEOOOOOOOOOOOOOOOOOOOOOOOOO

//  ---xy---- --> (y.d * y.p) + ((y.d+x.d)*x.p) < (x.d * x.p) + ((x.d+y.d)*y.p)
// 2 2 <--> 5 5
// 4 + 35
// 25 + 14