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
    typedef pair<ll,ll> pll;
     
    struct Tree {
    	typedef long double T;
    	static constexpr T neut = 0.0;
    	T f(T a, T b) { return (a + b); } 
    	vector<T> s; ll n;
    	Tree(ll n = 0, T def = neut) : s(2*n, def), n(n) {}
    	void upd(ll pos, T val) {
    		for (s[pos += n] = val; pos /= 2;)
    			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    	}
    	T query(ll b, ll e) { 
    		T ra = neut, rb = neut;
    		for (b += n, e += n; b < e; b /= 2, e /= 2) {
    			if (b % 2) ra = f(ra, s[b++]);
    			if (e % 2) rb = f(s[--e], rb);
    		}
    		return f(ra, rb);
    	}
    };
     
    int main(){
        FIN;
        long double n,a,b; cin >> n >> a >> b;
        long double tot = (b-a)+1.0;
        if(tot==1){
            long double res = n/b;
            cout << setprecision(10) << fixed << res << '\n';
            return 0;
        }
        Tree st(4*1000000);
        if(a==0){
            dfore(i,n-1,0){
                long double st_i = (tot/(tot-1.0)) + (1.0/(tot-1.0)) * (st.query(i+1.0, i+tot));
                st.upd(i,st_i);
            }
        } else{
            dfore(i,n-1,0){
                long double st_i = 1.0 + (1.0/(tot)) * (st.query(i+a, i+b+1.0));
                st.upd(i,st_i);
            }
        }
        cout << setprecision(10) << fixed << st.query(0,1) << '\n';
        return 0;
    }