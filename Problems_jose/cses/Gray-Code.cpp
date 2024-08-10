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
	int n;
    cin >> n;
    vector<string> gray_code;
    gray_code.push_back("");
    for (int i = 0; i < n; i++) {
        int size = gray_code.size();
        for (int j = size - 1; j >= 0; j--) {
            gray_code.push_back(gray_code[j]);
        }
        size *= 2;
        for (int j = 0; j < size; j++) {
            if (j < gray_code.size() / 2) {
                gray_code[j] += "0";
            } else {
                gray_code[j] += "1";
            }
        }
    }
    for (int i = 0; i < gray_code.size(); i++) {
        show(gray_code[i]);
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