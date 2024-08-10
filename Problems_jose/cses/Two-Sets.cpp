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
 
ll gauss(ll a){
	return (a*(a+1))/2;
}
 
void solve(){
	ll n;
	cin>>n;
	ll tot = gauss(n);
	if(n==1 || tot%2!=0){
		show("NO");
		return;
	}
	vector<int> resa(0), resb(0);
	ll curr = tot/2; 
	for(int i = n; i>0; --i){
		if(curr - i >= 0){
			curr -= i;
			resa.push_back(i);
		}
		else{
			resb.push_back(i);
		}
	}
	show("YES");
	show(resa.size());
	showAll(resa);
	show(resb.size());
	showAll(resb);
}
int main(){
	FIN;
    ui t;
    t=1;
    while(t--){
        solve();
    }
}