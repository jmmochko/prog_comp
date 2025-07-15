#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first 
#define snd second
#define all(a) a.begin() a.end()
#define pb push_back
using namespace std;
typedef long long ll;
int MOD = 0;
const ll MAXF = 501;
int add(int a,int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a,int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a,ll b){return a*b%MOD;}

ll pascal[MAXF][MAXF];//comb n,k

void pascalizar(){
    fore(i,0,MAXF)fore(j,0,MAXF)pascal[i][j] = 1;
    fore(i,1,MAXF){
        fore(j,1,i + 1){
            pascal[i][j] = add(pascal[i-1][j],pascal[i-1][j-1]);
        }
    }
}

ll nCr(ll n,ll k){
    if(n<=0||k<0||k>n)return 0;
    return pascal[n-1][k];
}

int main(){
    FIN;
    int n,m;
    cin>>n>>m>>MOD;
    pascalizar();
    cout<<nCr(4,2)<<'\n';
    vector<string> mat(m);
    fore(i,0,m)cin>>mat[i];
    ll res = 1;
    fore(c,0,n){
        ll libres = 2;
        fore(i,0,m){
            if(mat[i][c] == '1')--libres;
        }
        if(libres==0)continue;
        cout<<libres<<'\n';
        cout<<nCr(n-m,libres)<<'\n';
        res *= nCr(n-m,libres);
        res = res%MOD;
    }
    cout<<res<<'\n';
    return 0;
}