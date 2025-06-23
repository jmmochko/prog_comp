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

ll mx(vector<pii> &nums){
    int acc = 0, acc2 = 0;
    fore(i,0,SZ(nums)){
        if(!nums[i].snd)++acc;
    }
    int res = acc;
    int i = SZ(nums)-1;
    while(i>0){
        if(!nums[i].snd)--acc;
        else ++acc2;
        --i;
        res = max(res,acc + acc2);
    }
    return max(res,acc2);
}

int main(){
    FIN;
    int n;
    cin>>n;
    vector<pii> s(n),l(n);
    fore(i,0,n){
        cin>>s[i].fst>>l[i].fst;
        char e;
        cin>>e;
        if(e=='b'){
            s[i].snd = 0;
            l[i].snd = 0;
        }
        else{
            s[i].snd = 1;
            l[i].snd = 1;
        }
    }
    sort(all(s));sort(all(l));
    ll res = max(mx(s),mx(l));
    fore(i,0,n){
        s[i].snd = 1-s[i].snd;
        l[i].snd = 1-l[i].snd;
    }
    res = max({res,mx(s),mx(l)});
    show(res);
    return 0;
}

//Cue "Eye of the Tiger"