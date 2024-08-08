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
    int n,k;
    cin>>n>>k;
    vector<int> nums(k);
    input(nums);
    int pos = -1,mx = 0;
    fore(i,0,k){
        if(nums[i]>mx){
            pos = i;
            mx = nums[i];
        }
    }
    if(mx>n){
        show('N');
        return;
    }
    if(pos!=0 && pos!=k-1 && nums[pos-1]==nums[pos+1]){
        show("N");
        return;
    }
    int prev=mx;
    dfore(i,pos-1,0){
        if((nums[i]!=prev-2 && nums[i]!=prev-1)||prev == 2){
            show('N');
            return;
        }
        prev = nums[i];
    }
    prev = mx;
    fore(i,pos+1,k){
        if((nums[i]!=prev-2 && nums[i]!=prev-1)||prev == 2){
            show('N');
            return;
        }
        prev = nums[i];
    }
    show("S");
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo