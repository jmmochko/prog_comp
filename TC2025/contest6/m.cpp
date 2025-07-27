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

string siguiente(string prev, int b){
    int ogb = b;
    if(9*SZ(prev) < b){
        string res;
        while(b>9){
            res.push_back('9');
            b -= 9;
        }
        res.push_back('0' + b);
        return res;
    }
    reverse(all(prev));
    prev.pb('0');
    reverse(all(prev));
    fore(i,1,SZ(prev)){
        if(b - (prev[i] - '0')<=0){
            --b;
            if(prev[i-1] == '9'){
                int pt = i-1;
                while(prev[pt]=='9'){
                    b += prev[pt] - '0';
                    prev[pt] = '0';
                    --pt;
                }
                prev[pt]++;
                for(int atras = SZ(prev)-1; atras>pt; --atras){
                    prev[atras] = max('0',min('9',(char)(b+'0')));
                    b -= min('9',(char)(b+'0'));
                }
                return prev;
            }
            prev[i-1]++;
            fore(j,i,SZ(prev)-1)prev[i] = '0';
            prev[0] = b + '0';
            return prev;
        }
        b -= prev[i] - '0'; 
    }
    return prev;
}

int main(){
    FIN;
    int n;
    cin>>n;
    vector<int> nums(n);
    fore(i,0,n)cin>>nums[i];
    int anterior = 0, termina = 0;
    vector<string> res(n,"");
    res[0] = siguiente("0",nums[0]);
    fore(i,1,n)res[i] = siguiente(res[i-1],nums[i]);
    fore(i,0,n){
        cout<<res[i]<<'\n';
    }
    return 0;
}