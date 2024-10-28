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

bool cmp(string &q, string &s, int i, int qi){
    while(qi<SZ(q) && i<SZ(s)){
        if(q[qi]>s[i])return false;
        if(q[qi]<s[i])return true;
        ++qi;
        ++i;
    }
    return false;
}

int main(){
    FIN;
    string s;
    cin>>s;
    s.push_back('$');
    vector<int> sa = constructSA(s);
    string q;
    int n;
    cin>>n;
    fore(i,0,n){
        int res = 0;
        cin>>q;
        int qi = 0;
        while(qi<SZ(q)){
            int cur = qi;
            int l=0,r = SZ(s)-1;
            while(l+1<r){
                int m = (r+l)/2;
                if(cmp(q,s,sa[m],qi)){
                    r = m;
                }
                else l = m;
            }
            int i = sa[l];
            if(q[qi] != s[i]){
                i = sa[r];
            }
            if(r<SZ(s) && q[qi] != s[i]){
                res = -1;
                break;
            }
            while(qi<SZ(q) && i<SZ(s) && s[i]==q[qi]){
                ++i;
                ++qi;
            }
            i = sa[r];
            swap(cur,qi);
            while(qi<SZ(q) && i<SZ(s) && s[i]==q[qi]){
                ++i;
                ++qi;
            }
            qi = max(cur,qi);
            ++res;
        }
        show(res);
    }
    return 0;
}