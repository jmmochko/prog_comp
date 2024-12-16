#include <bits/stdc++.h>
using namespace std;

int main(){
    long long res = 0,a,b;
    vector<long long> L,R;
    while(scanf("%lld %lld",&a,&b)){
        L.push_back(a);
        R.push_back(b);
    }
    sort(L.begin(),L.end());
    sort(R.begin(),R.end());
    for(int i = 0;i<L.size();++i){
        res += abs(L[i]-R[i]);
    }
    cout<<res<<'\n';
    return 0;
}