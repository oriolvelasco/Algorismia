#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<long long> VL;
typedef vector<pair<long long, long long> > VP;

VP mt;

int cerca(long long val, int esq, int dre) {
    if(esq > dre or val > mt[dre].first) return -1;
    int mid = (esq+dre)/2;
    if(mt[esq].first >= val) return esq;
    if(mt[mid].first >= val) return cerca(val, esq, mid);
    return cerca(val, mid+1, dre);
}

int main() {
    int n;
    while(cin >> n) {
        mt = VP(n);
        for(int i = 0; i < n; ++i) cin >> mt[i].first >> mt[i].second;
        sort(mt.begin(), mt.end());
        VL dp(n, 0); //dp[i] temps maxim que pot estar menjant amb les i primeres crides si es menja l'i-essim
        VL maxabans(n, 0); //maxabans[i] temps maxim que pot estar menjant abans de menjar-se l'i-essim
        long long maxim = 0;
        long long sum = 0;
        for(int i = 0; i < n; ++i) {
            if(i != 0) maxabans[i] = max(maxabans[i], maxabans[i-1]);
            dp[i] = maxabans[i] + mt[i].second;
            int j = cerca(mt[i].first+mt[i].second, i+1, n-1);
            if(j != -1) maxabans[j] = max(maxabans[j], dp[i]);
            maxim = max(maxim, dp[i]);
            sum += mt[i].second;
        }
        if(sum == maxim) cout << "Cthulhu fhtagn!" << endl;
        else cout << maxim << endl;
    }
}
