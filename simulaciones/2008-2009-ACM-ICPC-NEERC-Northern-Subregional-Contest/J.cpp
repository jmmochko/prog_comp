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

ll k;

ll dp[13][2][109][109];

string s;

ll modulk(int a){
    if(a<0)a+=k;
    return a%k;
}

ll f(int i, bool t, int sum, int m){
    if(sum<0)return 0;
    if(dp[i][t][sum][m]!=-1)return dp[i][t][sum][m];
    dp[i][t][sum][m] = 0;
    if(i==SZ(s)-1){
        if(t){
            fore(j,0,(s[i]-'0')+1){
                if(j==sum && j%k == m)dp[i][t][sum][m]++;
            }
        }
        else{
            fore(j,0,10){
                if(j==sum && j%k == m)dp[i][t][sum][m]++;
            }
        }
        return dp[i][t][sum][m];
    }
    ll mk = 1;
    fore(p,0,(SZ(s)-i)-1)mk*=10;
    mk = mk%k;
    if(t){
        fore(j,0,s[i]-'0'){
            dp[i][t][sum][m] += f(i+1,false,sum-j,modulk(m-modulk(j*mk)));
        }
        dp[i][t][sum][m] += f(i+1,true,sum-(s[i]-'0'),modulk(m-modulk((s[i]-'0')*mk)));
        return dp[i][t][sum][m];
    }
    fore(j,0,10){
        dp[i][t][sum][m] += f(i+1,false,sum-j,modulk(m-modulk(j*mk)));
    }
    return dp[i][t][sum][m];
}

int main(){
    FIN;
    ifstream cin("just.in");
    ofstream cout("just.out");
    ll n;
    cin>>n;
    s = to_string(n);
    k = 108;
    ll res = 0;
    while(k>0){
        fore(a,0,13)fore(b,0,2)fore(c,0,109)fore(d,0,109)dp[a][b][c][d]=-1;
        res += f(0,true,k,0);
        --k;
    }
    show(res);
    cin.close();
    cout.close();
    return 0;
}