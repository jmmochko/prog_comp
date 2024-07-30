#include<bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second
#define ll long long
#define pb push_back
#define forn(a,b,c) for(int a=b;a<c;a++)
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DBG(a) cout<<#a<<" = "<<a<<"\n"
#define jump cout<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define MAXN 100005

int main(){
    FIN;
    //ifstream cin("input.txt");
    ll n,k,aux,tot=0; cin>>n>>k;
    vector<ll> a;
    forn(i,0,n){
        cin>>aux;
        a.pb(aux);
        tot+=aux;
    }

    string s; cin>>s;
    priority_queue<ll,deque<ll>,greater<ll> > pq;
    pq.push(a[0]);
    ll act=1;
    forn(i,1,n){
        if(s[i] == s[i-1]){
            if(i==n-1){
                pq.push(a[i]);
                act++;
                if(act>=k){
                    while(act>k){
                        tot-=pq.top();
                        pq.pop();
                        act--;
                    }
                }
            }
            pq.push(a[i]);
            act++;
        }else{
            if(act>=k){
                while(act>k){
                    tot-=pq.top();
                    pq.pop();
                    act--;
                }
            }
            act=1;
            while(!pq.empty()) pq.pop();
            pq.push(a[i]);
        }
    }
    show(tot);
    //system("pause");
    //cin.close()
    return 0;
}