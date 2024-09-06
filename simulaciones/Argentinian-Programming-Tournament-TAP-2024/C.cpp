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
#define DGBP(a) cout<<#a<<" = ";a.debug();
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

#define EPS 3.1e-10 // lower EPS for smaller numbers
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
	long double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	long double operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(long double a){return rot(pt(sin(a),cos(a)));}
};

int sgn2(long double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	bool segcross(ln l){
		pt itt = (*this)^l;
		if(itt.x == DINF){
			return (l.seghas(p)||l.seghas(pq+p)||(*this).seghas(l.p)||(*this).seghas(l.pq+l.p));
		}
		return (*this).seghas(itt)&&l.seghas(itt);
	}
	long double angle(ln l){return pq.angle(l.pq);}
	int side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	long double dist(pt r){return (r-proj(r)).norm();}
};


int sgn(double x){return x<-EPS?-1:x>EPS;}
struct pol {
	int n;vector<pt> p;
	pol(){}
	pol(vector<pt> _p){p=_p;n=p.size();}
	int has(pt q){
		fore(i,0,n)if(ln(p[i],p[(i+1)%n]).seghas(q))return 2; // minor change to distinguish on and in
		int cnt=0;
		fore(i,0,n){
			int j=(i+1)%n;
			int k=sgn((q-p[j])%(p[i]-p[j]));
			int u=sgn(p[i].y-q.y),v=sgn(p[j].y-q.y);
			if(k>0&&u<0&&v>=0)cnt++;
			if(k<0&&v<0&&u>=0)cnt--;
		}
		return cnt!=0;
	}
};

int main(){
    ll n,ax,ay,az,sx,sy,sz;
    cin>>n;
    cin>>ax>>ay>>az;
    cin>>sx>>sy>>sz;
    vector<pt> base(n);
    fore(i,0,n){
        cin>>base[i].x>>base[i].y;
    }
    pol basePol(base);
    //find where the line from the apex to the sun intersects the ground
    double iz = sz/(az-sz);
    pt ci;
    ci.x = sx + iz*(ax-sx);
    ci.y = sy + iz*(ay-sy);
    //check if ci is inside basePol
    if(!basePol.has(ci)){
        show("S");
        return 0;
    }
    pt sol(sx,sy),cus(ax,ay);
    //for each line base[i] ---> ci, check if its fully in basePol
    fore(i,0,n){
        if(sol<cus && base[i]<sol){
            continue;
        }
        if(cus<sol && sol<base[i]){
            continue;
        }
        //check if midpoint is inside
        pt md = (ci+base[i])/2;
        if(!basePol.has(md)){
            show("S");
            return 0;
        }
        ln check(base[i],ci);
        //check if it intersects any side of basePol
        bool res = false;
        fore(j,0,n){
			if(j==i||(j+1)%n==i)continue;
            ln ld(base[j],base[(j+1)%n]);
            if(ld.segcross(check)){
                show("S");
                return 0;
            }
        }
    }
    show("N");
    return 0;
}