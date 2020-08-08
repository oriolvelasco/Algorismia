#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

//P97803_en
//Library
typedef stack<string> SS;
typedef vector<SS> VS;
VS V;

//Prints the stack from bottom to top recursively
void print(stack<string>& S) {
    if (not S.empty()) {
        string x = S.top();
        S.pop();
        print(S);
        cout << ' ' << x;
    }
    return;
}

//Note: stringstream == istringstream are used indistinctly

int main() {
    //Create the vector that corresponds to the stacks
    string line;
    getline(cin, line);
    stringstream ss(line);
    int n;
    ss >> n;
    V = VS(n+1);
    for (int i = 1; i <= n; ++i) {
        getline(cin, line);
        stringstream ss(line);
        string book;
        while (ss >> book) V[i].push(book);
    }
    getline(cin, line);
    while (getline(cin, line)) {
        stringstream ss(line);
        ss >> line;
        if (line == "LOAN") {
            int id;
            ss >> id;
            if (id >= 1 and id <= n and not V[id].empty()) V[id].pop();
        }
        else {
            string book;
            ss >> book;
            int id;
            ss >> id;
            if (id >= 1 and id <= n) V[id].push(book);
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << "Stack " << i << ":";
        print(V[i]);
        cout << endl;
    }
}
