#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
#define DGB(a) cout<<#a<<" = "<<a<<'\n';
using namespace std;
typedef long long ll;

const int maxn = 100005;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n),y(n),z(n),ocx(maxn,0),ocy(maxn,0),ocz(maxn,0);
    fore(i,0,n){
        cin>>x[i]>>y[i]>>z[i];
        ocx[x[i]]++;ocy[y[i]]++;ocz[z[i]]++;
    }
    vector<int> mx(n,0);
    fore(i,0,n)mx[i] = max({ocx[x[i]],ocy[y[i]],ocz[z[i]]});
    sort(all(mx));
    int i = 0, k = 0, llevo = 0;
    while(k<n){
        while(i<n && mx[i]<=k){
            if(mx[i]>0)++llevo;
            ++i;
        }
        cout<<llevo<<' ';
        ++k;
    }
    cout<<'\n';
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