#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first 
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back

using namespace std;
typedef long long ll;

int main(){
    FIN;
    string s;
    cin>>s;
    string res;
    res.push_back('?');
    int i = 0;
    while(i<SZ(s)){
        if(i<SZ(s)-1 && s[i]==s[i+1]){
            i+=2;
        }
        else{
            res.pb(s[i]);
            ++i;
        }
        while(res[SZ(res)-1]==s[i]){
            ++i;
            res.pop_back();
        }
        
    }
    fore(i,1,SZ(res))cout<<res[i];
    cout<<'\n';
    return 0;
}