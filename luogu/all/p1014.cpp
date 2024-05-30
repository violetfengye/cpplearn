#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m,temp;
    cin>>n;
    for (int k = 1;;k++){
        if(k*(k+1)>=2*n){
            temp=k*(k-1)/2;
            m = k;
            break;
        }
    }
    temp = n - temp;
    cout<<(m-temp+1)<<"/"<<temp<<endl;
    return 0;
}