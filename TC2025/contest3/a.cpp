#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first 
#define snd second
#define all(a) a.begin(),a.end()
#define oper(a,b) (a+b)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
using namespace std;
typedef long long ll;

const int K = 22;
const int MAXN = 1000005;

int sp[MAXN];

int st_query(int a, int b){
    return sp[b] - sp[a];
}

int dp[MAXN];
vector<pair<int,int>> faros;

int f(int i){//min faros destruidos si destruyo este
    if(i<=0){
        return 0;
    }
    if(dp[i]!=-1)return dp[i];
    int estoy = faros[i].fst;
    int largo = faros[i].snd;
    //DGB(i);DGB(estoy);DGB(largo);
    int j;
    auto it = lower_bound(all(faros),make_pair(estoy-largo,0));
    int esta = it->fst;
    //DGB(it-faros.begin() - 1);
    dp[i] = f((it-faros.begin())-1) + st_query(esta,estoy);
    return dp[i];
}

int aa[MAXN];

int main(){
    FIN;
    int n;
    cin>>n;
    fore(i,0,n){
        faros.push_back(make_pair(0,0));
        cin>>faros[i].fst>>faros[i].snd;
    }
    faros.push_back({1e9,1e9});
    sort(all(faros));
    fore(i,0,n)aa[faros[i].fst] += 1;
    fore(i,1,MAXN)sp[i] = sp[i-1] + aa[i];
    int res = 1e9;
    fore(i,0,n+1)dp[i] = -1;
    fore(i,0,n){
        res = min(res,n-i-1 + f(i));
        //DGB(i);DGB(res);RAYA;
    }
    cout<<min(res,n-1)<<'\n';
    return 0;
}
