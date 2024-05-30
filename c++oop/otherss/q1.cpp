#include <bits/stdc++.h>
using namespace std;
class M{
    int A;
public:
    M();
    ~M(){}
};
M::M(){
    A = 25;
    for (int i = 0; i < 10;i++){
        cout << "ct " << i << endl;
    }
}
M test;
int main(){
    return 0;
}