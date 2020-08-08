#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

//P52023_en
//Reverse Polish notation

int main() {
    string s;
    while (getline(cin, s)) {
        stack<int> Q; //LIFO
        stringstream ss(s);
        while (ss >> s) {
            if (s == "+" or s == "-" or s == "*") {
                int y = Q.top();
                Q.pop();
                int x = Q.top();
                Q.pop();
                if (s == "+") Q.push(x+y);
                else if (s == "-") Q.push(x-y);
                else Q.push(x*y);
            }
            else { //Convert string to int
                int d = 1;
                int n = 0;
                for (int i = s.size()-1; i >= 0; --i) {
                    n += (s[i] - '0')*d; //s[i] - '0' because is ASCII
                    d *= 10;
                }
                Q.push(n);
            }
        }
        cout << Q.top() << endl; //Print the result
    }
}
