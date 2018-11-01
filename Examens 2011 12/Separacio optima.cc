#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;

int n;
VI nombres, sumafalta;
int millor;

void f(int i, int dif) {
    if (i == n) {
        if (abs(dif) < millor) millor = abs(dif);
        return;
    }
    if(abs(dif)-sumafalta[i-1] >= millor or millor == 0) return;
    f(i+1, dif+nombres[i]);
    f(i+1, dif-nombres[i]);
}

int main() {
    while (cin >> n) {
        nombres = VI(n);
        for (int i = 0; i < n; ++i) cin >> nombres[i];
        sumafalta = VI(n, 0);
        for(int i = n-2; i >= 0; --i) sumafalta[i] = sumafalta[i+1]+nombres[i+1];
        millor = sumafalta[0]+nombres[0];
        f(1, nombres[0]);
        cout << millor << endl;
    }
}
