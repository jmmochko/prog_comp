#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a = b; a<c; ++a)
#define ALL(a) a.begin(),a.end()
#define snd second
#define fst first
#define pii pair<int,int>
using namespace std;
typedef long long ll;

int block;

bool cmp(pair<pii,int> &a, pair<pii,int> &b){
    if(a.fst.snd/block != b.fst.snd/block){
        return a.fst.snd/block < b.fst.snd/block;
    }
    return a.fst < b.fst;
}

int main(){
    FIN;
    int n,q;
    cin>>n;
    vector<int> nums(n);
    fore(i,0,n)cin>>nums[i];
    cin>>q;
    vector<pair<pii,int>> qs(q);
    fore(i,0,n){cin>>qs[i].fst.fst>>qs[i].fst.snd;--qs[i].fst.fst;--qs[i].fst.snd;qs[i].snd = i;}
    sort(ALL(qs),cmp);
    vector<int> res(q);
    int l=-1,r=-1;
    bool rta = true;
    fore(i,0,q){
        int nl = qs[i].fst.fst, nr = qs[i].fst.snd;
        while(r < nr){
            ++r;
            
        }
    }
    return 0;
}