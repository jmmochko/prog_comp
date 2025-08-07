#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define sz(a) ((int)a.size())
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
typedef long double ld;
typedef vector<int> vi;
typedef vector<ld> vld;
 
//El kactl is love, El kactl is life
 


pair<ld, vi> hungarian(const vector<vld> &a) {
	if (a.empty()) return {0, {}};
	int n = sz(a) + 1, m = sz(a[0]) + 1;
	vld u(n), v(m);vi p(m), ans(n - 1);
	fore(i,1,n) {
		p[0] = i;
		int j0 = 0; // add "dummy" worker 0
		vld dist(m, INT_MAX);
        vi pre(m, -1);
		vector<bool> done(m + 1);
		do { // dijkstra
			done[j0] = true;
			int i0 = p[j0], j1;
            ld delta = INT_MAX;
			fore(j,1,m) if (!done[j]) {
				ld cur = a[i0 - 1][j - 1] - u[i0] - v[j];
				if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
				if (dist[j] < delta) delta = dist[j], j1 = j;
			}
			fore(j,0,m) {
				if (done[j]) u[p[j]] += delta, v[j] -= delta;
				else dist[j] -= delta;
			}
			j0 = j1;
		} while (p[j0]);
		while (j0) { // update alternating path
			int j1 = pre[j0];
			p[j0] = p[j1], j0 = j1;
		}
	}
	fore(j,1,m) if (p[j]) ans[p[j] - 1] = j - 1;
	return {-v[0], ans}; // min cost
}
 
int main(){
    FIN;
    int n;
    cin>>n;
    vector<vld> mat(n);
    fore(i,0,n){
        fore(j,0,n){
            ld e;
            cin>>e;
            e = -(log(e));
            mat[i].pb(e);
        }
    }
    //fore(i,0,n){fore(j,0,n)cout<<mat[i][j]<<' ';cout<<'\n';}
    pair<ld, vi> res = hungarian(mat);
    vi ans(n);
    fore(i,0,n)ans[res.snd[i]] = i;
    fore(i,0,n)cout<<ans[i] + 1<<" ";
    cout<<'\n';
    return 0;
}
 
//Sobrevivimos al pabellon