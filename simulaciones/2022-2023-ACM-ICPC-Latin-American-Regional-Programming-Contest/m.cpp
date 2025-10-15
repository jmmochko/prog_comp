#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;

int r,c;
int mat[1002][102];
bool vis[1002][102];
vector<pair<int,int>> D = {{0,1},{1,0},{-1,0},{0,-1}};


bool solve(vector<int> &nut, int i, int j){
    vis[i][j] = true;
    if(i==r)return true;
    bool res = false;
    //i,j es pos del 0 de la nut;
    for(auto d: D){
        int ni = i + d.fst, nj = (j + d.snd + c)%c;
        if(ni<0 || ni>r)continue;
        if(vis[ni][nj])continue;
        bool puedo = true;
        fore(k,0,c){
            if(!nut[k])continue;
            int nnj = (nj + k)%c;
            if(mat[ni][nnj]){
                puedo = false;
                break;
            }
        }
        if(puedo)res = solve(nut,ni,nj);
        if(res)return true;
    }
    return false;
}

int main(){
    FIN;
    cin>>r>>c;
    vector<char> nt(c);
    fore(i,0,c)cin>>nt[i];
    vector<int> nut(c);
    fore(i,0,c)nut[i] = nt[i]-'0';
    char mt[r+1][c];
    fore(i,1,r+1)fore(j,0,c){cin>>mt[i][j];mat[i][j] = mt[i][j] - '0';}
    bool res = solve(nut,0,0);
    reverse(ALL(nut));
    fore(i,0,r+1)fore(j,0,c)vis[i][j] = false;
    res = res || solve(nut,0,0);
    if(res)cout<<"Y\n";
    else cout<<"N\n";
    return 0;
}