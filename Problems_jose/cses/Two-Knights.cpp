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
	ll n;
	cin>>n;
	ll res,tot;
	show(0);
	if(n<=1){
		return;
	}
	show(6);
	if(n<=2){
		return;
	}
	show(28);
	if(n<=3){
		return;
	}
	show(96);
	if(n<=4){
		return;
	}
	forn(i,5,n+1){
		tot = i*i;
		res = 4*(tot-3);//esquinas
		res += 8*(tot-4);//al lado de las esquinas
		res += 4*(i-4)*(tot-5);//bordes
		res += 4*(tot-5);//esquinas interiores
		res += 4*(i-4)*(tot-7);//bordes interiores
		res += ((i-4)*(i-4))*(tot-9);//interior
		show((res/2));
	}
}
int main(){
	FIN;
    ui t;
    t=1;
    while(t--){
        solve();
    }
}