#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    while(cin >> m >> n) {
        priority_queue<pair<long long, long long> > pq;
        vector<long long> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<int> choice(n, 0);
        for (int i = 0; i < n; ++i) {
            pq.push(make_pair(-v[i], i));
        }
        vector<int> ordenats;
        for(int i = 0; i < m; ++i) {
            long long top = pq.top().first;
            int j = pq.top().second;
            ordenats.push_back(-top);
            while(pq.top().first == top) {
                int k = pq.top().second;
                pq.pop();
                pq.push(make_pair(-ordenats[choice[k]]*v[k], k));
                ++choice[k];
            }
            if(i == m-1)cout << -top << endl;
        }
    }
}
