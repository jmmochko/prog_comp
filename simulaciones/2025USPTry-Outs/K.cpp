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

double solve(int n, vector<double> &nums){
    sort(all(nums));
    double res = 1e200;
    fore(i,0,n-2){
        fore(j,1,n-1){
            int l = j+1, r = n;
            while(l+1<r){
                int m = (l+r)/2;
                if(nums[m]>nums[i]+nums[j])r = m;
                else l = m;
            }
            if(l>=n || nums[l]<=nums[i]+nums[j])continue;
            double s = (nums[i] + nums[j] + nums[l]) / 2.00000;
            res = min(res,sqrt(s*(s-nums[i])*(s-nums[j])*(s-nums[l])));
        }
    }
    return res;
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<double> nums(n);
        input(nums);
        double res = solve(n,nums);
        if(res>=1e200)show(-1);
        else cout<<setprecision(10)<<fixed<<res<<'\n';
    };
    return 0;
}

//Cue "Eye of the Tiger"
// minimizar esto: s*(s-nums[i])*(s-nums[j])*(s-nums[l])