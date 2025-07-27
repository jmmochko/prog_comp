#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;
typedef long long ll;

void solve(){
    int n;
    string p;
    cin>>n>>p;
    vector<int> nums(n);
    fore(i,0,n)cin>>nums[i];
    int cnt = 0;
    fore(i,0,n)if(nums[i]!=i+1)++cnt;
    if(n==2){
        cout<<"Alice\n";
        return;
    }
    if(cnt==2 && p[0] == 'A'){
        cout<<"Alice\n";
        return;
    }
    if(cnt==0){
        cout<<"Alice\n";
        return;
    }
    if(n==3){
        if(p[0] == 'B'){
            if(cnt==3){
                cout<<"Alice\n";
                return;
            }
            else{
                cout<<"Bob\n";
                return;
            }
        }
    }
    cout<<"Bob\n";
}

int main(){
    FIN;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}