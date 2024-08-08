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
#define MAXN 4000
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

vector<int> lfts,rts;
double dp[MAXN][MAXN][2];
int n,e,s;

double calcD(pair<double,double> i, pair<double,double> j){
    double a = i.first - j.first, b = i.second-j.second;
    a*=a;b*=b;
    return sqrt(a+b);
}

double f(int l, int r, bool lor, vector<pair<double,double>> &nums){// respuesta maxima de llegar a s recorriendo hasta l/r. lor en true implica que estoy en lfts
    if(dp[l][r][lor]!=0)return dp[l][r][lor];
    if(l==0 && r == 0){
        if(lor){
            dp[l][r][lor] = calcD(nums[e],nums[lfts[0]]) + calcD(nums[s],nums[lfts[0]]);
        }
        else{
            dp[l][r][lor] = calcD(nums[e],nums[rts[0]]) + calcD(nums[s],nums[rts[0]]);
        }
    }
    if(lor){
        if(l == 0){
            dp[l][r][lor] = calcD(nums[r],nums[l])+f(l,r-1,false,nums);
        }
        
    }
    else{

    }
}

void solve(){
    cin>>n>>e>>s;
    --e;--s;
    vector<pair<double,double>> nums(n);
    fore(i,0,n){
        cin>>nums[i].first>>nums[i].second;
    }
    int i = (e+1)%n;
    while(i!=s){
        lfts.push_back(i);
        i = (i+1)%n;
    }
    i=(i+1)%n;
    while(i!=e){
        rts.push_back(i);
        i = (i+1)%n;
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