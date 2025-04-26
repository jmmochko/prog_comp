#include <bits/stdc++.h>
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int main(){
    FIN;
    int r,c;
    cin>>r>>c;
    vector<string> mat(r);
    for(int i = 0; i<r; ++i){
        cin>>mat[i];
    }
    //como r,c son chicos, puedo simplemente recorrer todas las filas y columnas y marcar aquellas que no tengan una S
    for(int i = 0; i<r; ++i){
        bool berry = false;
        for(int j = 0; j<c; ++j){
            berry = berry || (mat[i][j] == 'S');
        }
        if(!berry){
            for(int j = 0; j<c; ++j){
                mat[i][j] = 'C';
            }
        }
    }
    for(int j = 0; j<c; ++j){
        bool berry = false;
        for(int i = 0; i<r; ++i){
            berry = berry || (mat[i][j] == 'S');
        }
        if(!berry){
            for(int i = 0; i<r; ++i){
                mat[i][j] = 'C';
            }
        }
    }
    int res = 0;
    for(int i = 0; i<r; ++i){
        for(int j = 0; j<c; ++j){
            if(mat[i][j]=='C')++res;
        }
    }
    cout<<res<<'\n';
    return 0;
}