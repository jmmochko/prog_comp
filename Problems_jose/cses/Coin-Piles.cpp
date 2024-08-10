#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define forn(a,b,c) for(int a=b; a<c;++a)
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
#define STRLEN 4
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
 
void solve(){
	vector<ll> ab(2);
	input(ab);
	sort(all(ab));
	if(ab[0]==0 && ab[1]==0){
		show("YES");
		return;
	}
	if(ab[1]>2*ab[0] || ab[1]==1 || ab[0]==0 || (ab[0]+ab[1])%3!=0){
		show("NO");
		return;
	}
	show("YES");
}
 
int main(){
	FIN;
    ui t;
    cin>>t;
    while(t--){
        solve();
    }
}