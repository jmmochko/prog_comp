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

ll dp[105][4];
char a[105][2];
ll n;
ll f(ll i, ll fig){
    if(i > n-1) return 0;
    if(dp[i][fig] != -1) return dp[i][fig];

    dp[i][fig] == 0;

    if(fig==0){
        if(a[i][0] == '0' && a[i][1] == '0' && a[i+1][1] == '0'){
            ll max_f = 0;
            max_f = max(max_f, f(i+1,3));
            fore(j,0,4){
                max_f = max(max_f, f(i+2,j));
            }
            dp[i][fig] = 1 + max_f;
        } else{
            fore(j,0,4){
                dp[i][fig] = max(dp[i][fig], f(i+1,j));
            }
        }

    } else if(fig==1){
        if(a[i][0] == '0' && a[i][1] == '0' && a[i+1][0] == '0'){
            ll max_f = 0;
            max_f = max(max_f, f(i+1,2));
            fore(j,0,4){
                max_f = max(max_f, f(i+2,j));
            }
            dp[i][fig] = 1 + max_f;
        } else{
            fore(j,0,4){
                dp[i][fig] = max(dp[i][fig], f(i+1,j));
            }
        }
    } else if(fig==2){
        if(a[i][1] == '0' && a[i+1][0] == '0' && a[i+1][1] == '0'){
            ll max_f = 0;
            fore(j,0,4){
                max_f = max(max_f, f(i+2,j));
            }
            dp[i][fig] = 1 + max_f;
        } else{
            fore(j,0,4){
                dp[i][fig] = max(dp[i][fig], f(i+1,j));
            }
        }
    } else if(fig==3){
        if(a[i][0] == '0' && a[i+1][0] == '0' && a[i+1][1] == '0'){
            ll max_f = 0;
            fore(j,0,4){
                max_f = max(max_f, f(i+2,j));
            }
            dp[i][fig] = 1 + max_f;
        } else{
            fore(j,0,4){
                dp[i][fig] = max(dp[i][fig], f(i+1,j));
            }
        }
    }

    return dp[i][fig];
}

int main(){
    FIN;
    memset(dp,-1,sizeof(dp));
    string s1,s2;
    cin >> s1;
    cin >> s2;
    n = SZ(s1);
    fore(i,0,SZ(s1)){
        a[i][0] = s1[i];
        a[i][1] = s2[i];
    }
    ll res = 0;
    fore(i,0,4){
        res = max(res,f(0,i));
    }
    cout << res << "\n";
}