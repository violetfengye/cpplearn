#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    return !y ? x : gcd(y, x % y);
}
int main(void){
    int x0, y0, num{},p;
    cin >> x0 >> y0;
    for (int i = 1; i*i<= x0 * y0;i++){
            if(x0*y0%i==0){
                int j = x0 * y0 / i;
                if(gcd(i,j)==x0){
                    num++;
                    if(i==j){
                        p = 1;
                    }
                }
            }
    }
    if(p){
            cout << 2 * num - 1;
    }
    else
    {
            cout << 2 * num;
    }
    return 0;
}