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

//sea a el angulo
//xn+1 = cos(a)xn - sin(a)yn
//yn+1 = sin(a)xn + cos(a)yn

#define EPS 3.1e-6 // lower EPS for smaller numbers
const long double DINF=1e200;

struct pt {  // for 3D add z coordinate
	long double x,y;
	pt(long double x, long double y):x(x),y(y){}
	pt(){}
	long double norm2(){return *this**this;}
	long double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(long double t){return pt(x*t,y*t);}
	pt operator/(long double t){return pt(x/t,y/t);}
	long double operator*(pt p){return x*p.x+y*p.y;}
	pt unit(){return *this/norm();}
	long double operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(long double a){return rot(pt(sin(a),cos(a)));}
    pt normalizar(){
        long double s = abs(x)+abs(y);
        return *this/s;
    }
};

double toRad(double a){
    return (a*2*PI)/360.0000000;
}

void solve(){
    int n;
    long double a,l;
    cin>>a>>l>>n;
    a = toRad(a);
    pt pos(0,0),dir(0,-1),inidir(0,-1),inipos(0,0);
    dir = dir.rot(a);
    int largo = 0;
    while(!(dir == inidir) && largo<n){
        pos = pos + (dir.normalizar())*l;
        dir = dir.rot(a);
        ++largo;
    }
    if(largo==n){
        cout<<setprecision(8)<<fixed<<pos.x<<" "<<pos.y<<'\n';
        return;
    }
    if(largo > 0){
        inipos = pos*(n/largo);
        n = n%largo;
    }
    dir = inidir;
    largo = 0;
    while(largo<n){
        pos = pos + (dir.normalizar())*l;
        dir = dir.rot(a);
        ++largo;
    }
    cout<<setprecision(8)<<fixed<<pos.y<<" "<<pos.x<<'\n';
}

int main(){
    FIN;
    int t = 1;
    cin>>t;
    while(t--)solve();
    return 0;
}

//Cue "Eye of the Tiger"