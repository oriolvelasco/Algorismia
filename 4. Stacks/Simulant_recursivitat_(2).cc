#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

void escriu(int n) {
    stack<int> pila1, pila2, pila3;
    for (int i = 1; i <= n; ++i) {
        pila2 = pila1;
        pila1.push(i);
        while (not pila2.empty()) {
            pila3.push(pila2.top());
            pila2.pop();
        }
        while (not pila3.empty()) {
            pila1.push(pila3.top());
            pila3.pop();
        }
    }
    while (not pila1.empty()) {
        cout << ' ' << pila1.top();
        pila1.pop();
    }
}

int main() { 
    int n;
    while (cin >> n) { 
        escriu(n); 
        cout << endl; 
    } 
}
