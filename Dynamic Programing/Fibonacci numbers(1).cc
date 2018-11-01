#include <iostream>
#include <vector>

using namespace std;

int n,m;
using VI = vector<int>;

int main(){
    while(cin>>n>>m){
        VI fibonacci(1001);
        fibonacci[0]=0;
        fibonacci[1]=1;
        for(int i=2; i<n+1; i++){
            fibonacci[i]=(fibonacci[i-1]+fibonacci[i-2])%m;
        }
        cout<<fibonacci[n]<<endl;
    }
}
