#include <bits/stdc++.h>
#define fore(a,b,c) for(int a = b; a<c; ++a)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second 
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;

int main(){
    FIN;
    double pi = 3.141592653589793;
    double n,r;
    cin >> n >> r;
    double alpha = n/360;
    double beta = (180-alpha)/2;
    alpha = alpha * pi / double(180);
    beta = beta * pi / double(180);
    double res = r/(((2*sin(beta))/sin(alpha))-1);
    cout << setprecision(6) << fixed << res << "\n";
    return 0;
}