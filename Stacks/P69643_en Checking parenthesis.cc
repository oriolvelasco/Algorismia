#include <iostream>
#include <stack>
using namespace std;

//P69643_en
//Checking parenthesis
string p;

bool parenthesis(stack<char>& S) {
    for (int i = 0; i < p.size(); ++i) {
        char c = p[i];
        if (c == ')' or c == ']') {
            if (S.empty()) return false;
            char d = S.top();
            S.pop();
            if ((c == ')' and d != '(') or (c == ']' and d != '[')) return false;
        }
        else S.push(c);
    }
    if (S.empty()) return true;
    return false;
}

int main() {
    while (cin >> p) {
        stack<char> S;
        if (parenthesis(S)) cout << p << " is correct" << endl;
        else cout << p << " is incorrect" << endl;
    }
}
