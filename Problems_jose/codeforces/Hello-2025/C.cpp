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

/*void prt(ll a){
    fore(i,0,31){
        if(a&(1ll<<i))cout<<"1 ";
        else cout<<"0 ";
    }
    cout<<'\n';
}*/

vector<ll> solve(ll l, ll r){
    if(r-l == 2){
        return {l,l+1,r};
    }
    vector<ll> nums(3);
    int rp=34,lp=34;
    while(1ll<<rp > r){
        --rp;
    }
    dfore(i,rp,0){
        ll diff = 1ll<<i;
        if(nums[0] + diff <= r)nums[0] += diff;
        if((nums[1] + diff - 1 < l || (nums[1]==nums[2] && r!=diff && nums[1]+diff != nums[0])) && nums[1] + diff <= r)nums[1] += diff;
        if(nums[2] + diff - 1 < l && nums[2] + diff <= r)nums[2] += diff;
        sort(all(nums));
        //showAll(nums);
    }
    
    if(nums[0]==nums[1]){
        fore(i,0,rp){
            if(!(nums[0]&&(1ll<<i)) && (nums[0] + (1ll<<i) <= r)){nums[0] += 1ll<<i;break;}
        }
    }
    if(nums[0]==nums[1])nums[0] = r;
    return(nums);
    //DGB((nums[0]^nums[1])+(nums[1]^nums[2])+(nums[2]^nums[0]));
}

//brute
/*
int main(){
    fore(l,0,150)fore(r,l+2,152){
        vector<ll> nums = solve((ll)l,(ll)r);
        ll mine = (nums[0]^nums[1])+(nums[1]^nums[2])+(nums[2]^nums[0]);
        sort(all(nums));
        if(nums[0]==nums[1] || nums[1] == nums[2]){
            DGB(l);DGB(r);showAll(nums);RAYA;
        }
        ll brute = 0;
        fore(a,l,r+1)fore(b,a+1,r+1)fore(c,b+1,r+1){
            brute = max(brute,(ll)((a^b)+(b^c)+(c^a)));
            if((a^b)+(b^c)+(c^a) > mine){
                DGB(a);DGB(b);DGB(c);
            }
        }
        if(brute!=mine){
            DGB(l);DGB(r);DGB(mine);DGB(brute);showAll(nums);RAYA;
        }
    }
}
*/

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        showAll(solve(l,r));
    }
    return 0;
}

//Cue "Eye of the Tiger"

// 1 0 ...
// 0 1 1 ...
// 0 0 1 0 ...