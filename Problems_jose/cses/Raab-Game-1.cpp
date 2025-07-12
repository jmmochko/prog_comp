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
    int n, a, b;
    cin>>n>>a>>b;
    if (a + b > n || (a == 0 && b > 0) || (b == 0 && a > 0)) {
        show("NO");
        return;
    }
    // 2 3 4 5 1 = n-1
    // 1 2 3 4 5 = 1

    // 1 2 3 4 5 = n/2
    // 2 1 4 3 5 = n/2

    vector<int> res(n), res2(n);
    fore(i,0,n){res[i] = i+1; res2[i] = i+1;}
    int i = 0;
    int mx = abs(a-b), ahora = res[0];
    while(mx){
        res[i]++;
        ++i;
        --mx;
    }
    res[i] = ahora;
    int mn = min(a,b);
    while(mn){
        swap(res[i],res[i+1]);
        --mn;
        i += 2;
    }
    //if(mn>0)++i;
    
    
    show("YES");
    if(a>b){
        showAll(res);
        showAll(res2);
    }
    else{
        showAll(res2);
        showAll(res);
    }
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"