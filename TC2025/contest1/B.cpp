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
    vector<int> res(n,0);
    //busco el padre del final de los niveles
    int u = n-1;
    int p = n-2;
    while(u>1){
        int r;
        cout << "? " << u << " " << p << "\n";
        cout.flush();
        cin >> r;
        if(r==-1) break;
        else if(r==0){
            res[u] = p;
            u = u-1;
        }
        p -= 1;
        if(!p) break;
        // si es 0, preguntamos por el que sigue
        
    }
    cout << "! ";
    fore(i,1,n){
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}