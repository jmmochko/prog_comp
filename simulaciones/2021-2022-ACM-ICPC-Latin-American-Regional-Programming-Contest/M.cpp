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

void calc_pmin(vector<pair<pll,int>> &nums, vector<ll> &pmin, ll acc){
    ll prev = MAXll;
    fore(i,0,SZ(nums)){
        if(nums[i].second!=-1){
            acc += nums[i].first.second;
            prev = min(prev,nums[i].first.first-acc);
        }
        pmin[i] = prev;
    }
}

void solve(){
    int n;
    cin>>n;
    vector<pair<pll,int>> nums(n);//<<Deadline,Time>,i>
    fore(i,0,n){
        cin>>nums[i].first.second>>nums[i].first.first;
        nums[i].second = i;
    }
    sort(all(nums));
    //check if possible
    ll acc = 0;
    vector<int> pos(n);
    fore(i,0,n){
        acc += nums[i].first.second;
        if(acc>nums[i].first.first){
            show('*');
            return;
        }
        pos[nums[i].second] = i;
    }
    //start placing
    vector<int> res;
    vector<ll> pmin(n);
    acc = 0;
    fore(_,0,n){
        calc_pmin(nums,pmin,acc);
        fore(j,0,n){
            int i = pos[j];
            if(nums[i].second==-1)continue;
            if(i==0){
                res.push_back(j+1);
                acc += nums[i].first.second;
                nums[i].second = -1;
                break;
            }
            ll cutoff = pmin[i-1];
            if(cutoff-nums[i].first.second>=0){
                res.push_back(j+1);
                acc += nums[i].first.second;
                nums[i].second = -1;
                break;
            }
        }
    }
    showAll(res);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?