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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> days(m);
    vector<int> res(m),cnt(n+1,0);
    int maxi = 0,mpos;
    fore(i,0,m){
        int k;
        cin>>k;
        fore(j,0,k){
            int e;
            cin>>e;
            days[i].push_back(e);
        }
        res[i] = days[i][0];
        ++cnt[days[i][0]];
        if(cnt[days[i][0]]>maxi){
            maxi = cnt[days[i][0]];
            mpos = days[i][0];
        }
    }
    int target = m/2 + (m%2);
    if(maxi>target){
        fore(i,0,m){
            if(maxi<=target)break;
            if(res[i]==mpos && SZ(days[i])>1){
                res[i] = days[i][SZ(days[i])-1];
                --maxi;
            }
        }
    }
    if(maxi<=target){
        show("YES");showAll(res);
    }
    else{
        show("NO");
    }
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Gallardo 2: electric boogaloo