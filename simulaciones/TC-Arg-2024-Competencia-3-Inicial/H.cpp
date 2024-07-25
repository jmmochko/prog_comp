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

int main(){

    while(1){
        string inp; cin >> inp;
        if(inp[0] == 'm' || inp[0] == 'e'){
            break;
        }else{
            // ll cnt = 0;
            ll a=0,b=1;
            cout << "? " << a << " " << b << "\n";
            fflush(stdout);
            cin >> inp;
            // cnt++;
            // cout << "counter: " << cnt << "\n";
            if(inp[0] == 'x') cout << "! 1\n"; // caso base
            else{
                fore(i,0,30){
                    // cnt++;
                    // RAYA;
                    a = 1LL << i, b = 1LL << (i+1);
                    cout << "? " << a << " " << b << "\n";
                    // cout << "counter: " << cnt << "\n";
                    fflush(stdout);
                    cin >> inp;
                    if(inp[0] == 'x') break; // encontre los bordes
                }
                while(a+1<b){
                    // cnt++;
                    // RAYA;
                    // cout << "counter: " << cnt << "\n";
                    ll m = (a+b)/2;
                    cout << "? " << a << " " << m << "\n";
                    fflush(stdout);
                    cin >> inp;
                    if(inp[0] == 'x') b = m;
                    else  a = m;
                }
                cout << "! " << a+1 << "\n";
                fflush(stdout);

            }
        }
    }


    return 0;
}

//A man may play the dutch defense but must never defend the dutch.
