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
#define MAXN 200005
#define ALPH 26
#define M 1000000007
#define fst first
#define snd second
#define STRLEN 4
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



int main(){
    string s;
    cin>>s;
    s+="$";
    vector<int> p = constructSA(s);
    int t, m, l, r;
    cin>>t;
    while(t--){
        string cmp;
        cin>>cmp;
        l = -1; r = p.size();
        while(l<r - 1){
            m = (l+r)/2;
            int i = 0;
            while(i < cmp.size() && s[(p[m] + i)%s.size()] == cmp[i]){
                ++i;
            }
            bool is_bigger = i==cmp.size() || s[(p[m] + i)%s.size()] > cmp[i];
            if(is_bigger){
                r = m;
            }
            else{
                l = m;
            }
        }
        bool are_equal = true;
        fore(i,0,cmp.size()){
            are_equal = cmp[i]==s[(p[r] + i)%s.size()] && are_equal;
        }
        if(are_equal){
            show("Yes");
        }
        else{
            show("No");
        }
    }
}