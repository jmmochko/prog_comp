#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
using namespace std;
typedef long long ll;

const double EPS = 0.0000001;
const double DINF = 1e200;

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

const double pi = acos(-1.00);

double toRad(double a){
    return (pi*a)/(double)180;
}

double dp[1<<20];
int n,l,r;
vector<double> x(n),y(n),a(n);

double cuenta(int i, double desde){
    ln ejeX(pt(0,0),pt(1,0));
    pt lamparita(x[i],y[i]);
    ln rayo(lamparita,pt(desde,0));
}

double f(int i){
    if(i==0)return 0;
    if(dp[i]!=-1)return dp[i];
    dp[i] = 0.000;
    fore(b,0,20){
        if(i & (1<<b)){
            dp[i] = max(dp[i], f(i - (1<<b)) + cuenta(i,f(i - (1<<b))));
        }
    }
}

int main(){
    FIN;
    cin>>n>>l>>r;
    
    fore(i,0,n){
        cin>>x[i]>>y[i]>>a[i];
        a[i] = toRad(a[i]);
    }
    
    return 0;
}