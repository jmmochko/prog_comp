#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define ALL(a) a.begin(),a.end()
#define pb push_back
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
using namespace std;
typedef long long ll;

const int MAXN = 700;

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
    cin>>n;
    m = n;
    map<string,int> id;
    map<int,string> name;
    fore(i,0,n){
        string c;
        cin>>c;
        id[c] = i;
        name[i] = c;
    }
    vector<int> best(n,0);//best possible pos for horse
    map<int,set<int>> win;//horses that can win this race
    vector<bool> wpos(n,false);//true if someone won in this position
    int k;
    cin>>k;
    fore(i,0,k){
        int sz,bp;
        cin>>sz>>bp;--bp;
        set<int> race;
        fore(j,0,sz){
            string c;
            cin>>c;
            race.insert(id[c]);
            best[id[c]] = max(best[id[c]],bp);
        }
        vector<int> member;
        if(wpos[bp]){
            for(auto e: win[bp]){
                if(!race.count(e))member.push_back(e);
            }
        }
        else{
            win[bp] = race;
        }
        for(auto e:member)win[bp].erase(e);
        wpos[bp] = true;
    }
    fore(i,0,n){
        fore(j,best[i],n){
            if(!wpos[j]){
                g[i].push_back(j);
            }
        }
    }
    fore(j,0,n){
        if(wpos[j]){
            for(auto e: win[j]){
                if(best[e]<=j){
                    g[e].push_back(j);
                }
            }
        }
    }
    vector<pair<int,int> > mtch = max_matching();
    vector<string> res(n);
    for(auto e:mtch){
        res[e.snd] = name[e.fst];
    }
    fore(i,0,n){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
    return 0;
}