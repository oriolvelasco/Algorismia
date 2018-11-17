#include <iostream>
#include <stack>
using namespace std;

//P69643_en
//Checking parenthesis

int main() {
    string p;
    while (cin >> p) {
        stack<char> S;
        bool ok = true;
        for (int i = 0; i < p.size() and ok; ++i) {
            char c = p[i];
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
