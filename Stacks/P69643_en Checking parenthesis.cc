#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

//P69643_en
//Checking parenthesis

int main() {
    string p;
    while (cin >> p) {
        stringstream ss(p);
        stack<char> S;
        char c;
        bool ok = true;
        while (ss >> c and ok) {
            if (c == ')' or c == ']') {
                if (S.empty()) ok = false;
                else if (c == ')') {
                    if (S.top() == '(') S.pop(); // () are canceled
                    else if (S.top() == '[') ok = false; //Not possible [)
                    else S.push(c);
                }
                else {
                    if (S.top() == '[') S.pop(); // [] are canceled
                    else if (S.top() == '(') ok = false; //Not possible (]
                    else S.push(c);
                }
            }
            else S.push(c);
        }
        if (not S.empty() or not ok) cout << p << " is incorrect" << endl;
        else cout << p << " is correct" << endl;
    }
}
