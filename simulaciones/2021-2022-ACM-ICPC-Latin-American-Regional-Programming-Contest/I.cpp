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

map<string, ll> days;


void solve(){
    days["Mon"] = 0;    
    days["Tue"] = 1;
    days["Wed"] = 2;
    days["Thu"] = 3;    
    days["Fri"] = 4;
    days["Sat"] = 5;
    days["Sun"] = 6;
    string t;
    cin>>t;
    int n;
    cin>>n;
    int hoy = days[t];
    int sihicehoy = 30;
    if((hoy+30)%7>=5){
        sihicehoy += 7-(hoy+30)%7;
    }
    int res = sihicehoy;
    while(n--){
        int pasaron;
        cin>>pasaron;
        if(pasaron==0)continue;;
        int hiceeldep = hoy - pasaron;
        //normalizo a lunes
        while(hiceeldep<0 && (-hiceeldep)%7!=0){
            hiceeldep += 30;
            if((-hiceeldep)%7>=5){
                hiceeldep += 7-(-hiceeldep)%7;
            }
        }
        hiceeldep = -(-hiceeldep)%91;
        while(hiceeldep<0 && (-hiceeldep)%7!=0){
            hiceeldep += 30;
            if((-hiceeldep)%7>=5){
                hiceeldep += 7-(-hiceeldep)%7;
            }
        }
        int retiro = hiceeldep-hoy;
        int nextretiro = hiceeldep + 30;
        if(retiro>=0){
            if(retiro%7>=5){
                retiro += 7-retiro%7;retiro += 30;
            }
            res = min(res,retiro);
            continue;
        }
        if(nextretiro%7>=5){
            nextretiro += 7-nextretiro%7;
        }
        res = min(nextretiro-hoy,res);
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