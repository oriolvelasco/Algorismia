#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;
typedef pair<int, int> PI;
typedef queue<PI> Q;

VE dists;
VVE G;
int n, m;

//L'algorisme es basa en un BFS. El BFS té complexitat O(|A| + |V|) comparat amb el Dijkstra de complexitat O((|A|+|V|)*log(|V|)).
//Com el cost de les arestes és com a molt 3, podem convertir el nostre graf dirigit en un de equivalent on totes les arestes són
//de cost 1 afegint nodes artificials a les arestes > 1. Aquest graf adaptat tindrà com a molt n+(2*m) vértexos i 3*m arestes,
//i per tant aplicar-li un BFS té complexitat O(|V| + 5*|A|) < O((|A|+|V|)*log(|V|))

void millorquedijkstra(Q& q){

  while(not q.empty()){
    PI now = q.front();
    int d = now.first;
    int node = now.second;
    q.pop();

    if(dists[node] == -1){
      dists[node] = d;
      for(v: G[node]) if(dists[v] == -1) q.push(make_pair(d+1, v));
    }

  }

}

int main(){
  while(cin >> n >> m){
    G = VVE(n + 2*m);
    dists = VE(n + 2*m, -1);
    int j = n;
    while (m--) {
      int u, v, c;
      cin >> u >> v >> c;
      if(c == 1) G[u].push_back(v);
      if(c == 2){
        G[u].push_back(j);
        G[j].push_back(v);
        ++j;
      }
      if(c == 3){
        G[u].push_back(j);
        G[j].push_back(j + 1);
        G[j + 1].push_back(v);
        j += 2;
      }
    }
    Q q;
    q.push(make_pair(0,0));
    millorquedijkstra(q);

    for(int i = 0; i < n; i++){
      cout << i << " : ";
      if(dists[i] == -1) cout << "no" << endl;
      else cout << dists[i] << endl;
    }
    cout << "----------" << endl;
  }

}
