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
    vector<pair<pll,int>> nums(n);//<<D,T>,i>
    fore(i,0,n){
        cin>>nums[i].first.second>>nums[i].first.first;
        nums[i].second = i;
        nums[i].first.second = -nums[i].first.second;
    }
    sort(all(nums));
    //check if possible
    ll acc = 0;
    vector<int> pos(n), t(n);
    fore(i,0,n){
        t[i] = acc;
        acc -= nums[i].first.second;
        if(acc>nums[i].first.first){
            show('*');
            return;
        }
        pos[nums[i].second] = i;
    }
    //if it was possible, make lex min
    fore(p,0,n){
        //search for how far back
        int from = pos[p];
        while(from > 0){
            if(t[from-1] - nums[from].first.second - nums[from-1].first.second > nums[from-1].first.first)break;
            if(t[from-1] - nums[from].first.second > nums[from].first.first)break;
            if(nums[from].second>nums[from-1].second)break;
            t[from] = t[from-1] - nums[from].first.second;
            swap(nums[from],nums[from-1]);
            swap(pos[p],pos[nums[from].second]);
            --from;
        }
    }
    fore(i,0,n){
        cout<<(nums[i].second + 1)<<' ';
    }
    cout<<'\n';
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?