#include<bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

const int INF=10e10;

int32_t main()
{
	IOS;
    int tot=0;
    int n; cin>>n;
    int cap_max=0;
    vector<pair<int, int>>v;
    for (int i=0; i<n; i++) {
        int x, y; cin>>x>>y;
        v.pb({x, y});
        tot+=y;
        cap_max+=x;
    }
    int dp[n][n][cap_max+1];
    vector<float>ans(n, -1);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int cap=1; cap<=cap_max; cap++) {
                dp[i][j][cap]=-1;
                if (i>0) {
                    dp[i][j][cap]=dp[i-1][j][cap];
                }
                if (cap-v[i].first==0 && j==0) {
                    dp[i][j][cap]=max(dp[i][j][cap], v[i].second);
                }
                if (cap-v[i].first>0 && i>0 && j>0 && dp[i-1][j-1][cap-v[i].first]!=-1) {
                    dp[i][j][cap]=max(dp[i][j][cap], dp[i-1][j-1][cap-v[i].first]+v[i].second);
                }
                if (dp[i][j][cap]!=-1) {
                    float tott=tot;
                    float dpp=dp[i][j][cap];
                    float xx=(tott+dpp)/2;
                    float capp=cap;
                    ans[j]=max(ans[j], min(capp, xx));
                }


            }
        }
    }

    for (int i=0; i<n; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

	return 0;
}