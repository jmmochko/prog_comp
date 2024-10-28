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

#define oper(a,b) min(a,b)
#define NEUT MAXll //Operation 
#define LNEUT 0 //Neutral chosen for lazy op
struct STree { // min with range sum
	vector<ll> st,lazy;int n;
	STree(int n): st(4*n+5,NEUT), lazy(4*n+5,LNEUT), n(n) {}
	void init(int k, int s, int e, ll *a){
		lazy[k]=LNEUT;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]); // operation
	}
	void push(int k, int s, int e){
		if(lazy[k]==LNEUT)return; // if neutral, nothing to do
		st[k]+=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=LNEUT; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]); // operation
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(int a, int b, ll v){upd(1,0,n,a,b,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

void solve(){
    int n;
    cin>>n;
    vector<pair<pll,int>> nums(n);//<<D,T>,i>
    fore(i,0,n){
        cin>>nums[i].first.second>>nums[i].first.first;
        nums[i].second = i;
    }
    sort(all(nums));
    //check if possible
    ll acc = 0;
    vector<int> pos(n), t(n);
    fore(i,0,n){
        t[i] = acc;
        acc += nums[i].first.second;
        if(acc>nums[i].first.first){
            show('*');
            return;
        }
        pos[nums[i].second] = i;
    }
    //lazy st <tiempo de sobra al llegar a pos i>
    ll to_st[n];
    fore(i,0,n){
        to_st[i] = nums[i].first.first - (t[i] + nums[i].first.second);
    }
    STree st(n);
    st.init(to_st);
    vector<int> res(n);
    set<int> to_place;
    fore(i,0,n)to_place.insert(i);
    fore(placed,0,n){
        for(auto i: to_place){
            if(st.query(0,pos[i])<nums[i].first.second){
                continue;
            }
            st.upd(0,pos[i],-nums[i].first.second);
            st.upd(pos[i],pos[i]+1,MAXll);
            res[placed] = i+1;
            to_place.erase(i);
            break;
        }
    }
    showAll(res);
}

int main(){
    FIN;
    int t = 1;
    //cin>>t;
    while(t--)solve();
    return 0;
}

//Sale regional?