#include <bits/stdc++.h>
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(a) cout<<a<<"\n"
using namespace std;

#define oper min
#define K 20
int n;  // K such that 2^K>n
int st[K][1<<K];
void st_init(int *a){
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

int main(){
    FIN;
    int q;
    cin>>n>>q;
    int a[n];
    fore(i,0,n)cin>>a[i];
    st_init(a);
    while(q--){
        int l,r;
        cin>>l>>r;
        --l;
        show(st_query(l,r));
    }
    return 0;
}