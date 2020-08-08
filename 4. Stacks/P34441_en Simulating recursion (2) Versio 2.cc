#include <iostream>
#include <stack>
using namespace std;

//P34441_en
//Simulating recursion (2)
/* IDEA:
    We write [bottom, ..., top] instead of
    |  top |
    |  ... |
    |bottom|

    for n == 3; push(3)
    1. [3]
        push(3-1) = push(2)
    2. [3, 2]
        push(2-1) = push(1)
    3. [3, 2, 1]
        cout << 1 << 2;
        pop(), pop(); --> erase 1 and 2
        push(2-1) = push(1);
    4. [3, 1]
        cout << 1 << 3;
        pop(), pop(); --> erase 1 and 3
        push(3-1) = push(2);
    5. [2, 1]
        cout << 1 << 2;
        pop(), pop(); --> erase 1 and 2
        push(2-1) = push(1);
    6. [1]
        cout << 1;
        pop(); --> erase 1;
    7. empty
*/

void print(int n) {
    stack<int> S;
    S.push(n);
    while (not S.empty()) {
        if (S.top() == 1) {
            cout << ' ' << S.top();
            S.pop();
            if (not S.empty()) {
                int x = S.top();
                cout << ' ' << x;
                S.pop();
                S.push(x-1);
            }
        }
        else {
            int x = S.top();
            S.push(x-1);
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        print(n);
        cout << endl;
    }
}
