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

//El Vasito is love, El Vasito is life

int w,h;

bool cmpPair(pair<pii,int> a, pair<pii,int> b){
    if(a.first.first == 0 && b.first.first == 0){
        return a.first>b.first;
    }
    if(a.first.first == 0){
        return true;
    }
    if(b.first.first == 0){
        return false;
    }
    if(a.first.second == 0 && b.first.second == 0){
        return a.first<b.first;
    }
    if(a.first.second == 0){
        return true;
    }
    if(b.first.second == 0){
        return false;
    }
    if(a.first.first == w && b.first.first == w){
        return a.first<b.first;
    }
    if(a.first.first == w){
        return true;
    }
    if(b.first.first == w){
        return false;
    }
    return a.first>b.first;
}

void solve(){
    
    cin>>w>>h;
    int n;
    cin>>n;
    //<<x,y>,c>
    vector<pair<pii,int>> bordes;
    fore(i,0,n){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1==0||x1==w||y1==0||y1==h){
            if(x2==0||x2==w||y2==0||y2==h){
                bordes.push_back({{x1,y1},i});
                bordes.push_back({{x2,y2},i}); 
            }
        }
    }
    sort(all(bordes),cmpPair);
    fore(i,0,SZ(bordes))cout<<bordes[i].second<<" ";
    cout<<'\n';
    set<int> openC;
    vector<int> mystack;
    fore(i,0,SZ(bordes)){
        if(openC.count(bordes[i].second)){
            openC.erase(bordes[i].second);
            if(mystack[SZ(mystack)-1]!=bordes[i].second){
                show("N");
                return;
            }
            mystack.pop_back();
        }
        else{
            mystack.push_back(bordes[i].second);
            openC.insert(bordes[i].second);
        }
    }
    show("Y");
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?