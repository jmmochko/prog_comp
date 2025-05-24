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
#define MAXN 2001
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

ll dp[MAXN][MAXN];

vector<pll> neg;

ll f(int i, ll k){// min cantidad de vida que necesito para poder matar a estos con k skips
    if(k<0)return MAXll;
    if(dp[i][k]!=-1)return dp[i][k];
    if(i==0){
        if(k>0)return 0;
        else return (1ll+neg[0].fst);
    }
    dp[i][k] = min(f(i-1,k-1), neg[i].fst + max(1ll,f(i-1,k) - neg[i].snd));
    //DGB(i);DGB(k);DGB(dp[i][k]);DGB(f(i-1,k-1));DGB(1 + neg[i].fst + max(0ll,f(i-1,k) - neg[i].snd));RAYA;
    return dp[i][k];
}

bool cmp(pll &a, pll &b){
    if(a.fst - a.snd > b.fst - b.snd)return true;
    if(a.fst - a.snd < b.fst - b.snd)return false;
    return a.fst < b.fst;
}

bool solve(vector<pll> &Ds, int k, ll h){
    if(k==SZ(Ds))return true;
    if(h==0)return false;
    int n = SZ(Ds);
    neg.clear();
    vector<pll> pos;
    fore(i,0,n){
        ll x = Ds[i].fst,y = Ds[i].snd;
        if(y>=x)pos.pb({x,y});
        else neg.pb({x,y});
    }
    sort(all(pos));
    fore(i,0,SZ(pos)){
        if(pos[i].fst < h){
            h += pos[i].snd;
            h -= pos[i].fst;
        }
        else k--;
    }
    if(k<0){
        return false;
    }
    n = SZ(neg);
    if(n==0)return true;
    sort(all(neg),cmp);
    fore(i,0,n)fore(j,0,k+1)dp[i][j] = -1;
    //DGB(f(n-1,k));DGB(h);DGB(k);
    if(h>=f(n-1,k))return true;
    else return false;
}

bool brute(vector<pll> &Ds, int k, ll h){
    sort(all(Ds));reverse(all(Ds));
    fore(i,0,1<<SZ(Ds)){
        int kcpy = k;
        ll hcpy = h;
        fore(j,0,SZ(Ds)){
            if(i&(1<<j)){
                hcpy -= Ds[j].fst;
                if(hcpy<=0)break;
                hcpy += Ds[j].snd;
            }
            else --kcpy;
            if (kcpy<0)break;
            if(j==SZ(Ds)-1){
                /*ll hcpy2 = h;
                DGB(h);
                fore(z,0,SZ(Ds)){
                    if(i&(1<<z)){
                        DGB(z);
                        hcpy2 -= Ds[z].fst;
                        DGB(hcpy2);
                        hcpy2 += Ds[z].snd;
                        DGB(hcpy2);
                        RAYA;
                    }
                }*/
                return true;
            }
        }
    }
    return false;
}
/*
int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--){
        vector<pll> Ds(3);
        fore(i,0,SZ(Ds)){
            Ds[i].fst = rand()%10 + 1;
            Ds[i].snd = rand()%(Ds[i].fst);
        }
        ll h = rand()%10;
        int k = rand()%(SZ(Ds)+1);
        if(solve(Ds,k,h)!=brute(Ds,k,h)){
            cout<<SZ(Ds)<<" "<<h<<" "<<k<<'\n';
            fore(i,0,SZ(Ds))cout<<Ds[i].fst<<" "<<Ds[i].snd<<' ';cout<<'\n';
            DGB(solve(Ds,k,h));
            DGB(brute(Ds,k,h));
        };
    }
    return 0;
}
*/
int main(){
    FIN;
    int t;
    cin>>t;
    fore(tt,1,t+1){
        int n,k;
        ll h;
        cin>>n>>h>>k;
        vector<pll> nums(n);
        fore(i,0,n)cin>>nums[i].fst>>nums[i].snd;
        if(solve(nums,k,h))show("Y");
        else show("N");
        //if(brute(nums,k,h+1))show("Y");
        //else show("N");
    }
    return 0;
}

//Cue "Eye of the Tiger"
//10 3 8
//9 1 8 3 8 0 7 2 7 0 6 0 3 3 3 1 2 0 1 1
