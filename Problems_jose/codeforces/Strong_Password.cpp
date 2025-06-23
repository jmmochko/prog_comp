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
#define MAXN 300005
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
    string s,l,r;
    int m;
    cin>>s>>m>>l>>r;
    int i=0;
    fore(j,0,m){
        vector<bool> llevo(10,false);
        while(i<SZ(s)){
            llevo[s[i]-'0'] = true;
            bool tengotodos = true;
            fore(d,l[j]-'0',r[j]-'0'+1){
                tengotodos = tengotodos && llevo[d];
            }
            ++i;
            if(tengotodos)break;
            if(i==SZ(s)){
                show("YES");
                return;
            }
        }
        if(i==SZ(s) && j<m-1){
            show("YES");
            return;
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

//Cue "Eye of the Tiger"