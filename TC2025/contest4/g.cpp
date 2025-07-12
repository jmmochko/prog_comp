#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
#define DGB(a) cout<<#a<<" = "<<a<<'\n';
using namespace std;
typedef long long ll;

const int MAXN = 1001;

int n;
int res[MAXN][MAXN];
bool checker(){
    fore(x,0,n){
        fore(y,0,n){
            set<int> colors;
            fore(i,0,n){
                fore(j,0,n){
                    if((x-i)*(x-i) + (y-j)*(y-j) <= 100)colors.insert(res[i][j]);
                }
            }
            if(SZ(colors)>8){
                cout<<res[x][y]<<'\n';
                for(auto c: colors)cout<<c<<" ";
                cout<<'\n';
            }
        }
    }
    return true;
}

int color = 1;


int main(){
    FIN;
    cin>>n;
    fore(i,0,n)fore(j,0,n)res[i][j] = 0;
    for(int esq = 0; esq<n; esq += 21){
        for(int esq2 = 0; esq2<n; esq2 += 7){
            fore(i,esq,min(n,esq+21))fore(j,esq2,(min(n,esq2+7)))res[i][j] = color;
            ++color;
        }
    }
    fore(i,0,n){{fore(j,0,n){cout<<res[i][j]<<" ";}}cout<<'\n';}
    return 0;
}