#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define all(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define show(a) cout<<a<<'\n'
#define showAll(a) for(auto b: a)cout<<b<<" ";cout<<'\n'
#define pb push_back
#define pii pair<int,int>
#define input(a) for(auto& i:a) cin>>i
#define RAYA cout<<"--------------\n";
typedef long long ll;
using namespace std;

int N,M;

bool valid(int i, int j){
    return (i>=0 && i<N && j>=0 && j<M);
}

bool is(vector<pii> &f, int i, int j, vector<string> &B){
    for(auto e: f){
        int ni = i+e.first, nj = j+e.second;
        if((!valid(ni,nj))||B[ni][nj]!='#'){
            return false;
        }
    }
    return true;
}

void fill(vector<pii> &f, int i, int j, vector<string> &B){
    for(auto e: f){
        int ni = i+e.first, nj = j+e.second;
        B[ni][nj] = 'X';
    }
}

int main(){
    FIN;
    cin>>N>>M;
    vector<string> B(N);
    input(B);
    vector<int> res(3,0);
    vector<pii> T = {{0,0},{-1,0},{-2,0},{-3,0},{-4,0},{-4,1},{-4,-1}};
    vector<pii> A = {{0,0},{-1,0},{-2,0},{-3,0},{-4,0},{0,-2},{-1,-2},{-2,-2},{-3,-2},{-4,-2},{-4,-1},{-2,-1}};
    vector<pii> P = {{0,0},{-1,0},{-2,0},{-3,0},{-4,0},{-4,1},{-4,2},{-3,2},{-2,2},{-2,1}};
    vector<vector<pii>> TAP = {A,P,T};
    dfore(i,N-1,4)dfore(j,M-1,0){
        fore(k,0,3){
            if(is(TAP[k],i,j,B)){
                ++res[k];
                fill(TAP[k],i,j,B);
            }
        }
    }
    cout<<res[2]<<" "<<res[0]<<" "<<res[1]<<'\n';
    return 0;
}