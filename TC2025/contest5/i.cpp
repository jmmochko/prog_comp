#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first 
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back
#define DGB(a) cout<<#a<<" = "<<a<<'\n';
using namespace std;
typedef long long ll;
#define INF 1e6
#define oper(a,b)  a+b
#define NEUT 0
struct STree
{
    vector<int> st; int n;
    STree(int n): st(4*n+5,NEUT), n(n) {}
    void init(int k, int s, int e, int *a){
        if(s+1==e){st[k]=a[s];return;}
        int m = (s+e)/2;
        init(2*k,s,m,a); init(2*k+1,m,e,a);
        st[k]=oper(st[2*k], st[2*k+1]);
    }
    void upd(int k, int s, int e, int p, int v){
        if(s+1==e){st[k]=v;return;}
        int m = (s+e)/2;
        if(p<m) upd(2*k,s,m,p,v);
        else upd(2*k+1,m,e,p,v);
        st[k] = oper(st[2*k],st[2*k+1]);
    }
    int query(int k, int s, int e, int a, int b){
        if(s>=b || e<=a) return NEUT;
        if(s>=a && e <= b) return st[k];
        int m=(s+e)/2;
        return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
    }
    void init(int *a){init(1,0,n,a);}
    void upd(int p, int v){upd(1,0,n,p,v);}
    int query(int a, int b){return query(1,0,n,a,b);}
};


int main(){
    FIN;
    int n;
    cin>>n;
    int nums[n];
    fore(i,0,n){
        cin>>nums[i];
        nums[i] = min(nums[i],n);
    }
    vector<pair<int,int>> ord(n);//<nums[i],i>
    fore(i,0,n)ord[i] = {nums[i],i};
    sort(all(ord));
    //calculo >= i atras mio
    STree st(n+1);
    int i = 0;
    ll res = 0;
    fore(k,0,n){
        //agrego al st los numeros en posisciones hasta ord[i].fst
        while(i<n && i<ord[k].fst){
            st.upd(nums[i],st.query(nums[i],nums[i]+1) + 1);
            ++i;
        }
        res += st.query(ord[k].snd + 1,n+1);
    }
    fore(i,0,n)if(nums[i]>i)--res;
    cout<<res/2<<'\n';
    return 0;
}