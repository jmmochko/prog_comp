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
    int n,m;
    cin>>n>>m;
    vector<int> nums(n+2),og(n+1);
    nums[0] = -1;
    nums[n+1] = n+1;
    fore(i,1,n+1){
        int e;
        cin>>e;
        nums[e] = i;
        og[i] = e;
    }
    int res = 1;
    fore(i,1,n+1){
        if(nums[i]<nums[i-1]){
            ++res;
        }
    }
    while(m--){
        vector<int> a(2);
        input(a);
        sort(all(a));
        int v = og[a[0]], w = og[a[1]];
        if(v==w+1){
            --res;
        }
        else if(v+1==w){
            ++res;
        }
        if((nums[v]<nums[v-1] && nums[w]>nums[v-1])){
            --res;
        }
        if((nums[w]>nums[w+1] && nums[v]<nums[w+1])){
            --res;
        }
        if((nums[w]>nums[w-1] && nums[v]<nums[w-1])){
            ++res;
        }
        if((nums[v]<nums[v+1] && nums[w]>nums[v+1])){
            ++res;
        }
        swap(nums[v],nums[w]);
        swap(og[a[0]],og[a[1]]);
        show(res);
    }
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo