#include <bits/stdc++.h>
#define fore(a,b,c) for(int a = b; a<c; ++a)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second 
#define all(a) a.begin(),a.end()
#define M 1000000009
using namespace std;
typedef long long ll;
#define bint __int128
struct Hash {
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	vector<bint> h,pi;
	Hash(string& s){
		assert((P*PI)%MOD==1);
		h.resize(s.size()+1);pi.resize(s.size()+1);
		h[0]=0;pi[0]=1;
		bint p=1;
		fore(i,1,s.size()+1){
			h[i]=(h[i-1]+p*s[i-1])%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
		}
	}
	ll get(int s, int e){
		return (((h[e]-h[s]+MOD)%MOD)*pi[s])%MOD;
	}
};

int main(){
    FIN;
    string s,t;
    cin>>s>>t;
    int n = s.size(),m = t.size();
    if(m<n){
        cout<<"0\n";
        return 0;
    }
    if(s[0]=='0'){
        fore(i,0,n){
            if(s[i]=='0')s[i] = '1';
            else s[i] = '0';
        }
    }
    int cnt = 0;
    fore(i,0,n)cnt += s[i] - '0';
    Hash hs(t);
    int pcero;
    fore(i,0,n)if(s[i]=='0'){pcero = i; break;}
    // m = i*cnt + j*(n-cnt)
    // m - i*cnt = j*(n-cnt)
    // (m - i*cnt)/(n-cnt) = j
    int res = 0;
    fore(i,1,m/cnt){
        //cout<<i<<'\n';
        //NO ES DIV POR 0
        if((m - i*cnt)%(n-cnt) != 0)continue;
        bool can = true;
        int j = (m - i*cnt)/(n-cnt);
        if(j<=0 || ((j*(n-cnt) + i*cnt) != m))continue;
        //NO ES ESTO
        ll huno = hs.get(0,i), hero = hs.get(pcero*i, i*pcero + j);
        if(huno == hero)continue;
        int pt = 0, ps = 0;
        while(pt<m && ps<n){
            if(s[ps] == '0'){
                //NO ES ESTO
                ll cmp = hs.get(pt,pt+j);
                if(cmp != hero){
                    can = false;
                    break;
                }
                pt += j;
            }
            else{
                //NO ES ESTO
                ll cmp = hs.get(pt,pt+i);
                if(cmp != huno){
                    can = false;
                    break;
                }
                pt += i;
            }
            ++ps;
        }
        if(can)++res;
    }
    cout<<res<<'\n';
    return 0;
}