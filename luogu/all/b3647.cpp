#include<bits/stdc++.h>
using namespace std;
const int N = 1e9;
int d[105][105];
int main(void){
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==j){
                d[i][j] = 0;
            }
            else{
                d[i][j] = N;
            }
        }
    }
    for(int i=1; i<=m; i++){
        int a, b;
        cin>>a>>b;
        cin >> d[a][b];
        d[b][a] = d[a][b];
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            if(d[k][i]==N)
                continue;
            for(int j=1; j<=n; j++){
                if(i==j)
                    continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}