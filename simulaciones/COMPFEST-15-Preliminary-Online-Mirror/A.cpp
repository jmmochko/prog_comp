    #include <bits/stdc++.h>
    #define fst first
    #define snd second
    #define pb push_back
    #define fore(i,a,b) for(int i=a;i<b;i++)
    #define SZ(x) ((int)x.size())
    #define all(x) x.begin(),x.end()
    #define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
    #define mset(a,v) memset((a),(v),sizeof(a))
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
     
    int main(){
        FIN;
        int n;
        cin>>n;
        vector<ll> nums(n);
        fore(i,0,n){cin>>nums[i];nums[i] = abs(nums[i]);}
        ll res = nums[0];
        fore(i,0,n)res = min(res,nums[i]);
        cout<<res<<'\n';
        return 0;
    }