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

vector<pii> Ds = {{0,1},{1,1},{1,0},{1,-1}};

int main(){
    FIN;
    int l,c;
    cin>>l>>c;
    string mat[l];
    input(mat);
    int n;
    cin>>n;
    int ps[n][26];
    fore(i,0,n)fore(j,0,26)ps[i][j] = 0;
    fore(i,0,n){
        string s;
        cin>>s;
        fore(j,0,SZ(s)){
            ps[i][s[j] - 'A']++;
        }
    }
    set<int> res[l][c];
    fore(i,0,l){
        fore(j,0,c){
            set<int> soy;
            for(auto d: Ds){
                vector<pii> llevo;
                int ni = i,nj = j;
                vector<int> ls(26,0);
                while(ni>=0 && nj>=0 && ni<l && nj<c){
                    ls[mat[ni][nj] - 'A']++;
                    //DGB(ni);DGB(nj);
                    llevo.pb({ni,nj});
                    fore(k,0,n){
                        bool ig = true;
                        fore(p,0,26){
                            if(ps[k][p]!=ls[p]){
                                ig = false;
                                break;
                            }
                        }
                        if(ig){
                            for(auto par: llevo){
                                res[par.fst][par.snd].insert(k);
                            }
                        }
                    }
                    ni += d.fst;
                    nj += d.snd;
                }
            }
        }
    }
    int fnl = 0;
    fore(i,0,l)fore(j,0,c)if(res[i][j].size()>=2)++fnl;
    show(fnl);
    return 0;
}

//Sobrevivimos al pabellon