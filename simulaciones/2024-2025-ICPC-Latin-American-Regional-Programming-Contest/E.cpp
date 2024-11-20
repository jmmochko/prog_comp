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
    vector<int> nums(n);
    input(nums);
    int left = 0,right = n-1;
    int nextleft = left, nextright = right;
    fore(i,1,n+1){
        if(nums[left] == i){
            nums[left] = i;
            ++left;
            continue;
        }
        if(nums[right] == i){
            nums[right] = i;
            --right;
            continue;
        }
        if(nums[left] != 0 && nums[right] != 0){
            if(nums[left] == i)++left;
            else if (nums[right] == i)--right;
            else{
                show('*');
                return;
            }
            continue;
        }
        if(nums[left] != 0){
            nums[right] = i;
            --right;
            continue;
        }
        if(nums[right] != 0){
            nums[left] = i;
            ++left;
            continue;
        }
        //find nextleft and nextright
        nextleft = max(nextleft,left);
        nextright = min(right,nextright);
        while(nextleft < n && nums[nextleft]==0)++nextleft;
        while(nextright >= 0 && nums[nextright]==0)--nextright;
        
        if(nums[nextleft] > nums[nextright]){
            nums[right] = i;
            --right;
            continue;
        }
        if(nums[nextleft] < nums[nextright]){
            nums[left] = i;
            ++left;
            continue;
        }
        if(abs(left-nextleft)>abs(right-nextright)){
            nums[right] = i;
            --right;
            continue;
        }
        nums[left] = i;
        ++left;
        continue;
    }
    //check if valid solution
    bool asc = true;
    fore(i,1,n){
        if(nums[i]>nums[i-1] && !asc){
            show('*');
            return;
        }
        if(nums[i]<nums[i-1]){
            asc = false;
        }
    }
    showAll(nums);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//El año que viene soy GOD