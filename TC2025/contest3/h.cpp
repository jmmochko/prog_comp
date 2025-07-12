#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fore(a,b,c) for(int a=b;a<c;++a)
#define SZ(a) ((int)a.size())
#define fst first 
#define snd second
#define all(a) a.begin(),a.end()
#define pb push_back

using namespace std;
typedef long long ll;

const int alph = 26;

bool g[alph][alph];

int niv[alph];

bool cmp(string &a, string &b){
    fore(i,0,min(SZ(a),SZ(b))){
        if(niv[a[i]]>niv[b[i]]){
            return false;
        }
        if(niv[a[i]]<niv[b[i]])return true;
    }
    return SZ(a)<SZ(b);
}

bool stringeq(string &a, string &b){
    if(SZ(a)!=SZ(b))return false;
    fore(i,0,SZ(a))if(a[i]!=b[i])return false;
    return true;
}

vector<int> gg[alph];
vector<int> tsort(){  // lexicographically smallest topological sort
	vector<int> r;priority_queue<int> q;
	vector<int> d(2*alph,0);
	fore(i,0,alph)fore(j,0,gg[i].size())d[gg[i][j]]++;
	fore(i,0,alph)if(!d[i])q.push(-i);
	while(!q.empty()){
		int x=-q.top();q.pop();r.pb(x);
		fore(i,0,gg[x].size()){
			d[gg[x][i]]--;
			if(!d[gg[x][i]])q.push(-gg[x][i]);
		}
	}
	return r;  // if not DAG it will have less than n elements
}

int main(){
    FIN;
    int n;
    cin>>n;
    vector<string> s(n);//las palabras del input
    fore(i,0,n)cin>>s[i];
    fore(i,0,n)fore(j,0,SZ(s[i]))s[i][j] = (s[i][j] - 'a');
    bool diff[n][n]; //true si son distintas
    fore(i,0,n)fore(j,0,n)diff[i][j] = false;
    fore(l,0,101){
        fore(i,0,n-1){
            if(l>=SZ(s[i]))continue;
            int j = i+1;
            while(j<n && !diff[i][j] && SZ(s[j]) > l && s[i][l]==s[j][l]){
                ++j;
            }
            if(j<n && SZ(s[j])<=l && !diff[i][j]){
                cout<<"Impossible\n";
                return 0;
            }
            if(j<n && !diff[i][j] && SZ(s[j]) > l){
                g[s[i][l]][s[j][l]] = true;
                if(s[i][l]==s[j][l]){
                    cout<<"Impossible\n";
                    return 0;
                }
            }
            fore(k,j,n)diff[i][j] = true;
        }
    }
    fore(i,0,alph)fore(j,0,alph){
        if(g[i][j])gg[i].pb(j);
    }
    vector<int> res = tsort();
    if(SZ(res)<alph){
        cout<<"Impossible\n";
        return 0;
    }
    fore(i,0,alph){
        cout<<char(res[i]+'a');
    }
    cout<<'\n';
    return 0;
}