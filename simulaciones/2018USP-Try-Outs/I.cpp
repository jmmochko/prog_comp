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

map<int,char> ps;

vector<pair<char,char>> pasos;

void solve(int n, int o, int d){//mover n barcos del puerto o al puerto d
    int otro;
    if(o+d == 1)otro = 2;
    if(o+d == 2)otro = 1;
    if(o+d == 3)otro = 0;
    if(n==1){
        pasos.pb({ps[o],ps[d]});
        return;
    }
    solve(n-1,o,otro);
    pasos.pb({ps[o],ps[d]});
    solve(n-1,otro,d);
}

int main(){
    FIN;
    int n,k;
    cin>>n>>k;
    ps[0] = 'A';
    ps[1] = 'B';
    ps[2] = 'C';
    if(k<(1<<n)-1){
        show("N");
        return 0;
    }
    else k -= (1<<n)-1;
    show("Y");
    solve(n,0,2);
    fore(i,0,SZ(pasos)-1){
        cout<<pasos[i].fst<<" "<<pasos[i].snd<<'\n';
    }
    int estoy = pasos[SZ(pasos)-1].fst - 'A';
    while(k){
        k--;
        cout<<ps[estoy]<<" "<<ps[1-estoy]<<'\n';
        estoy = 1-estoy;
    }
    cout<<ps[estoy]<<" "<<ps[2]<<'\n';
    return 0;
}

//Cue "Eye of the Tiger"