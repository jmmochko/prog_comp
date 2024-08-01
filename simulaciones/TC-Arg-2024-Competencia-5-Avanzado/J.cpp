#include<bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second
#define ll long long
#define pb push_back
#define forn(a,b,c) for(int a=b;a<c;a++)
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DBG(a) cout<<#a<<" = "<<a<<"\n"
#define jump cout<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define MAXN 100005

int main(){
    FIN;
    //ifstream cin("input.txt");
    string s;
    cin>>s;
    if(s.size() <= 4){
        show(0);
    }else{
        vector<ll> vvs;
        ll n=s.size(),act=0,solve=0;
        vvs.pb(0);
        forn(i,0,n-1){
            if(s[i]=='v' and s[i+1]=='v') act++;
            vvs.pb(act);
        }
        //showAll(vvs);
        forn(i,2,n-2){
            if(s[i]=='o') solve+=vvs[i]*(vvs.back()-vvs[i]);
        }
        show(solve);
    }

    //system("pause");
    //cin.close()
    return 0;
}
