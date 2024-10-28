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
    ll n,m;
    cin>>n>>m;
    vector<string> s(n);
    input(s);
    ll dp[n][m]; //cnt de iguales a la derecha
    fore(i,0,n){
        ll acc = 1;
        dfore(j,n-2,0){
            if(s[i][j]==s[i][j+1])++acc;
            else acc = 1;
            dp[i][j] = acc;
        }
    }
    int i=0,j=2;
    ll res = 1;
    while(i<m-1){
        //fijarse si hay j-i filas tq todos sus elementos sean iguales
        ll acc = 0;
        ll target = j-i;
        fore(k,0,n){
            if(dp[k][i]<target)acc = 0;
            else acc++;
            if(acc>=target)break;
        }
        if(acc>=target){
            res = max(res,target*target);
            ++j;
        }
        else ++i;
    }
    show(res);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?