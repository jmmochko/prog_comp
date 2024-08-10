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
	string s;
	cin>>s;
	int res = 1, curr = 1;
	char prev = s[0];
	forn(i,1,s.length()){
		if(s[i]==prev){
			++curr;
		}
		else{
			res = max(res,curr);
			curr=1;
			prev = s[i];
		}
	}
	res = max(res,curr);
	show(res);
}
 
int main(){
    ui t;
    t=1;
    while(t--){
        solve();
    }
}