#include <iostream>
#include <queue>
using namespace std;

//P62266_en
//Huffman codes

//Comentari: La solucio NO es trivial.
/* IDEA:
    La idea es que podem expressar un arbre com el mateix arbre
    traient dues fulles + el codi de huffman d'aquestes dues fulles,
    tal que sumem les frequencies que guardem a l'arrel, com podem
    veure-ho en el graf.
    A cada iteracio, com que ajuntem les dues fulles, s'ha de sumar
    al total dels bits/lletra la suma d'aquestes fulles (f1*1 + f2*1)
    que es corresopn a col.locar el bit 1 o 0 a cada fulla.
    f = [frequencies] |  b = bits/lletra
    f = [10, 30, 60]     [40, 60]        [100]
    b = 140=100+60+40   100=0+60+40    0(nomes es una lletra)
         100              100            100
         / \              / \             A
        60 40      <=    60 40     <=
        A  / \           A   B
          10 30
          B   C
*/
int main() {
    cout.setf(ios::fixed);
    cout.precision(4);
    int n;
    cin >> n;
    priority_queue<double> Q;
    double bits = 0;
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        Q.push(-x); //Ordered increasingly
    }
    while (Q.top() != -100) {
        double x = Q.top(); Q.pop();
        double y = Q.top(); Q.pop();
        bits += x+y;
        Q.push(x+y);
    }
    cout << "expected number of bits per letter: " << -bits/100 << endl;
}
