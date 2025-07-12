#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a = b; a<c; ++a)
#define ALL(a) a.begin(),a.end()
#define snd second
#define fst first
#define pii pair<int,int>
#define showall(a) for(auto i: a)cout<<i<<" ";cout<<'\n';
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin>>n;
    cout<<"? 1 2 3\n";
    cout.flush();
    int rta;
    cin>>rta;
    if(rta == 0){
        cout<<"! 1 2 3\n";
        cout.flush();
        return;
    }
    vector<int> nums(3);
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = rta;
    int i = 1;
    while(rta!=0){
        cout<<"? ";
        showall(nums);
        cout.flush();
        cin>>rta;
        if(rta==0 || rta == -1)break;
        nums[i] = rta;
        i++;
        i = 1 + i%2;
    }
    cout<<"! ";
    showall(nums);
    cout.flush();
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}