#include <bits/stdc++.h>
using namespace std;

int main(){
    long long res = 0,a,b;
    multiset<long long> L,R;
    while(scanf("%lld %lld",&a,&b)){
        L.insert(a);
        R.insert(b);
    }
    for(auto e: L){
        res += e*R.count(e);
    }
    cout<<res<<'\n';
    return 0;
}