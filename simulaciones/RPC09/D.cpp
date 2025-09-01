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

const double EPS = 1e-6;
//El Vasito is love, El Vasito is life

vector<double> brute(double p, double r, double y){
    vector<double> res = {1,1,1,1};
    double ww,ss,ee,nn;
    ww = y/4.0000;
    ss = ww;
    ee = ww;
    nn = ww;
    ee += p/2.00;
    ww -= p/2.00;
    nn += r/2.00;
    ss -= r/2.00;
    double c = -1;
    double best = 199;
    while(c - EPS<=1){
        double n = nn - c,e = ee + c,w = ww + c, s = ss - c;
        if(max({abs(n),abs(s),abs(e),abs(w)}) < best){
            res = {n,e,s,w};
            best = max({abs(n),abs(s),abs(e),abs(w)});
        }
        c += EPS;
    }
    return res;
}

vector<double> solve(double p, double r, double y){
    //FIN;
    //p = e − w
    //r = n − s
    //y = n + e + s + w
    double ww,ss,ee,nn;
    ww = y/4.0000;
    ss = ww;
    ee = ww;
    nn = ww;
    ee += p/2.00;
    ww -= p/2.00;
    nn += r/2.00;
    ss -= r/2.00;
    //aca se cumple todo
    //cout<<setprecision(8)<<fixed<<n<<" "<<e<<" "<<s<<" "<<w<<'\n';
    //puedo hacer
    // e += c, w += c, n -= c, s -= c
    //igualo n con e
    double best = 1;
    vector<double> res = {nn,ee,ss,ww};
    vector<double> rres = {nn,ee,ss,ww};
    //showAll(res);
    fore(i,0,4)fore(j,0,4){
        double c;
        if((rres[j],rres[i])>=0)c = (max(rres[j],rres[i]) - min(rres[j],rres[i]))/2.00;
        else c = (min(rres[j],rres[i]) - max(rres[j],rres[i]))/2.00;
        c = rres[j] - c;
        DGB(i);DGB(j);
        //if(ee<nn) c = -c;
        DGB(rres[i]);DGB(rres[j]);DGB(c);
        vector<double> pres = {nn-c,ee+c,ss-c,ww+c};
        showAll(pres);
        double cur = abs(pres[0]);
        fore(k,1,4)cur = max(cur,abs(pres[k]));
        if(cur<best){
            best = cur;
            res = pres;
        }
        pres = {nn+c,ee-c,ss+c,ww-c};
        cur = abs(pres[0]);
        fore(k,1,4)cur = max(cur,abs(pres[k]));
        if(cur<best){
            best = cur;
            res = pres;
        }showAll(pres);RAYA;
    }
    return res;
}
// x y -> x += c, y -= c

int main(){
    //FIN;
    int nn; cin>>nn;
    cout<<setprecision(10)<<fixed;
    uniform_real_distribution<double> unif(-1,1);
    default_random_engine re;
    fore(i,0,nn){
        double p,r,y;
        //cin>>p>>r>>y;
        p = unif(re);
        r = unif(re);
        y = unif(re);
        vector<double> rb = brute(p,r,y); 
        vector<double> sv = solve(p,r,y); 
        double mx1 = 0, mx2 = 0;
        fore(i,0,4){mx1 = max(mx1,abs(rb[i]));mx2 = max(mx2,abs(sv[i]));}
        DGB(p);DGB(r);DGB(y);DGB(mx1);DGB(mx2);showAll(rb);showAll(sv);RAYA;
        //assert(mx1 + EPS >= mx2 && mx1 - EPS <= mx2);
    }
}

/*
int main(){
    FIN;
    int nn; cin>>nn;
    cout<<setprecision(10)<<fixed;
    fore(i,0,nn){
        double p,r,y;
        cin>>p>>r>>y;
        vector<double> sv = solve(p,r,y); 
        showAll(sv);
    }
}*/
//Sobrevivimos al pabellon