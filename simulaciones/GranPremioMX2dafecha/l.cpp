#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; }

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;



int main(){
    FIN;
    ll n,aux,aux1,res=0;
    cin>>n;
    ll a[n];
    ll indexa[n];
    ll b[n];
    ll indexb[n];

    fore(i,0,n){
        cin>>aux;
        a[i]=aux;
        indexa[aux-1]=i;
    }

    fore(i,0,n){
        cin>>aux;
        b[i]=aux;
        indexb[aux-1]=i;
    }

    fore(i,0,n-1){

        if(a[i]!=i+1){
            aux=indexa[i];
            indexa[i]=i;
            indexa[a[i]-1]=aux;

            aux=a[i];
            a[i]=i+1;
            a[indexa[aux-1]]=aux;
            //cout<<"A";
            res++;
        }
        
    }

    fore(i,0,n-1){

        if(b[i]!=i+1){
            aux=indexb[i];
            indexb[i]=i;
            indexb[b[i]-1]=aux;

            aux=b[i];
            b[i]=i+1;
            b[indexb[aux-1]]=aux;
            res++;
            //imp(b);
            //cout<<"\n";
        }

    }
    
cout<<res;
}