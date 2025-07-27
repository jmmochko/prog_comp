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
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll i = 2, res = 1;
        while(i*i<=n){
            ll cnt = 0;
            while(n%i==0){
                n /= i;
                ++cnt;
            }
            res *= 2ll*cnt + 1;
            i++;
        }
        if(n>1){
            res *= 3ll;
        }
        cout<<(res+1)/2ll<<'\n';
    }
    return 0;
}