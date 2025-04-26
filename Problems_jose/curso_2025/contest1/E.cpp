#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define all(a) a.begin(),a.end()

using namespace std;

int main(){
    FIN;
    int n;
    cin>>n;
    vector<int> nums(n),sp0(n+1),sp1(n+1);
    //sp de sumas parciales
    //sp0[i] = diferencias con el string 01010101... hasta esa posicion
    //viceversa para sp1
    fore(i,0,n){
        cin>>nums[i];
    }
    sp0[0] = 0;
    sp1[0] = 0;
    fore(i,0,n){
        sp0[i+1] = sp0[i];
        sp1[i+1] = sp1[i];
        if(nums[i]==i%2)++sp0[i+1];
        else ++sp1[i+1];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        --l;
        cout<<min(sp0[r]-sp0[l],sp1[r]-sp1[l])<<'\n';
    }
    return 0;
}