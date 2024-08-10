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
 
ll fast_pow(ll b, ll e){
	if(e==0){
		return 1;
	}
	if(e==1){
		return b;
	}
	if(e%2==0){
		return (fast_pow(b,e/2)*fast_pow(b,e/2))%M;
	}
	return ((fast_pow(b,e/2)*fast_pow(b,e/2))%M)*b%M;
}
 
void solve(){
	ll n;
	cin>>n;
	show(fast_pow(2,n));
}
 
int main(){
	FIN;
    ui t;
    t=1;
    while(t--){
        solve();
    }
}