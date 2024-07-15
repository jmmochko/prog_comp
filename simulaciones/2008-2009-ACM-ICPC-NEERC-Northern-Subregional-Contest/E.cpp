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
#define MAXN 100
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

vector<int> g[MAXN]; // [0,n)->[0,m)
int n,m;
int mat[MAXN];bool vis[MAXN];
int match(int x){
	if(vis[x])return 0;
	vis[x]=true;
	for(int y:g[x])if(mat[y]<0||match(mat[y])){mat[y]=x;return 1;}
	return 0;
}
vector<pair<int,int> > max_matching(){
	vector<pair<int,int> > r;
	memset(mat,-1,sizeof(mat));
	fore(i,0,n)memset(vis,false,sizeof(vis)),match(i);
	fore(i,0,m)if(mat[i]>=0)r.pb({mat[i],i});
	return r;
}

int main(){
    FIN;
    ifstream cin("enchanted.in");
    ofstream cout("enchanted.out");
    string s1,s2,t1,t2;
    cin>>s1>>s2>>t1>>t2;
    n = SZ(s1);
    m = n;
    reverse(all(s2));
    reverse(all(t2));
    fore(i,0,n){
        fore(j,0,n){
            if(s1[i]==t1[j] && s2[i]==t2[j]){
                g[i].push_back(j);
            }
        }
    }
    vector<pair<int,int> > mm = max_matching();
    if(SZ(mm)==n)show("Yes");
    else show("No");
    cin.close();
    cout.close();
    return 0;
}

//GRACIAS PENAZZI.