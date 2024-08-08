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
    int n,r=0,d=0,rd=0,res=0;
    cin>>n;
    fore(i,0,n){
        string s;
        cin>>s;
        bool sr=false,sd=false;
        int k = 0;
        while(k<SZ(s) && s[k]!='D'){
            if(s[k]=='R')sr = true;
            ++k;
        }
        sd=s[k-1]=='D';
        while(k<SZ(s)){
            if(sd){
                if(s[k]=='R'){
                    sd=false;
                    ++res;
                }
            }
            else{
                if(s[k]=='D'){
                    sd = true;
                }
            }
            k++;
        }
        if(sr && sd)++rd;
        else if(sr)++r;
        else if(sd)++d;
    }
    if(r>0 && d>0 && rd>0){
        --r;
        --d;
        res += rd+1;
        rd = 0;
    }
    else if(r>0){
        res += rd;
        rd = 0;
    }
    else if(d>0){
        res += rd;
        rd = 0;
    }
    if(rd)res+=rd-1;
    res += min(r,d);
    show(res);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo