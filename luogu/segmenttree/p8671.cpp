#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int> v;
int main(void){
    cin >> n >> k;
    v.resize(n+10);
    v.at(1) = 0;
    for (int i = 2;i<=n;i++){
        v.at(i) = (v.at(i - 1) + k) % i;
    }
    cout<<v.at(n)+1<<endl;
    return 0;
}