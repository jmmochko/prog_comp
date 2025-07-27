#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
#define DGB(a) cout<<#a<<" = "<<a<<'\n'
using namespace std;
typedef long long ll;
#define pll pair<ll,ll>

random_device rd;
mt19937 rng(rd());

class Compare {
public:
	bool operator()(pll &a, pll &b) {
		if(a.fst > b.fst) {
			return true;
		}
		return false;
	}
};

ll solve(vector<ll> &bat,vector<pll> &charg){
    ll n = SZ(bat),m = SZ(charg);
    vector<ll> tengo(n);
    fore(i,0,n) {tengo[i] = bat[i];}
    priority_queue<pll, vector<pll>, Compare> pq;
    //prox carga de cada una
    vector<ll> cargas[n];
    fore(i,0,m)cargas[charg[i].snd].pb(charg[i].fst);
    fore(i,0,n)cargas[i].pb(charg[m-1].snd + 1000000000000000);
    fore(i,0,m){
        pq.push(charg[i]);
    }
    fore(i,0,n)pq.push({charg[m-1].snd + 1000000000000000,i});
    ll nxt = 0, estoy = 0;
    while(nxt<m && !pq.empty()){
        ll b = pq.top().second;
        ll pos_aux = pq.top().fst;
        ll tb = tengo[b];
        pq.pop();
        DGB(b);DGB(tb);DGB(estoy);cout<<"----------------\n";
        if(tb == 0)continue;if(pos_aux <= estoy)continue;
        tengo[b] -= min(charg[nxt].first - estoy, tb);
        estoy += min(charg[nxt].first - estoy, tb);
        // cout << b << " " << estoy << "\n";
        if(estoy == charg[nxt].first){
            // queueo la que acabo de cargar
            tengo[charg[nxt].snd] = bat[charg[nxt].snd];
            auto it = lower_bound(all(cargas[charg[nxt].snd]),estoy + 1);
            if(*it<=estoy)++it;
            pq.push({*it,charg[nxt].snd});
            ++nxt;
            if(nxt<m){
                // queueo la que sigue
                pq.push(charg[nxt]);
            }
        }
        // queueo la que acabo de gastar
        auto it = lower_bound(all(cargas[b]),estoy + 1);
        if(*it<=estoy)++it;
        pq.push({*it,b});
    }
    fore(i,0,n){estoy += tengo[i];DGB(tengo[i]);}
    return estoy;
}

ll attempt(ll estoy, ll uso, vector<ll> &bat, vector<ll> tengo, vector<pll> &charg){
    //cout<<estoy<<'\n';
    fore(i,0,SZ(charg))if(estoy==charg[i].fst)tengo[charg[i].snd] = bat[charg[i].snd];
    if(tengo[uso]>0){
        tengo[uso]--;
        estoy++;
    }
    else return 0;
    ll best = 0;
    fore(i,0,SZ(bat))best = max(best,attempt(estoy,i,bat,tengo,charg));
    return 1 + best;
}

ll brute(vector<ll> &bat,vector<pll> &charg){
    //intento usar ordenes
    ll res = 0;
    vector<ll> tengo(SZ(bat));
    fore(i,0,SZ(bat))tengo[i] = bat[i];
    fore(i,0,SZ(bat))res = max(res,attempt(0,i,bat,tengo,charg));
    return res;
}

int main(){
    FIN;
    int t;
    cin>>t;
    ll n,m;
    cin>>n>>m;
    while(t--){
        vector<ll> bat(n);
        //fore(i,0,n)cin>>bat[i];
        vector<pll> ch(m);
        //fore(i,0,m)cin>>ch[i].fst>>ch[i].snd;//, --ch[i].snd;
        fore(i,0,n)bat[i] = rng()%3 + 1;
        ll last = 0;
        fore(i,0,m){
            last += rng()%3 + 1;
            ch[i] = {last,rng()%n};
        }
        ll yo = solve(bat,ch);
        ll ellos = brute(bat,ch);
        if(solve(bat,ch) != brute(bat,ch)){
            cout<<yo<<'\n';
            cout<<ellos<<'\n';
            fore(i,0,n)cout<<bat[i]<<" ";
            cout<<'\n';
            fore(i,0,m)cout<<ch[i].fst<<" "<<ch[i].snd<<" ";
            cout<<'\n';
            cout<<"----------------------\n";
        }
    }
    return 0;
}
/*
int main(){
    FIN;
    int t;
    cin>>t;
    ll n,m;
    while(t--){
        cin>>n>>m;
        vector<ll> bat(n);
        fore(i,0,n)cin>>bat[i];
        vector<pll> ch(m);
        fore(i,0,m)cin>>ch[i].fst>>ch[i].snd, --ch[i].snd;
        ll yo = solve(bat,ch);
        cout<<yo<<'\n';
    }
    return 0;
}
*/
/*
9
10
2 2 1 
2 0 4 0 5 2
*/