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

int main(){
    FIN;
    int n;
    cin>>n;
    int nums[n];
    input(nums);
    int q;
    cin>>q;
    vector<pair<pii,int>> qs(q);
    fore(i,0,q){
        cin>>qs[i].fst.fst>>qs[i].fst.snd;
        --qs[i].fst.fst;--qs[i].fst.snd;
        //DGB(qs[i].fst.fst);DGB(qs[i].fst.snd);DGB(i);RAYA;
        qs[i].snd = i;
    }
    sort(all(qs));
    int que = 0;
    vector<int> res(q,0);
    //precalc
    fore(i,0,n-1){
        if(i<qs[que].fst.fst)continue;
        while(i>qs[que].fst.fst)++que;
        set<int> cur;
        cur.insert(nums[i]);
        cur.insert(-10000000);
        cur.insert(1000000000);
        int mx = MAXINT;
        fore(j,i+1,n){
            if(cur.count(nums[j]) || mx==0){
                break;
            }
            auto itprev = cur.lower_bound(nums[j]);
            auto itpos = itprev;
            --itprev;
            int prev = *itprev, pos = *itpos;
            mx = min(mx,min(abs(prev-nums[j]),abs(pos-nums[j])));
            //DGB(i);DGB(j);DGB(mx);DGB(que);
            while(qs[que].fst.fst==i && qs[que].fst.snd==j){
                //DGB(qs[que].snd);DGB(mx);
                res[qs[que].snd] = mx;
                ++que;
            }
            cur.insert(nums[j]);
        }
        //RAYA;
    }
    fore(i,0,q){
        show(res[i]);
    }
    return 0;
}

//Cue "Eye of the Tiger"
// a[i][j] = rta en ese rango
// a[i][j+1] = min(a[i][j],lb(set[i]-nums[j]),ub(set[i]-nums[j]))