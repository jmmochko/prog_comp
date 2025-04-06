#include <bits/stdc++.h> 
#define fore(i,a,b) for(int i=a;i<b;i++)
#define pb push_back 
#define sz(x) (int)x.size() 
#define fst first
#define snd second 
#define all(x) x.begin(),x.end() 
#define REGALO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); //mas rapido las lecturas y escrituras SIEMPRE USAR "\n" ej: cout<<"\n"
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; }

using namespace std;
typedef long long ll;

int main(){

ll n=1,aux;
ll a[55];

while(n!=0){
    cin>>n;
    if(n==0){
        continue;
    }
    ll res[n+2][n+2];
    
    
    fore(i,0,n){
        fore(j,0,n){
            res[i][j]=0;
        }
    }
    fore(i,0,n){
        cin>>aux;
        a[i]=aux;
    } 
    
    if(a[0]==a[n-1]){
        
        fore(j,0,n){
            res[j][0]=a[j]; //norte
        }

        fore(j,0,n){
            res[0][j]=a[n-1-j]; //oeste
        }
        
        fore(j,0,n){
            res[n-1][j]=a[j]; //este
        }

        fore(j,0,n){
            res[j][n-1]=a[n-j-1]; //sur
        }
    
        if(n!=0){
            cout<<"Yes"<<"\n";
            fore(i,0,n){
                fore(j,0,n){
                    cout<<res[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
    
    }


    else{
        cout<<"No"<<"\n";
    }



    


}

}