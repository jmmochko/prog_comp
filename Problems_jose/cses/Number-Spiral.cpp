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
 
void solve(){
	ll x,y,sq,nsq;
	cin>>y>>x;
	sq = max(x,y);
	nsq = min(x,y);
	ll res = sq*sq;
	if(sq%2==0){
		res -= abs(1-x);
		res -= abs(sq-y);
	}
	else{
		res -= abs(1-y);
		res -= abs(sq-x);
	}
	show(res);
}
 
int main(){
	FIN;
    ui t;
    cin>>t;
    while(t--){
        solve();
    }
}