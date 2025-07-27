#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    FIN;
    ll t; cin >> t;
    while(t--){
        string s; cin >> s;
        vector<pair<ll,char>> aps(26);
        fore(i,0,26){
            aps[i] = {0,'a'+i};
        }
        for(auto c : s){
            aps[c-'a'].fst++;
        }
        ll max_ap = 0;
        ll cant_dist = 0;
        ll min_ap = 1e7;
        fore(i,0,26) if(aps[i].fst) cant_dist++;
        for(auto [x,y] : aps){
            max_ap = max(max_ap,x);
            if(x>0){
                min_ap = min(min_ap,x);
            }
        }
        if(cant_dist == 1 && min_ap > 1) cout << "NO\n";
        else if(cant_dist == 1) cout << "YES\n" << s << "\n";
        else if(cant_dist == 2 && min_ap > 1) cout << "NO\n";
        else{
            cout << "YES\n";
            sort(all(aps));
            ll pos_fst;
            fore(i,0,26){
                if(aps[i].fst > 0){
                    pos_fst = i;
                    cout << aps[i].snd;
                    aps[i].fst--;
                    break;
                }
            }
            fore(i,pos_fst+1,26){
                while(aps[i].fst--){
                    cout << aps[i].snd;
                }
            }
            while(aps[pos_fst].fst--) cout << aps[pos_fst].snd;
            cout << "\n";
        }
    }
}