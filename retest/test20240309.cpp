#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    for (int i = 0; i < 10;i++){
        v.push_back(i);
    }
    v.erase(v.begin() + 3);
    for (auto i = v.begin(); i < v.end();i++){
        cout << *i << " ";
    }
        return 0;
}