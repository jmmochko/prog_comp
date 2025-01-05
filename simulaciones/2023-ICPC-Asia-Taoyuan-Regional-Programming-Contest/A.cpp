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
    string s;
    cin>>s;
    int n = SZ(s);
    vector<int> nums;
    for(int i = n-1; i>=0 ; i-=3){
        string num;
        int j = i;
        while(j>i-3 && j>=0){
            num.push_back(s[j]);
            --j;
        }
        reverse(all(num));
        nums.push_back(stoi(num));
    }
    int res = nums[0];
    fore(i,1,SZ(nums)){
        if(i%2==0){
            res += nums[i];
        }
        else{
            res -= nums[i];
        }
    }
    res = abs(res);
    cout<<res<<" ";
    if(res%13==0)cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//LEOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO