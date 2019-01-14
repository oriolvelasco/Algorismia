#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

const int INF = 1e8; // Be, ens conformem amb aquesta aproximacio... #ElNumericoLoEsTodo

int n; // Nombre d'investigadors
int m; // Nombre d'articles
map<string, set<int>> articles; // Articles llegits per cada investigador
vector<set<string>> authors; // Autors de cada article
vector<string> researchers; // Noms dels investigadors
map<string, int> erdosnum; // Vector del nombre d'Erdos + 1 pel BFS

void bfs() {
  erdosnum["erdos"] = 1;
  queue<string> Q;
  Q.push("erdos");

  while (!Q.empty()) {
    string x = Q.front(); Q.pop();
    for (int article : articles[x]) {
      for (const string &y : authors[article]) {
        if (y == x || erdosnum[y] > 0) continue; // Si l'hem visitat, p calle
        erdosnum[y] = erdosnum[x] + 1;
        Q.push(y);
      }
    }
  }
}

int main() {
  while (cin >> n) {
    // Read and process data:
    researchers = vector<string>(n);
    for (int i = 0; i < n; ++i)
      cin >> researchers[i];

    cin >> m;
    authors = vector<set<string>>(m);
    for (int i = 0; i < m; ++i) {
      int k;
      cin >> k;
      for (int j = 0; j < k; ++j) {
        string author;
        cin >> author;
        articles[author].insert(i);
        authors[i].insert(author);
      }
    }

    // Perform bfs to retrieve Erdos numbers:
    bfs();

    // Now select the winner!
    int minnum = INF;
    int person;
    for (int i = 0; i < n; ++i) {
      int num = erdosnum[researchers[i]];
      if (num != 0 and (num < minnum or (num == minnum and researchers[i] < researchers[person]))) {
        minnum = num;
        person = i;
      }
    }

    if (minnum == INF) cout << "???";
    else cout << researchers[person] << " " << (minnum - 1);
    cout << endl;

    // Cleanup:
    articles.clear();
    erdosnum.clear();
  }
}
