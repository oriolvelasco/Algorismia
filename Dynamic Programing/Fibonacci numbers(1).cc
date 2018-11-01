#include <iostream>
#include <vector>
using namespace std;

typedef long long L;
typedef vector<L> VL;
VL F;
int n, m;

int fibonacci(int n, int m){
    if (F[n] != -1) return F[n]%m;
    if (n <= 1) return F[n] = n;
    return F[n] = fibonacci(n-1,m)%m + fibonacci(n-2,m)%m;
}

int main(){
    while (cin >> n >> m){
        F = VL(n+1,-1);
        cout << fibonacci(n,m)%m << endl;
    }
}
