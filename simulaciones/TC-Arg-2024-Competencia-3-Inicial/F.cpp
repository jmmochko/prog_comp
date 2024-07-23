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
#define ALPH 3
#define M 1000000007
#define MAXINT (1<<30)
#define MAXll (1ll<<60)
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

//El Vasito is love, El Vasito is life



int main(){
    FIN;
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    ll p31[n+1];//powers of 31 modulo M
    p31[0] = 1;
    fore(i,1,n+1){
        p31[i] = (p31[i-1]*31)%M;
    }
    vector<vector<int>> occs(ALPH);//occurences of every letter in order
    vector<vector<ll>> psum31(ALPH);//psums of powers of 31 associated with letter i modulo M
    fore(i,0,ALPH)psum31[i].push_back(0);
    fore(i,0,n){
        //record occurence
        occs[s[i]-'a'].push_back(i);
        //fill psums
        fore(j,0,ALPH)psum31[j].push_back(psum31[j][i]);
        psum31[s[i]-'a'][i+1] += p31[i];
        psum31[s[i]-'a'][i+1] = psum31[s[i]-'a'][i+1]%M;
    }
    while(m--){
        bool res = true;
        int x,y,len;
        cin>>x>>y>>len;
        --x;--y;
        if(x>y)swap(x,y);
        //calc "hash" for x
        ll hashx = 0;
        fore(i,0,ALPH){
            ll thing = (i*(((psum31[i][x+len] - psum31[i][x])+M)%M))%M;
            thing = (thing*p31[y-x])%M;
            DGB(i);
            DGB(thing);
            hashx = (hashx+thing)%M;
        }
        //match first occ of each letter in x side to its pair in y side
        vector<int> matches(ALPH,-1);
        set<int> used;
        fore(i,0,ALPH){
            auto it = lower_bound(all(occs[i]),x);
            if(it==occs[i].end())continue;
            int loc = occs[i][it - occs[i].begin()];
            if(loc<x+len){
                int match = s[loc + (y-x)]-'a';
                if(used.count(match)){
                    res = false;
                    break;
                }
                matches[i] = match;
                used.insert(match);
            }
        }
        if(!res){
            show("NO");
            continue;
        }
        //calc hash for y
        ll hashy = 0;
        fore(i,0,ALPH){
            if(matches[i]==-1)continue;
            ll thing = (matches[i]*(((psum31[matches[i]][y+len] - psum31[matches[i]][y])+M)%M))%M;
            DGB(matches[i]);
            DGB(thing);
            hashy = (hashy+thing)%M;
        }
        //check if equal
        DGB(hashx);DGB(hashy);
        if(hashx==hashy)show("YES");
        else show("NO");
        RAYA;
    }
    return 0;
}

//Escuchen, corran la bola...
/*i = 0
0 1 1 962 962 924483 924483 888428164 
==============
i = 1
0 0 31 31 31 31 28629182 28629182 
==============
i = 2
0 0 0 0 29791 29791 29791 29791*/

