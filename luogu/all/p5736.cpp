#include<bits/stdc++.h>
using namespace std;
bool zs(int a){
    if(a==0||a==1){
        return 0;
    }
    for (int i = 2; i * i <= a;i++){
        if(a%i==0){
            return 0;
            break;
        }
    }
    return 1;
}
int main(void){
    int n;
    cin >> n;
    const int nn = n;
    int a[nn];
    for (int i = 0; i < nn;i++){
        cin >> a[i];
    }
    int b[nn], j{};
    for (int i = 0; i < nn;i++){
        if(zs(a[i])){
            b[j++] = a[i];
        }
    }
    for (int i = 0; i < j;i++){
        cout << b[i]<<" ";
    }
    return 0;
}