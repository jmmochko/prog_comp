//https://codeforces.com/problemset/problem/1986/D

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
    string s;
    cin>>s;
    if(n<=2){
        if(s[0]=='0'){
            show(s[1]);
            return;
        }
        show(s);
        return;
    }
    vector<int> nums;
    fore(i,0,n){
        nums.push_back(s[i]-'0');
    }
    int res = MAXINT;
    fore(i,0,n-1){
        vector<int> cur;
        fore(j,0,n){
            if(j==i){
                cur.push_back(nums[j]*10+nums[j+1]);
                ++j;
            }
            else{
                cur.push_back(nums[j]);
            }
            if(cur[SZ(cur)-1]==0){
                show(0);
                return;
            }
        }
        int acc = 0;
        fore(j,0,SZ(cur)){
            if(cur[j]!=1){
                acc+=cur[j];
            }
        }
        res = min(res,acc);
    }
    if(res==0){
        show(1);
        return;
    }
    show(res);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

//A man may play the dutch defense but must never defend the dutch.