#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define all(a) a.begin(),a.end()

using namespace std;

int main(){
    FIN;
    int n,k;
    cin>>n>>k;
    vector<int> occs(k,0);
    fore(i,0,n){
        char c;
        cin>>c;
        occs[c-'A']++;
    }
    sort(all(occs));
    cout<<occs[0]*k<<'\n';
    return 0;
}