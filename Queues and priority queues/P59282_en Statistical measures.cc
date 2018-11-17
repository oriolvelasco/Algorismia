#include <iostream>
#include <queue>
using namespace std;

//P59282_en
//Statistical measures
/* IDEA:
    we write [top ... bottom]
    input = 7 2 5
    if Q.push(n) --> Q = [7 5 2]
    if Q.push(-n) --> Q = [-2 -5 -7]
*/

const int INF = 1e9;
priority_queue<int> Q;
int maxim = -INF;
double aver = 0;
string request;

void print(bool ok) {
    if (ok)
        cout << "minimum: " << -Q.top() << ", maximum: " << maxim
            << ", average: " << aver/Q.size() << endl;
    else cout << "no elements" << endl;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    while (cin >> request) {
        if (request == "number") {
            int n;
            cin >> n;
            if (maxim < n) maxim = n;
            Q.push(-n); //Ordered increasingly
            aver += n;
            print(true);
        }
        //We cannot delete if Q is empty
        else if (Q.empty()) print(false);
        else { //delete
            int x = Q.top();
            aver += x;
            Q.pop();
            if (not Q.empty()) print(true);
            else {
                maxim = -INF;
                print(false);
            }
        }
    }
}
