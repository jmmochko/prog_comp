#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 200005
#define ALPH 26
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

void solve(){
    int k;
    string s;
    cin>>k>>s;
    if(k==2){
        char toca = '0';
        int res1 = 0, res2 = 0;
        fore(i,0,SZ(s)){
            if(s[i] != toca)++res1;
            if(toca=='0') toca = '1';
            else toca = '0';
        }
        toca = '1';
        fore(i,0,SZ(s)){
            if(s[i] != toca)++res2;
            if(toca=='0') toca = '1';
            else toca = '0';
        }
        cout<<min(res1,res2)<<" ";
        if(res1<res2)toca = '0';
        else toca = '1';
        fore(i,0,SZ(s)){
            cout<<toca;
            if(toca=='0') toca = '1';
            else toca = '0';
        }
        return;
    }
    s.pb('2');
    int cnt = 1;
    int res = 0;
    fore(i,1,SZ(s)-1){
        if(s[i]==s[i-1])++cnt;
        else cnt = 1;
        if(cnt==k){
            if(s[i]==s[i+1]){
                s[i] = '0' + ((s[i]+1)%2);
            }
            else{
                s[i-1] = '0' + ((s[i]+1)%2);
            }
            cnt = 1;
            ++res;
        }
    }
    s.pop_back();
    cout<<res<<" ";
    show(s);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?