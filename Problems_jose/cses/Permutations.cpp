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
	int n;
	cin>>n;
	if(n<=3 && n > 1){
		show("NO SOLUTION");
		return;
	}
	int i = 1;
	while(2*i<=n){
		cout<<2*i<<" ";
		++i;
	}
	i = 1;
	while((2*i)-1<=n){
		cout<<(2*i)-1<<" ";
		++i;
	}
}
 
int main(){
    ui t;
    t=1;
    while(t--){
        solve();
    }
}