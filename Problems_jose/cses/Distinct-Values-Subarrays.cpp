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

int main(){
    FIN;
    int n;
    cin>>n;
    vector<int> nums(n);input(nums);
    set<int> ord;
    fore(i,0,n)ord.insert(nums[i]);
    map<int,int> comp;
    int cnt = 0;
    for(auto e:ord){
        comp[e] = cnt;
        ++cnt;
    }
    fore(i,0,n)nums[i] = comp[nums[i]];
    int l=0,r=0;
    ll res = 0;
    vector<bool> have(n,false);
    while(r<n){
        if(!have[nums[r]]){
            have[nums[r]] = true;
            ++r;
            res += r-l;
        }
        else{
            have[nums[l]] = false;
            ++l;
        }
    }
    show(res);
    return 0;
}

//Sobrevivimos al pabellon