#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;

bool up(ll h, ll n){
    ll mitad = (1ll<<n);
    if(h<mitad)return false;
    return true;
}

vector<bool> wentUp;

void fill(ll h, ll n){
    for(int i = n-1; i>=0; --i){
        wentUp.push_back(up(h,i));
        if(wentUp[SZ(wentUp)-1]){// lo reverseo
            h = (1ll<<(i+1))-1-h;
        }
    }
}

string res;

void solve(ll n, ll p, ll h){
    for(int i = n-1; i>=0; --i){
        if(wentUp[i]){
            if(p<(1ll<<i)){
                res.push_back('L');
                p =(1ll<<i)-1-p;
            }
            else{
                res.push_back('R');
                p =(1ll<<(i+1))-1-p;
            }
        }
        
        else{
            if(p<(1ll<<i)){
                res.push_back('R');
            }
            else{
                res.push_back('L');
                p = p - (1ll<<i);
            }
        }
    }
}

int main(){
    FIN;
    ll n,p,h;
    cin>>n>>p>>h;
    --p;--h;
    fill(h, n);
    solve(n,p,h);
    cout<<res<<'\n';
    return 0;
}