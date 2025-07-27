#include <bits/stdc++.h>
#define fore(a,b,c) for(int a = b; a<c; ++a)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second 
#define all(a) a.begin(),a.end()
using namespace std;

typedef long long ll;

void solve(){
    string s;
    cin>>s;
    vector<char> ord = {'A','T','O','N'};
    sort(all(ord));
    ll mx = 0;
    vector<char> res = {'A','T','O','N'};
    do{
        // cuento inversiones
        ll cur = 0;
        map<char,int> letra;
        fore(i,0,4){
            letra[ord[i]] = i;
        }
        vector<int> vi(4,0);//cantidad de veces que vi la letra que esta en esta posiscion del orden
        fore(i,0,s.size()){
            fore(k,letra[s[i]] + 1,4)cur += vi[k];
            vi[letra[s[i]]]++;
        }
        if(cur > mx){
            mx = cur;
            fore(i,0,4)res[i] = ord[i];
        }
    }
    while (next_permutation(all(ord)));
    //cuento apps de cada letra
    map<char,int> cnt;
    cnt['A'] = 0;
    cnt['T'] = 0;
    cnt['O'] = 0;
    cnt['N'] = 0;
    fore(i,0,s.size())cnt[s[i]]++;
    string fnl;
    //cout<<mx<<" "<<s<<'\n';
    fore(i,0,4){
        fore(c,0,cnt[res[i]])fnl.push_back(res[i]);
    }
    cout<<fnl<<'\n';
}

int main(){
    FIN;
    int t;
    cin>>t;
    fore(i,1,t+1){solve();}
    return 0;
}