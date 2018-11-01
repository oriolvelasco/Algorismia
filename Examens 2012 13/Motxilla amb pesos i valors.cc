#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;
typedef pair<int,int> P;
typedef vector<P> VP;
VVE M;
VP V;
int n, p;

int const INF = 1e9;

int f(int pes, int i){
    if (pes > p) return -INF;
    if (i == n) return 0;
    int& res = M[pes][i];
    if (res != -1) return res;
    return res = max(V[i].second + f(V[i].first + pes, i + 1), f(pes, i + 1));
}

int main(){
    while (cin >> p >> n) {
        V = VP(n);
        M = VVE(p+1, VE(n,-1));
        for (int i = 0; i < n; ++i) cin >> V[i].first >> V[i].second;
        cout << f(0,0) << endl;
    }
}
