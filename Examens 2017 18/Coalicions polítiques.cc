#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& v, vector<int>& suma, vector<bool>& used, int i, int s, int minim, int& k, int& n){
    if(s >= k and s-minim < k) {
        cout << '{';
        bool primer = true;
        for (int i = 0; i < n; ++i) {
            if(used[i]){
                if(primer) primer = false;
                else cout << ", ";
                cout << i+1;
            }
        }
        cout << '}' << endl;
        return;
    }
    if(s >= k or i == n or s + suma[i] < k) return;
    used[i] = true;
    backtrack(v, suma, used, i+1, s+v[i], min(minim, v[i]), k, n);
    used[i] = false;
    backtrack(v, suma, used, i+1, s, minim, k, n);
    return;
}

int main() {
    int k, n;
    while (cin >> k >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        vector<int> suma(n,0);
        suma[n-1] = v[n-1];
        for (int i = n-2; i >= 0; --i) suma[i]=suma[i+1]+v[i];
        vector<bool> used(n, 0);
        backtrack(v, suma, used, 0, 0, 1000000, k, n);
        cout << "----------" << endl;
    }
}
