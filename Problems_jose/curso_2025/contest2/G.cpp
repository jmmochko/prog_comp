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

int n,k;

bool can(vector<int> &nums, int p){
    vector<int> ps(n+1);
    ps[0] = 0;
    int x = nums[p];
    fore(i,0,n){
        ps[i+1] = ps[i];
        if(nums[i]>=x)++ps[i+1];
    }
    int i = 0, j = 0, acc = 0;
    while(j<=n){
        int largo = j-i;
        if(largo < k){
            acc += (nums[j] >= x);
            ++j;
            continue;
        }
        int offset = j-k-i;
        if(ps[j-k]-ps[i] <= offset/2){
            i = j-k;
            acc = ps[j] - ps[i];
        }
        largo = j-i;
        if(acc>largo/2){
            return true;
        }
        if(j<n)acc += (nums[j] >= x);
        ++j;
    }
    return false;
}

void solve(){
    cin>>n>>k;
    vector<int> nums(n);
    vector<pii> ord(n);
    input(nums);
    if(n==1){show(nums[0]);return;}
    fore(i,0,n){ord[i].fst = nums[i];ord[i].snd = i;}
    sort(all(ord));
    if(k==1){
        show(ord[n-1].fst);
        return;
    }
    int l=-1,r=n+1;
    while(l+1<r){
        int m = (l+r)/2;
        if(can(nums,ord[m].snd))l = m;
        else r = m;
    }
    show(ord[l].fst);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"