#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int main(){
    FIN;
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a<c + abs(c-b)){
            cout<<1<<'\n';
        }
        else if(a>c + abs(c-b)){
            cout<<2<<'\n';
        }
        else cout<<3<<'\n';
    }
    return 0;
}