
#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
using namespace std;

int main(){
    vector<int> a(3);
    fore(i,0,3)cin>>a[i];
    sort(a.begin(),a.end());
    if(a[2]>=a[1]+a[0])cout<<"S\n";
    else cout<<"N\n";
    return 0;
}