#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fore(a,b,c) for(int a=b; a<c;++a)
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAXN 400005
#define ALPH 26
#define M 1000000007
#define fst first
#define snd second
#define PI 3.141592653
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

int posinsa[MAXN];

#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	fore(i,0,n)f[RB(i+k)]++;
	int sum=0;
	fore(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	fore(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}

vector<int> constructSA(string& s){ // O(n logn)
	int n=s.size(),rank;
	vector<int> sa(n),r(n),t(n);
	fore(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0);
		t[sa[0]]=rank=0;
		fore(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	return sa;
}

vector<int> computeLCP(string& s, vector<int>& sa){
	int n=s.size(),L=0;
	vector<int> lcp(n),plcp(n),phi(n);
	phi[sa[0]]=-1;
	fore(i,1,n)phi[sa[i]]=sa[i-1];
	fore(i,0,n){
		if(phi[i]<0){plcp[i]=0;continue;}
		while(s[i+L]==s[phi[i]+L])L++;
		plcp[i]=L;
		L=max(L-1,0);
	}
	fore(i,0,n)lcp[i]=plcp[sa[i]];
	return lcp; // lcp[i]=LCP(sa[i-1],sa[i])
}

#define oper min
#define K 19
int st[K][1<<K];int n;  // K such that 2^K>n
void st_init(int *a){
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
//0 0 1 3 1 0 2 0
bool cmp(pii a, pii b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	bool tiebreak = a.first < b.first;
	int posa = posinsa[a.first], posb = posinsa[b.first];
	if(posa < posb){
		if(st_query(posa + 1, posb + 1) >= (b.second - b.first) + 1){
			if((a.second - a.first) == (b.second - b.first)){
				return tiebreak;
			}
			return (a.second - a.first) < (b.second - b.first);
		}
		else{
			return true;
		}
	}
	else{
		if(st_query(posb + 1, posa + 1) >= (a.second - a.first) + 1){
			if((a.second - a.first) == (b.second - b.first)){
				return tiebreak;
			}
			return (a.second - a.first) < (b.second - b.first);
		}
		else{
			return false;
		}
	}
	return tiebreak;
}


int main(){
	FIN;
	string s;
	cin>>s;
	s+="$";
	n = s.length();
	int q;
	cin>>q;
	vector<pii> qs(q);
	fore(i,0,q){
		cin>>qs[i].first>>qs[i].second;
		--qs[i].first;--qs[i].second;
	}
	vector<int> sa = constructSA(s);
	vector<int> lcp = computeLCP(s,sa);
	int lcpcopy[n];
	fore(i,0,n){
		lcpcopy[i] = lcp[i];
	}
	st_init(lcpcopy);
	fore(i,0,n){
		posinsa[sa[i]] = i;
	}
	sort(all(qs),cmp);
	fore(i,0,q){
		cout<<++qs[i].first<<" "<<++qs[i].second<<'\n';
	}
    return 0;
}