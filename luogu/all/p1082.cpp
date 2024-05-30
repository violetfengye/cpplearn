#include<bits/stdc++.h>
using namespace std;
int main(void){
    int a, b, x;
    cin >> a >> b;
    for (int k = 1;;k++){
        if(!((k*b+1)%a)){
            x = (k * b + 1) / a;
            break;
        }
    }
    cout << x;
    return 0;
}