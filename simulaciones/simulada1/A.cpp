#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

bool compare_first(const pair<ll,pair<ll,bool>>& a, const pair<ll,pair<ll,bool>>& b) {
  return a.first < b.first;
}

int main(){
    FIN;
    ifstream cin("access.in");
    ofstream cout("access.out");
    ll n,m;
    cin >> n;
    vector<bool> stat(n);
    vector<ll> from(n), to(n);
    fore(i,0,n){
        string a,b,c;
        cin >> a >> b >> c;

        if(a=="allow") stat[i] = 1;
        else stat[i]=0;

        istringstream iss(c);
        ll aa, bb, cc, dd, ee = -1; // Inicializa e a -1 para indicar que no hay máscara por defecto
        char dot, slash;
        iss >> aa >> dot >> bb >> dot >> cc >> dot >> dd;

        bool mask = false;
        if (iss >> slash) { // Intenta leer el slash, si es exitoso, entonces hay una máscara
            iss >> ee;
            mask = true;
        }

        ll ip = aa * (1LL << 24) + bb * (1LL << 16) + cc * (1LL << 8) + dd;
        ll ipt = ip;
        if(mask) ipt = ip - 1 + (1LL << (32 - ee));

        from[i] = ip;
        to[i] = ipt;
    }

    cin >> m;
    set<pair<ll,ll>> qs;
    vector<bool> res(m, true);
    fore(i,0,m){
        string q; cin >> q;

        istringstream iss(q);
        ll aa, bb, cc, dd;
        char dot;
        iss >> aa >> dot >> bb >> dot >> cc >> dot >> dd;
        ll ip = aa * (1LL << 24) + bb * (1LL << 16) + cc * (1LL << 8) + dd;

        qs.insert({ip, i});
    }


    // qs es un set donde estan los par {ip del query, indice del query}
    fore(i,0,n){
        auto it = qs.lower_bound({from[i], -1});
        while(it != qs.end() && it->fst <= to[i]){
            if(!stat[i]) res[it->snd] = false;
            it = qs.erase(it);
        }
    }

    fore(i,0,m){
        if(res[i]) cout << "A";
        else cout << "D";
    }
    cout << "\n";


    cin.close();
    cout.close();
}

// GRACIAS DURAN.
