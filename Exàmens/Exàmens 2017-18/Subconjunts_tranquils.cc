#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> VE;
typedef vector<VE> VVE;

int n;
VVE dislikes;

//Cal mirar tant si a la persona que hem afegit li agrada tothom com que als que ja hi són els agradi l'afegit
bool nice(VE& persones, int i){
  for(int j = 0; j < i; ++j){
    if(dislikes[i][j] == 1 and persones[j] == 1) return false;
    if(dislikes[j][i] == 1 and persones[j] == 1) return false;
  }
  return true;
}

//Backtracking, quan afegim algú al subconjunt mirem amb la funcio nice() si encara és subconjunt tranquil
void backtracking(VE& persones, int i, int& subconjunts){
  if(i == n){
    ++subconjunts;
    return;
  }
  if(i >= n) return;
  
  persones[i] = 0;
  backtracking(persones, i + 1, subconjunts);
  persones[i] = 1;
  if(nice(persones, i)) backtracking(persones, i + 1, subconjunts);

  return;
}

int main(){
  while(cin >> n){
    VE persones(n, 0);
    dislikes = VVE(n, VE(n, 0));
    char c;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> c;
        if(c == 'D') dislikes[i][j] = 1;
      }
    }
    int subconjunts = -1;
    backtracking(persones, 0, subconjunts);
    cout << subconjunts << endl;
  }
}
