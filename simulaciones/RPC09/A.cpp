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
#define pll pair<long long,long long>
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

int main() {
    FIN;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    fore(i,0,n) fore(j,0,m) cin >> a[i][j];

    int r, s;
    cin >> r >> s;
    int altura = n, ancho = m - s + 1;
    vector<vector<int>> H(altura, vector<int>(ancho));
    //horizontales
    fore(i,0,n) {
        deque<int> dq;
        fore(j,0,m) {
            while(!dq.empty() && a[i][dq.back()] <= a[i][j])
                dq.pop_back();
            dq.pb(j);
            if(dq.front() <= j - s) dq.pop_front();
            if(j >= s - 1) H[i][j - s + 1] = a[i][dq.front()];
        }
    }

    int alto2 = n - r + 1, an = ancho;
    vector<vector<int>> rta(alto2, vector<int>(an));
    //verticales
    fore(j,0,an) {
        deque<int> dq;
        fore(i,0,n) {
            while(!dq.empty() && H[dq.back()][j] <= H[i][j])
                dq.pop_back();
            dq.pb(i);
            if(dq.front() <= i - r) dq.pop_front();
            if(i >= r - 1) rta[i - r + 1][j] = H[dq.front()][j];
        }
    }
    //resultado
    fore(i,0,alto2) {
        fore(j,0,an) {
            if(j) cout << " ";
            cout << rta[i][j];
        }
        cout << "\n";
    }

    return 0;
}