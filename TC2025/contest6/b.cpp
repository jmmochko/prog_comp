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
    vector<pair<int,int>> nums(n); //termina, comienza
    fore(i,0,n)cin>>nums[i].snd>>nums[i].fst;
    sort(all(nums));
    int nxt = 0, res = 0;
    fore(i,0,n){
        if(nums[i].snd > nxt){
            ++res;
            nxt = nums[i].fst;
        }
    }
    cout<<res<<'\n';
    return 0;
}