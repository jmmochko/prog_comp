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

double brute(int n, vector<double> &nums){
    double res = 10e200;
    fore(i,0,n)fore(j,i+1,n)fore(k,j+1,n){
        vector<int> a(3);
        a[0] = nums[i];
        a[1] = nums[j];
        a[2] = nums[k];
        sort(all(a));
        if(a[0]+a[1]<=a[2])continue;
        double s = (nums[i] + nums[j] + nums[k]) / 2.00000;
        res = min(res, sqrt(s*(s-nums[i])*(s-nums[j])*(s-nums[k])));
    }
    return res;
}

double solve(int n, vector<double> &nums){
    sort(all(nums));
    double res = 10e200;
    fore(i,0,n-2){
        fore(j,1,n-1){
            int l = j+1, r = n;
            while(l+1<r){
                int m = (l+r)/2;
                if(nums[m]>nums[i]+nums[j])r = m;
                else l = m;
            }
            if(l>=n)continue;
            double s = (nums[i] + nums[j] + nums[l]) / 2.00000;
            res = min(res,sqrt(s*(s-nums[i])*(s-nums[j])*(s-nums[l])));
        }
    }
    return res;
}

int main(){
    FIN;
    fore(_,0,100){
        vector<double> nums(20);
        fore(i,0,20){
            nums[i] = rand()%501;
        }
        double b = brute(20,nums);
        double res = solve(20,nums);
        if(b != res){
            showAll(nums);
            DGB(b);
            DGB(res);
        }
        DGB(b);
        //assert((brute(20,nums) == solve(20,nums)));
    }
    return 0;
}

//Cue "Eye of the Tiger"
// minimizar esto: s*(s-nums[i])*(s-nums[j])*(s-nums[l])