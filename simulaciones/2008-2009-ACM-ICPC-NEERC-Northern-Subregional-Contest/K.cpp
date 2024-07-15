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
#define MAXN 1000001
#define ALPH 26
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int main(){
    FIN;
    ifstream cin("key.in");
    ofstream cout("key.out");
    ll n,m;
    cin>>n>>m;
    vector<ll> nums(n);
    input(nums);
    sort(all(nums));
    ll acc=0,i = 0;
    while(m){
        if(i<n && nums[i]<=acc+1){
            while(i<n && nums[i]<=acc+1){
                acc += nums[i];
                ++i;
            }
            continue;
        }
        cout<<acc+1<<" ";
        acc += acc+1;
        --m;
    }
    cout<<'\n';
    cin.close();
    cout.close();
    return 0;
}

// 1 1 1 3 7 10; acc = 3---> acc = 6 ---> acc = 13 ---> acc = 23