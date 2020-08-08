#include <iostream>
#include <vector>
using namespace std;

int N = 500001;

int main() {
    vector<int> v(N, N+1);
    v[0] = 0;
    for (int i = 0; i < N; ++i) {
        if(i >= 1) v[i] = min(v[i],1+v[i-1]);
        if(i >= 5) v[i] = min(v[i],1+v[i-5]);
        if(i >= 8) v[i] = min(v[i],1+v[i-8]);
        if(i >= 14) v[i] = min(v[i],1+v[i-14]);
    }
    int n;
    while(cin >> n and n != -1) cout << v[n] << endl;
}
