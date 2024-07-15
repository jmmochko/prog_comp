#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
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
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int main(){
    FIN;
    ifstream cin("important.in");
    ofstream cout("important.out");
    int n;
    cin>>n;
    vector<string> logs(n);
    //random empty line
    getline(cin,logs[0]);
    fore(i,0,n){
        getline(cin,logs[i]);
    }
    show("Yes");
    fore(i,0,n-1){
        cout<<'('<<logs[i][0]<<"|(~"<<logs[i][0]<<"))&";
    }
    cout<<'('<<logs[n-1][0]<<"|(~"<<logs[n-1][0]<<"))\n";
    cin.close();
    cout.close();
    return 0;
}