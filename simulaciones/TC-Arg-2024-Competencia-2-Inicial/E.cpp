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
    vector<vector<int>> psums;
    vector<int> cur(ALPH,0);
    psums.pb(cur);
    fore(i,0,SZ(s)){
        cur[s[i]-'a']++;
        psums.push_back(cur);
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        --l;
        if(l+1==r || s[l]!=s[r-1]){
            show("YES");
            continue;
        }
        int cnt = 0;
        fore(i,0,ALPH){
            cnt += (psums[r][i] - psums[l][i] > 0);
        }
        if(cnt>2){
            show("YES");
            continue;
        }
        show("NO");
    }
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo