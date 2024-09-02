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
//ejibyyju
//101010101

int elimx(int x, vector<vector<int>> &cnt){
    vector<int> odd(ALPH,0),ev(ALPH,0);
    if(x&1){
        fore(i,0,ALPH){
            odd[i] = (cnt[SZ(cnt)-2][i] - cnt[x-1][i]) + cnt[max(x-2,0)][i];
            ev[i] = (cnt[SZ(cnt)-1][i] - cnt[x][i]) + cnt[max(x-1,0)][i];
        }
    }
    else{
        fore(i,0,ALPH){
            odd[i] = (cnt[SZ(cnt)-1][i] - cnt[x-1][i]) + cnt[max(x-2,0)][i];
            ev[i] = (cnt[SZ(cnt)-2][i] - cnt[x][i]) + cnt[max(x-1,0)][i];
        }
    }
    sort(all(odd),greater<int>());
    sort(all(ev),greater<int>());
    int res = 0;
    fore(i,1,ALPH){
        res += odd[i];
        res += ev[i];
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> cnt;
    vector<int> cureven(ALPH,0),curodd(ALPH,0);
    cnt.push_back(curodd);
    cureven[s[0]-'a']++;
    cnt.push_back(cureven);
    fore(i,1,n){
        if(i%2){
            curodd[s[i]-'a']++;
            cnt.push_back(curodd);
        }
        else{
            cureven[s[i]-'a']++;
            cnt.push_back(cureven);
        }
    }
    if(n%2==0){
        sort(all(cureven),greater<int>());sort(all(curodd),greater<int>());
        int res = 0;
        fore(i,1,SZ(cureven)){
            res += cureven[i];
        }
        fore(i,1,SZ(curodd)){
            res += curodd[i];
        }
        show(res);
        return;
    }
    if(n==1){
        show(1);
        return;
    }
    //have to erase one
    int res = MAXINT;
    fore(i,1,n+1){
        res = min(res,1+elimx(i,cnt));
    }
    show(res);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//ESTOY SOLO YO