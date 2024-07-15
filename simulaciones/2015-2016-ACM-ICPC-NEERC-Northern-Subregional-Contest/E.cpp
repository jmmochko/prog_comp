#include<bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
//#define f first
//#define s second
#define ll long long
#define pb push_back
#define mp make_pair
#define forn(a,b,c) for(int a=b;a<c;a++)
#define show(a) cout<<a<<"\n"
#define showAll(a) for(auto i:a) cout<<i<<" ";cout<<"\n"
#define input(a) for(auto& i:a) cin>>i
#define all(a) a.begin(),a.end()
#define DBG(a) cout<<#a<<" = "<<a<<"\n"
#define RAYA cout<<"=============="<<"\n"
#define jump cout<<"\n"
#define MAXN 10000000

int main(){
    FIN;
    //ifstream cin("easy.in");
    //ofstream cout("easy.out");

    string s;
    cin>>s;
    if(s.size()>=1){
        cout<<s[0];
        if(s.size()>=2){
            forn(i,1,s.size()){
                cout<<s[i];
                if(i<s.size()-1){
                    if(s[i-1] =='+' and s[i]=='0' and s[i+1]=='0'){
                        cout<<'+';
                        s[i]='+';
                        continue;
                    }
                }
                if(s[i-1]=='-'){
                    if(i==s.size()-1) continue;
                    else if(s[i+1]=='+' or s[i+1]=='-') continue;
                    else{
                        cout<<'+';
                        s[i]='+';
                    
                    }
                }
            }
        }
    }
    //system("pause");
    //cin.close();
    //cout.close();
    return 0;
}