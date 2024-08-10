#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define forn(a,b,c) for(unsigned int a=b; a<c;++a)
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
 
int main(){
    FIN;
    ll n,res=0,comp=5;
    cin>>n;
    forn(i,0,13){
        res+=n/comp;
        comp*=5;
    }
    show(res);
    return 0;
}