#include<bits/stdc++.h>
using namespace std;
const int N = 20;
vector<int> v;
int n, b[N];
void dfs(int x){
    int sum{};
    for (int i = 0; i < v.size();i++){
        sum += v[i];
    }
    if(sum==n){
        for (int i = 0; i < v.size();i++){
            if(i==v.size()-1){
                cout << v[i];
            }
            else{
                cout << v[i] << "+";
            }
        }
    }
    for (int i = 1; i < n;i++){
        if(!b[i]){
            
        }
    }
}