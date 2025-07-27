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

int main(){
    FIN;
    int n;
    cin>>n;
    vector<pair<int,int>> nums(n);
    fore(i,0,n){
        cin>>nums[i].fst>>nums[i].snd;
        nums[i].fst = -nums[i].fst;
    }
    sort(all(nums));
    cout<<"YES\n";
    fore(i,0,n-1){
        cout<<-nums[i].fst<<" "<<nums[i].snd<<'\n';
    }
    return 0;
}