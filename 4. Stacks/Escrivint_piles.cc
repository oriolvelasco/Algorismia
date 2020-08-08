#include <iostream>
#include <stack>

using namespace std;

void escriu_de_cim_a_base(stack<int>& pila) {
    while (not pila.empty()) {
        cout << pila.top();
        pila.pop();
        cout << (pila.empty() ? "" : " ");
    }
    cout << endl;
}

void escriu_de_base_a_cim(stack<int>& pila) {
    stack<int> pila2;
    while (not pila.empty()) {
        pila2.push(pila.top());
        pila.pop();
    }
    while (not pila2.empty()) {
        cout << pila2.top();
        pila2.pop();
        cout << (pila2.empty() ? "" : " ");
    }
    cout << endl;
}
