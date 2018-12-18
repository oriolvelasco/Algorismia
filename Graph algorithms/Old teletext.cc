#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<pair<int, int> > VP;
typedef vector<VP> VVP;
typedef vector<char> VB;

const int INF = 1e5;
const int N = 800;
VB used, trencat;
VI possibles;

void Dijkstra(int ini, VI& dist) {
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, ini));
    dist[ini] = 0;
    while(not q.empty()) {
        int node = q.top().second;
        int d = -q.top().first;
        q.pop();
        if(dist[node] == d) {
            if(not trencat[10]) {
                int z = (node+1)%N;
                if(dist[z] > d+1) {
                    q.push(make_pair(-d-1, z));
                    dist[z] = d+1;
                }
            }
            if(not trencat[11]) {
                int z = (node-1+N)%N;
                if(dist[z] > d+1) {
                    q.push(make_pair(-d-1, z));
                    dist[z] = d+1;
                }
            }
            for (int i = 0; i < possibles.size(); ++i) {
                int z = possibles[i];
                if(dist[z] > d+3){
                    q.push(make_pair(-d-3, z));
                    dist[z] = d+3;
                }
            }
        }
    }
}

void f(int i, int anterior, VVI& dist, int actual, int& minim, int& p, VI& v) {
    if(actual >= minim) return;
    if(i == p) {
        minim = actual;
        return;
    }
    for (int j = 1; j < p; ++j) {
        if(not used[j]) {
            used[j] = true;
            f(i+1, j, dist, actual+dist[anterior][v[j]], minim, p, v);
            used[j] = false;
        }
    }
}

int main() {
    string s;
    while (cin >> s) {
        trencat = VB(12, false);
        for (int i = 7; i < s.size(); ++i) {
            if(s[i] >= '0' and s[i] <= '9') trencat[s[i]-'0'] = true;
            if(s[i] == '+') trencat[10] = true;
            if(s[i] == '-') trencat[11] = true;
        }
        possibles = VI(0);
        for(int i = 0; i < N; ++i) {
            int aux = 100+i;
            if(not trencat[aux/100] and not trencat[aux%10] and not trencat[(aux/10)%10]) possibles.push_back(i);
        }
        int p;
        cin >> p;
        VI v;
        v.push_back(0);
        for (int i = 0; i < p; ++i) {
            int x;
            cin >> x;
            if(x != 100) v.push_back(x-100);
        }
        p = v.size();
        VVI dist(p, VI(N, INF));
        for (int i = 0; i < p; ++i) {
            Dijkstra(v[i], dist[i]);
        }
        used = VB(p, false);
        used[0] = true;
        int minim = INF;
        f(1, 0, dist, 0, minim, p, v);
        if (minim >= INF) cout << "no solution" << endl;
        else cout << minim << endl;
    }
}
