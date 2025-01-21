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
#define MAXN 200003
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

struct UF{
    vector<int> uf;int sz;
    UF(int n): uf(n,-1), sz(n) {}
    int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);};
    bool join(int x, int y){
	    x=find(x);y=find(y);
	    if(x==y)return false;
	    if(uf[x]>uf[y])swap(x,y);
	    uf[x]+=uf[y];uf[y]=x;
	    return true;
    };
};

int main(){
    FIN;
    UF a(4);
    a.join(1,2);
    assert(a.find(1)==a.find(2));
    assert(a.find(0)!=a.find(2));
    assert(a.find(3)!=a.find(2));
    assert(a.find(0)!=a.find(3));
    a.join(0,2);
    assert(a.find(0)==a.find(2));
    return 0;
}