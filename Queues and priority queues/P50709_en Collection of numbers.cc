#include <iostream>
#include <queue>
using namespace std;

//P50709_en
//Collection of numbers

int main() {
    priority_queue<int> Q;
    char c;
    int x;
    while (cin >> c) {
        if (c == 'S') { //Store a copy
            cin >> x;
            Q.push(x);
        }
        else if (Q.empty()) {
            cout << "error!" << endl;
            if (c == 'I' or c == 'D') cin >> x;
        }
        else if (c == 'A') cout << Q.top() << endl;
        else if (c == 'R') Q.pop();
        else {
            int top = Q.top();
            Q.pop();
            cin >> x;
            if (c == 'I') Q.push(top + x);
            else Q.push(top - x);
        }
    }
}
