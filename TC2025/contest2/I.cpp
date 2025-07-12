#include <bits/stdc++.h>
#define fore(a,b,c) for(int a = b; a<c; ++a)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fst first
#define snd second 
#define all(a) a.begin(),a.end()
using namespace std;
typedef long long ll;

int main(){
    FIN;
    ll n,x,y;
    cin>>n;
    vector <vector <ll>> g(n+1);
    fore(i,0,n-1){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<ll> nums(n);fore(i,0,n)cin>>nums[i];
    queue<int> q;
    bool vis[n+1];
    fore(i,0,n+1)vis[i] = false;
    q.push(1);
    vis[1] = true;
    int i = 1;
    if(nums[0]!=1){
        cout<<"No\n";
        return 0;
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        set<int> vecinos;
        for(auto e: g[u]){
            if(vis[e])continue;
            vecinos.insert(e);
        }
        fore(k,0,vecinos.size()){
            if(!vecinos.count(nums[i])){
                cout<<"No\n";
                return 0;
            }
            vis[nums[i]] = true;
            q.push(nums[i]);
            ++i;
        }
    }
    if(i!=n){
        cout<<"No\n";
    }
    else cout<<"Yes\n";
    return 0;
}