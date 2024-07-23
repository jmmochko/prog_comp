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

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending &";
string s2 = "&? Are you busy? Will you send &";
string s3 = "&?";

ll dp[56];

ll rec_szn(int n){
    if(n==0)return SZ(f0);
    dp[n] = 2*rec_szn(n-1) + SZ(s1) + SZ(s2) + SZ(s3);
    return dp[n];
}

ll szn(int n){//sizeof fn
    if(n<0)return -1;
    if(n==0)return SZ(f0);
    if(n>55)return MAXll;
    if(dp[n])return dp[n];
    return rec_szn(n);
}

char rec_solve(int n, ll k){
    if(n==0){
        if(k>=SZ(f0))return '.';
        return f0[k];
    }
    if(k<SZ(s1)){
        char res = s1[k];
        if(res=='&')res='"';
        return res;
    }
    k-=SZ(s1);
    ll target = szn(n-1);
    if(k<target){
        return rec_solve(n-1,k);
    }
    k-=target;
    if(k<SZ(s2)){
        char res = s2[k];
        if(res=='&')res='"';
        return res;
    }
    k-=SZ(s2);
    if(k<target){
        return rec_solve(n-1,k);
    }
    k-=target;
    if(k<SZ(s3)){
        char res = s3[k];
        if(res=='&')res='"';
        return res;
    }
    return '.';
}

void solve(){
    int n;
    ll k;
    cin>>n>>k;
    --k;
    cout<<rec_solve(n,k);
}

int main(){
    FIN;
    szn(55);
    int t = 1;
    cin>>t;
    while(t--)solve();
    cout<<'\n';
    return 0;
}

//Escuchen, corran la bola...