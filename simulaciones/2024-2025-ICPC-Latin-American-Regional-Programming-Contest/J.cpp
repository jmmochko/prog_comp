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
typedef double ld;

//El Vasito is love, El Vasito is life

ld get_rad(ld ang){
    return (2.000*PI*ang)/360.00000;
}

ld get_l(ld h, ld ang){
    ld res = sin(get_rad(90.00000 - ang))/sin(get_rad(ang));
    return res*h;
}

int main(){
    FIN;
    ld ang;
    int n;
    cin>>ang>>n;
    vector<pair<ll,ll>> nums(n);
    fore(i,0,n){
        cin>>nums[i].first>>nums[i].second;
    }
    sort(all(nums));
    vector<pair<ld,ld>> sl(n);//<empieza, termina>
    fore(i,0,n){
        sl[i] = {nums[i].first,nums[i].first + get_l(nums[i].second,ang)};
    }
    ld res = sl[0].second - sl[0].first, prev = sl[0].second;
    fore(i,1,n){
        res += max(0.00000,sl[i].second - max(prev,sl[i].first));
        prev = max(prev,sl[i].second);
    }
    show(res);
    return 0;
}
//Sale regional?