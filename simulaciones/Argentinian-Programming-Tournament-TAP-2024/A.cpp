#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define all(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define show(a) cout<<a<<'\n'
#define showAll(a) for(auto nousev: a)cout<<nousev<<" ";cout<<'\n'
#define pb push_back
#define pii pair<int,int>
#define RAYA cout<<"--------------\n";
#define DGB fore(ni,0,3){showAll(B[ni]);}RAYA
typedef long long ll;

using namespace std;

set<pii> rt[3][3];

int B[3][3];

//only call on playable squares
int play(int i, int j, int p){
    B[i][j] = p;
    //check for win vertical
    int cnt = 0;
    fore(ni,0,3){
        cnt += B[ni][j];
    }
    if(cnt == 3*p){B[i][j]=0; return p;}
    //horizontal
    cnt = 0;
    fore(nj,0,3){
        cnt += B[i][nj];
    }
    if(cnt == 3*p){B[i][j]=0; return p;}
    //diagonals
    cnt = 0;
    fore(ni,0,3){
        cnt += B[ni][ni];
    }
    if(cnt == 3*p){B[i][j]=0; return p;}
    cnt = 0;
    fore(ni,0,3){
        cnt += B[ni][2-ni];
    }
    if(cnt == 3*p){B[i][j]=0; return p;}
    //no immediate wins
    int res = p;
    cnt = 0;
    fore(ni,0,3)fore(nj,0,3){
        if(B[ni][nj]==0){
            bool playable = true;
            for(auto e: rt[ni][nj]){
                if(B[e.first][e.second]==0)playable=false;
            }
            if(playable){
                if(p<0)res = max(res,play(ni,nj,-p));
                else res = min(res,play(ni,nj,-p));
                ++cnt;
            }
        }
    }
    B[i][j]=0;
    if(cnt==0){return 0;}
    return res;
}

int main(){
    int r;
    cin>>r;
    if(r==0){
        show("E");return 0;
    }
    while(r--){
        int a,b;
        cin>>a>>b;
        --a;--b;
        rt[b/3][b%3].insert({a/3,a%3});
    }
    int res = -1,cnt=0;
    fore(ni,0,3)fore(nj,0,3){
        if(SZ(rt[ni][nj])==0){
            res = max(res,play(ni,nj,1));
            ++cnt;
        }
    }
    if(!res || !cnt)show("E");
    else if(res == 1)show("X");
    else show("O");
    return 0;
}