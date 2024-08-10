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
 
int occs[ALPH];
 
void solve(){
	string s;
	cin>>s;
	forn(i,0,s.size()){
		++occs[s[i]-'A'];
	}
	int oddn = 0;
	int oddpos = 0;
	forn(i,0,ALPH){
		if(occs[i]%2!=0){
			++oddn;
			oddpos = i;
		}
	}
	if(oddn>=2){
		show("NO SOLUTION");
		return;
	}
	int i = 0;
	int l = 0;
	while(i<s.size() && l<ALPH){
		while(occs[l]>1){
			s[i] = (char)(l+'A');
			s[(s.size()-1)-i] = (char)(l+'A');
			++i;
			occs[l]-=2;
		}
		++l;
	}
	if(oddn==1){
		s[s.size()/2] = (char)(oddpos+'A');
	}
	show(s);
}
 
int main(){
	FIN;
    ui t;
    t=1;
    while(t--){
        solve();
    }
}