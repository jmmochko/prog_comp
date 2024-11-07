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

#define EPS 0 // lower EPS for smaller numbers

//El Vasito is love, El Vasito is life

struct pt {  // for 3D add z coordinate
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	ll norm2(){return *this**this;}
	ll norm(){return sqrt(norm2());}
	bool operator==(pt p){return x==p.x&&y==p.y;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p)const {return pt(x-p.x,y-p.y);}
	pt operator*(ll t){return pt(x*t,y*t);}
	pt operator/(ll t){return pt(x/t,y/t);}
	ll operator*(pt p){return x*p.x+y*p.y;}
	ll angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	ll operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(ll a){return rot(pt(sin(a),cos(a)));}
};

struct Cmp { // IMPORTANT: add const in pt operator-
	pt r;
	Cmp(pt r):r(r){}
	int cuad(const pt &a)const {
		if(a.x>0&&a.y>=0)return 0;
		if(a.x<=0&&a.y>0)return 1;
		if(a.x<0&&a.y<=0)return 2;
		if(a.x>=0&&a.y<0)return 3;
		assert(a.x==0&&a.y==0);
		return -1;
	}
	bool cmp(const pt& p1, const pt& p2)const {
		int c1=cuad(p1),c2=cuad(p2);
		if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
		return c1<c2;
	}
	bool operator()(const pt& p1, const pt& p2)const {
		return cmp(p1-r,p2-r);
	}
};

pt centro(0,0);

Cmp coso(centro);

bool compare(pair<pt,bool> a, pair<pt,bool> b){
	if(coso.cmp(a.first,b.first))return true;
	return false;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<int,pii>> nums(n);
    fore(i,0,n){
        cin>>nums[i].second.first>>nums[i].second.second>>nums[i].first;
    }
    sort(all(nums));
    vector<pair<pt,bool>> cmp;
    fore(i,0,n-1){
        fore(j,i+1,n){
            if(nums[i].first == nums[j].first || nums[i].second == nums[j].second)continue;
            pt diff = pt(nums[j].second.first - nums[i].second.first, nums[j].second.second - nums[i].second.second);
            pt dir = pt(-diff.y, diff.x);
            pt cierra = pt(-dir.x,-dir.y);
            cmp.push_back({dir,true});
            cmp.push_back({cierra,false});
        }
    }
	if(SZ(cmp)==0){
        show("Y");
    	return;
    }
    sort(all(cmp),compare);
    ll cnt = 0; 
	bool accneg = 0;
	ll accpos = 0;
	pt prev = cmp[0].first;
    fore(i,0,2*SZ(cmp)){
        pt next = cmp[i%SZ(cmp)].first;
		if(next == prev){
			if(cmp[i%SZ(cmp)].second){
				++cnt;
				++accpos;
			}
			else accneg = true;
		}
		else{
			if(cnt == SZ(cmp)/2){
            	show("Y");
            	return;
        	}
			if(accneg)cnt = accpos;
			accneg = false;
			accpos = 0;
			if(cmp[i%SZ(cmp)].second){
				++cnt;
				++accpos;
			}
			else accneg = true;
		}
		if(cnt == SZ(cmp)/2){
        	show("Y");
        	return;
        }
		prev = next;
    }
    show("N");
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?

// <x,y> X <nums[i].fst,nums[i].snd> = x 