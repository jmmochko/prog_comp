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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life

struct Hash {
	int P=1777771,MOD[2],PI[2];
	vector<int> h[2],pi[2];
	Hash(string& s){
		MOD[0]=999727999;MOD[1]=1070777777;
		PI[0]=325255434;PI[1]=10018302;
		fore(k,0,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
		fore(k,0,2){
			h[k][0]=0;pi[k][0]=1;
			ll p=1;
			fore(i,1,s.size()+1){
				h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
				pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
				p=(p*P)%MOD[k];
			}
		}
	}
	ll get(int s, int e){
		ll h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
		h0=(1LL*h0*pi[0][s])%MOD[0];
		ll h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
		h1=(1LL*h1*pi[1][s])%MOD[1];
		return (h0<<32)|h1;
	}
};

int findDif(Hash &original, Hash &cmp, int m, int i){
    int bordeizql = 0, bordeder = m;
    while(bordeizql+1<bordeder){
        int medio = (bordeizql+bordeder)/2;
        if(original.get(i,i+medio)==cmp.get(0,medio))bordeizql = medio;
        else bordeder = medio;
    }
    return bordeizql;
}

bool areEq(Hash &original, Hash &cmp, int m, int i, int dif){
    if(original.get(i,i+m)==cmp.get(0,m))return true;
    if(dif==0)return original.get(1,i+m)==cmp.get(1,m);
    if(dif>=m-1)return true;
    return (original.get(i,i+dif-1) == cmp.get(0,dif-1)) &&(original.get(i+dif+1,i+m) == cmp.get(dif+1,m));
}

void solve(){
    string a,b;
    cin>>a;
    cin>>b;
    Hash da(a),db(b);
    DGB(findDif(da,db,5,2));
    show(areEq(da,db,5,2,findDif(da,db,5,2)));
}

int main(){
    //FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//ESTOY SOLO YO