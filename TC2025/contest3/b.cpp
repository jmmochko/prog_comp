#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first 
#define snd second
#define all(a) a.begin(),a.end()

using namespace std;
typedef long long ll;

bool cmp(pair<pair<ll,ll>,ll> &a, pair<pair<ll,ll>,ll> &b){
    if(a.fst.snd<b.fst.snd)return true;
    else if(a.fst.snd == b.fst.snd)return a.fst.fst<b.fst.fst;
    else return false;
}

int main(){
    FIN;
    int n,m;
    cin>>n>>m;
    if(m<n-1){
        cout<<"No\n";
        return 0;
    }
    vector<pair<pair<ll,ll>,ll>> islas(n), medios(n-1);
    vector<pair<ll,ll>> puentes(m);
    fore(i,0,n){cin>>islas[i].fst.fst>>islas[i].fst.snd;}
    sort(all(islas));
    fore(i,0,m){
        cin>>puentes[i].fst;
        puentes[i].snd = i;
    }
    fore(i,0,n-1){
        medios[i] = {{islas[i+1].fst.fst - islas[i].fst.snd,islas[i+1].fst.snd - islas[i].fst.fst},i};
    }
    sort(all(medios),cmp);
    sort(all(puentes));
    int p = 0, i = 0;
    vector<ll> res(n-1);
    while(p<m && i<n-1){
        if(puentes[p].fst<=medios[i].fst.snd && puentes[p].fst>=medios[i].fst.fst){
            res[medios[i].snd] = puentes[p].snd;
            ++i;
        }
        ++p;
    }
    if(i<n-1){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    fore(i,0,n-1){
        cout<<res[i]+1<<" ";
    }
    cout<<'\n';
    return 0;
}