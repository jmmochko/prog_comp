#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c;++a)
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
#define fst first
#define snd second
#define PI 3.141592653
#define yesif(a) cout << (a ? "YES\n" : "NO\n")
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
 
vector<pii> occs(ALPH,make_pair(0,0));//<occs of letter, letter>
 
void solve(){
    string s;
    cin>>s;
    set<string> res;
    sort(all(s));
    res.insert(s);
    while(next_permutation(all(s))){
        res.insert(s);
    }
    show(res.size());
    for(auto e:res){
        show(e);
    }
}
 
int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}