#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<vector<int> > graf(n);
        vector<vector<int> > arriben(n);
        vector<int> nin(n, 0);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            graf[x].push_back(y);
            arriben[y].push_back(x);
            ++nin[y];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) if(nin[i] == 0) q.push(i);
        vector<vector<int> > dp(n, vector<int> (2,1));
        int lmax = 0;
        int numcam = 1;
        while(not q.empty()) {
            int node = q.front();
            q.pop();
            for(int i = 0; i < graf[node].size(); ++i){
                --nin[graf[node][i]];
                if(nin[graf[node][i]] == 0) q.push(graf[node][i]);
            }
            for (int j = 0; j < arriben[node].size(); ++j) {
                if(1+dp[arriben[node][j]][0] > dp[node][0]) {
                    dp[node][0] = 1+dp[arriben[node][j]][0];
                    dp[node][1] = dp[arriben[node][j]][1];
                }
                else if(1+dp[arriben[node][j]][0] == dp[node][0]) dp[node][1] += dp[arriben[node][j]][1];
            }
            if(dp[node][0] > lmax) {
                lmax = dp[node][0];
                numcam = dp[node][1];
            }
            else if(dp[node][0] == lmax) numcam += dp[node][1];
        }
        cout << lmax << ' ' << numcam << endl;
    }
}
