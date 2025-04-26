#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int main(){
    FIN;
    int t;
    cin>>t;
    while(t--){
        int a,res = 0;
        cin>>a;
        //notese que no hace falta declarar variables manualmente para b,c,d
        for(int i = 0; i<3; ++i){
            int e;
            cin>>e;
            if(e>a)++res;
        }
        cout<<res<<'\n';
    }
    return 0;
}
