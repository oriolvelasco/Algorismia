#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

//cost de canviar el caracter c a d
int cost(char c, char d) {
    if(c == d) return 0;
    if(c == '(' and d == ')') return 1;
    if(c == ')' and d == '(') return 1;
    if(c == '[' and d == ']') return 1;
    if(c == ']' and d == '[') return 1;
    if(c == '(' and d == '[') return 2;
    if(c == ')' and d == ']') return 2;
    if(c == '[' and d == '(') return 2;
    if(c == ']' and d == ')') return 2;
    return 3;
}

int main() {
    string s;
    while (cin >> s) {
        int n = s.size();
        VVI dp(n, VI(n, 3*n+1));
        //dp[i][j][aux] es el cost minim de parentitzar be el tram {j,...,i}
        for(int i = 1; i < n; ++i) {
            dp[i][i-1] = min(cost(s[i-1], '(') + cost(s[i], ')'), cost(s[i-1], '[') + cost(s[i], ']'));
            for(int j = i-3; j >= 0; j-=2) {
                //intentem posar un parentesis a i i considerem la posicio k on s'obre el parentesis
                int c1 = cost(s[i-1], '(') + cost(s[i], ')') + dp[i-2][j];
                c1 = min(c1, cost(s[j], '(') + cost(s[i], ')') + dp[i-1][j+1]);
                for(int k = j+2; k < i-1; k += 2) {
                    c1 = min(c1, cost(s[k], '(') + cost(s[i], ')') + dp[k-1][j] + dp[i-1][k+1]);
                }
                //intentem posar un claudator a i i considerem la posicio k on s'obre el claudator
                int c2 = cost(s[i-1], '[') + cost(s[i], ']') + dp[i-2][j];
                c2 = min(c2, cost(s[j], '[') + cost(s[i], ']') + dp[i-1][j+1]);
                for(int k = j+2; k < i-1; k += 2) {
                    c2 = min(c2, cost(s[k], '[') + cost(s[i], ']') + dp[k-1][j] + dp[i-1][k+1]);
                }
                dp[i][j] = min(c1, c2);
            }
        }
        cout << dp[n-1][0] << endl;
    }
}
