#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b; a<c; ++a)
#define all(a) a.begin(),a.end()
#define SZ(a) (int)a.size()
#define show(a) cout<<a<<'\n'
#define showAll(a) for(auto b: a)cout<<b<<" ";cout<<'\n'
#define pb push_back
typedef long long ll;
using namespace std;

void solve(){
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n);
    fore(i,0,n) cin >> a[i];
    sort(all(a));
    vector<ll> res;
    vector<int> p;//pos such that it breaks;
    fore(i,0,n-1){
        if(a[i]+a[i+1]==x)p.push_back(i);
    }
    if(SZ(p)==0){
        showAll(a);
        return;
    }
    else if(SZ(p)==1){
        if(SZ(a)==2){
            show('*');
            return;
        }
        else{
            if(a[p[0]+1]!=a[n-1]){
                swap(a[p[0]+1],a[n-1]);
                showAll(a);
            }
            else if(a[0]!=a[p[0]]){
                swap(a[0],a[p[0]]);
                showAll(a);
            }
            else{
                show('*');
            }
            return;
        }
    }
    //---(izq)XXXX(der)---
    int izq = p[0]-1, der = p[SZ(p)-1]+2;
    if(SZ(p)>n-(SZ(p)+1)){
        show("*");
        return;
    }
    for(int i = 0; i<SZ(p)-1; i++){
        if(izq>=0){
            cout<<a[p[i]]<<" "<<a[izq]<<" ";
            izq--;
        }
        else if(der<n){
            cout<<a[p[i]]<<" "<<a[der]<<" ";
            der++;
        }
    }
    cout<<a[p[0]]<<" ";
    int print = 0;
    for(int i = izq; i>=0; --i){
        print++;
        cout<<a[i]<<" ";
    }
    if(print!=0) cout<<a[p[0]]<<' ';
    fore(i,der,SZ(a)){
        cout<<a[i]<<" ";
    }
    if(print==0) cout<<a[p[0]];
    cout<<'\n';
}

int main(){
    FIN;
    solve();
    return 0;
}
