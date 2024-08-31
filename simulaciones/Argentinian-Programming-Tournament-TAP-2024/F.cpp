#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
using namespace std;

int main(){
    FIN;
    int n; cin >> n;
    vector<int> a(n);
    fore(i,0,n) cin >> a[i];

    int cnt = 0;
    int res = 0;
    fore(i,0,n){
        if(a[i]==1) {
            cnt++;
            res++;
        } else{
            cnt = 0;
            res--;
        }

        if(cnt >= 3) res++;
    }

    cout << res << "\n";
}