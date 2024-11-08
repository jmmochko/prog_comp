#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ThxDem=b;i<ThxDem;++i)
#define dfore(a,b,c) for(int a=b; a>=c; --a)
#define DGB(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) ll(s.size())
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

typedef long double td; typedef vector<int> vi; typedef vector<td> vd;
const td INF=1e100;//for maximum set INF to 0, and negate costs
bool zero(td x){return fabs(x)<1e-9;}//change to x==0, for ints/ll
struct Hungarian{
    int n; vector<vd> cs; vi L, R;
    Hungarian(int N, int M):n(max(N,M)),cs(n,vd(n)),L(n),R(n){
        fore(x,0,N)fore(y,0,M)cs[x][y]=INF;
    }
    void set(int x,int y,td c){cs[x][y]=c;}
	td assign() {
		int mat = 0; vd ds(n), u(n), v(n); vi dad(n), sn(n);
		fore(i,0,n)u[i]=*min_element(ALL(cs[i]));
		fore(j,0,n){v[j]=cs[0][j]-u[0];fore(i,1,n)v[j]=min(v[j],cs[i][j]-u[i]);}
		L=R=vi(n, -1);
		fore(i,0,n)fore(j,0,n)
			if(R[j]==-1&&zero(cs[i][j]-u[i]-v[j])){L[i]=j;R[j]=i;mat++;break;}
		for(;mat<n;mat++){
		    int s=0, j=0, i;
		    while(L[s] != -1)s++;
		    fill(ALL(dad),-1);fill(ALL(sn),0);
		    fore(k,0,n)ds[k]=cs[s][k]-u[s]-v[k];
		    for(;;){
		        j = -1;
		        fore(k,0,n)if(!sn[k]&&(j==-1||ds[k]<ds[j]))j=k;
		        sn[j] = 1; i = R[j];
		        if(i == -1) break;
		        fore(k,0,n)if(!sn[k]){
		            auto new_ds=ds[j]+cs[i][k]-u[i]-v[k];
		            if(ds[k] > new_ds){ds[k]=new_ds;dad[k]=j;}
		        }
		    }
		    fore(k,0,n)if(k!=j&&sn[k]){auto w=ds[k]-ds[j];v[k]+=w,u[R[k]]-=w;}
		    u[s] += ds[j];
		    while(dad[j]>=0){int d = dad[j];R[j]=R[d];L[R[j]]=j;j=d;}
		    R[j]=s;L[s]=j;
		}
		td value=0;fore(i,0,n)value+=cs[i][L[i]];
		return value;
	}
};

int main(){
    FIN;
    ll n; cin >> n;
    ll nn = n/2 + n%2;
    ll newn = n + n%2;
    vector<vector<ll>> m(newn);
    fore(i,0,n) { fore(j,0,n){
        ll aux; cin >> aux;
        m[i].pb(aux);
    } 
    m[i].pb(0);
    }
    Hungarian h(n/2,nn);

    vector<vector<ll>> mm(nn,vector<ll>(nn));


    // quiero que la posicion 1 de mis matrices sea el costo hacia la 2,
    // despues necesito sumar el costo de la 2 a la 3 + el viaje hasta la 4
    
    for(ll i = 1; i < n+1; i+=2){ // pares
        ll p1=0,p2=0;
        for(ll j = 0; j < n; j+=2){ // impares
        // cout << "Calc: " << i << " " << j << "\n";
            p2 = m[j][i]; // lo q tarda hasta la posicion par
            if(i!=1){
                p1 = m[i-2][j]; // lo q tarde hasta venir
            }
            // cout << "Setting: " << i/2 << " " << j/2 << "\n";
            h.set(i/2,j/2,(p1+p2));
            // show(p1+p2);
            mm[i/2][j/2] = p1+p2;
        }
    }
    // cout << "termina\n";
    // fore(i,0,nn){
    //      fore(j,0,nn){
    //         cout << mm[i][j] << " \n";
    //      }
    //      cout << "\n";
    // }
    cout << h.assign() << '\n';
    return 0;
}

// muchas gracias pennazzi