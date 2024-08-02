#include<bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
#define pb push_back
#define SZ(a) ((int)a.size())
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DBG(a) cout<<#a<<" = "<<a<<"\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
#define jump cout<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define MAXN 200005
#define ALPH 26
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1<<60)
#define PI 3.141592653

struct cmpPair {
    bool operator()(pair<ll,int> a, pair<ll,int> b) {
        if (a.first < b.first) return true;
        else if (a.first == b.first && a.second > b.second) return true;
        else return false;
    }
};

int main(){
    FIN;
    //ifstream cin("input.txt");
    ll n,t; cin>>n;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, cmpPair > pq;
    fore(i,0,n){
        ll bas; cin>>bas;
        pq.push(make_pair(bas,i));
    }
    cin>>t;
    while(t--){
        ll k,pos; cin>>k>>pos;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, cmpPair > aux = pq;
        vector<pair<int,ll> > res;
        fore(i,0,k){
            res.pb(make_pair(aux.top().second,aux.top().first));
            aux.pop();
        }
        sort(all(res));
        show(res[pos-1].snd);
    }
    //system("pause");
    //cin.close()
    return 0;
}
