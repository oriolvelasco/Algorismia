#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

//cost de canviar el caracter c a d
int cost(char c, char d) {
    if(c == d) return 0;
    return 1;
}

int main() {
    string s;
    while (cin >> s) {
        int n = s.size();
        VVI dp(n, VI(n, n+1));
        //dp[i][j] es el cost minim de parentitzar be el tram {j,...,i}
        //Si (i-j)%2==0, no es pot parentitzar be
        for(int i = 0; i < n; ++i) {
            for(int j = i-1; j >= 0; j-=2) {
                dp[i][j] = cost(s[j], '(') + cost(s[i], ')');
                if(j < i-1) {
                    int minim = dp[i-1][j+1];
                    //k es la posicio on s'obre el parentesi que es tanca en i
                    for(int k = j+2; k < i; k+=2) {
                        int aux = cost(s[k],'(') + cost(s[k-1],')');
                        if(k < i-1) aux += dp[i-1][k+1];
                        if(j < k-2) aux += dp[k-1][j] - cost(s[k-1],')') - cost(s[j], '(');
                        minim = min(minim, aux);
                    }
                    dp[i][j] += minim;
                }
            }
        }
        cout << dp[n-1][0] << endl;
    }
}
