#include <stack>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        istringstream ss(s);
        int x;
        stack<int> p1, p2;
        while (ss >> x) {
            if (x%2 == 0) p2.push(x);
            else p1.push(x);
        }
        if (p1.empty()) {
            if (p2.empty()) cout << endl;
            else {
                cout << p2.top();
                p2.pop();
                while (not p2.empty()) {
                    cout << ' ' << p2.top();
                    p2.pop();
                }
                cout << endl;
            }
        }
        else {
            while (not p2.empty()) {
                cout << p2.top() << ' ';
                p2.pop();
            }
            cout << p1.top();
            p1.pop(); 
            while (not p1.empty()) {
                cout << ' ' << p1.top();
                p1.pop();
            }
            cout << endl;
        }
    }
}
