#include<bits/stdc++.h>
using namespace std;
struct A{
    int b;
    int x;
};
int main(void){
    int N, W;
    cin >> N >> W;
    const int NN = N;
    struct A a[NN];
    for (int i = 0; i < NN;i++){
        cin >> a[i].x >> a[i].b;
    }
    int sum{};
    for (int i = a[0].x; i < W;i++){
        sum += a[i].b;
    }

}