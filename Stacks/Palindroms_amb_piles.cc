#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int main() {
    string s;
    while(getline(cin, s))  {
        istringstream in(s);
        stack<int> p1, paux, p2;
        int x;
        while (in >> x) {
            paux.push(x);
            p1.push(x);
        }
        while (not paux.empty()) {
            p2.push(paux.top());
            paux.pop();
        }
        bool b = false;
        while (not p1.empty() and not b) {
            if (p1.top() != p2.top()) {
                b = true;
                cout << "NO es un palindrom." << endl;
            }
            else {
                p1.pop();
                p2.pop();
            }
        }
        if (p1.empty()) cout << "Es un palindrom." << endl;
    }
}
