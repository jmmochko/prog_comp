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
    string s;
    cin>>s;
    int n = SZ(s);
    int sd = 0, cnt2 = 0, cnt3 = 0; 
    fore(i,0,n){
        int e = s[i]-'0';
        if(e==2)++cnt2;
        else if(e==3)++cnt3;
        else sd+=e;
    }
    sd += 2*cnt2;
    sd = sd%9;
    if(sd==0){
        show("YES");
        return;
    }
    if(cnt3>0){
        if(sd + 3 == 9){
            show("YES");
            return;
            }
        if(cnt3>1){
            if(sd + 6 == 9){
                show("YES");
                return;
            }
        }
    }
    fore(i,0,cnt2){
        sd += 2;
        sd = sd%9;
        if(sd==0){
            show("YES");
            return;
        }
        if(cnt3>0){
            if(sd + 3 == 9){
                show("YES");
                return;
            }
            if(cnt3>1){
                if(sd + 6 == 9){
                    show("YES");
                    return;
                }
            }
        }
        
    }
    show("NO");
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//El año que viene soy GOD