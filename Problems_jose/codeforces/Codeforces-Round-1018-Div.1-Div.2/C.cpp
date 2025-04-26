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

ll f(vector<ll> &nums1, vector<int> &blkprox1, vector<int> &blkant1){
    ll res1=0, res2=0;
    fore(i,0,SZ(nums1)-1){
        if(i%2){
            if(blkprox1[i])res1 = MAXll;
            if(blkant1[i])res1 = MAXll;
            res1 += nums1[i];
            res2 += nums1[i+1];
        }
        else{
            if(blkprox1[i])res2 = MAXll;
            if(blkant1[i])res2 = MAXll;
            res1 += nums1[i+1];
            res2 += nums1[i];
        }
    }
    return min(res1,res2);
}

void solve(){
    int n;
    cin>>n;
    ll mat[n][n];
    fore(i,0,n)input(mat[i]);
    vector<ll> as(n),bs(n);
    input(as);input(bs);
    vector<ll> cf(n,0),cc(n,0);
    fore(i,0,n-1){
        //ver si hay problema en esta fila/columna
        fore(j,0,n)if(mat[i][j]==mat[i+1][j]){
            cf[i] = as[i]; cf[i+1] = as[i+1];
        }
        fore(j,0,n)if(mat[j][i]==mat[j][i+1]){
            cc[i] = bs[i]; cc[i+1] = bs[i+1];
        }
    }
    vector<int> blkprox1(n,0), blkant1(n,0), blkprox2(n,0), blkant2(n,0);
    fore(i,0,n-1){
        //ver si hay problema en esta fila/columna
        fore(j,0,n)if(mat[i][j]==mat[i+1][j]+1){
            blkprox1[i] = true;
        }
        fore(j,0,n)if(mat[j][i]==mat[j][i+1]+1){
            blkprox2[i] = true;
        }
    }
    fore(i,1,n){
        //ver si hay problema en esta fila/columna
        fore(j,0,n)if(mat[i][j]==mat[i-1][j]+1){
            blkant1[i] = true;
        }
        fore(j,0,n)if(mat[j][i]==mat[j][i-1]+1){
            blkant2[i] = true;
        }
    }
    vector<ll> nums1;
    vector<int> blkprox, blkant;
    ll res = 0;
    fore(i,0,n){
        if(cf[i]==0 && SZ(nums1)>0){
            ll temp = f(nums1,blkprox,blkant);
            if(temp>=MAXll){show(-1);return;}
            res += temp;
        }
        else{
            nums1.pb(cf[i]);
            blkprox.pb(blkprox1[i]);
            blkant.pb(blkant1[i]);
        }
    }
    ll temp = f(nums1, blkprox, blkant);
    if(temp==-1){show(-1);return;}
    res += temp;
    nums1.clear();blkprox.clear();blkant.clear();
    fore(i,0,n){
        if(cc[i]==0 && SZ(nums1)>0){
            ll temp = f(nums1,blkprox,blkant);
            if(temp>=MAXll){show(-1);return;}
            res += temp;
        }
        else{
            nums1.pb(cc[i]);
            blkprox.pb(blkprox2[i]);
            blkant.pb(blkant2[i]);
        }
    }
    temp = f(nums1, blkprox, blkant);
    if(temp==-1){show(-1);return;}
    res += temp;
    show(res);
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"