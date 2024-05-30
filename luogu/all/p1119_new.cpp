#include<bits/stdc++.h>
using namespace std;
const int MAX_ = 1e9;
const int N = 205;
int d[N][N], n, m, q, t[N], k;
int floyd_(int x,int y,int ti){
    if(t[x]>ti||t[y]>ti)  return -1;
    while(t[k]<=ti&&k<n){
        for (int i = 0; i < n; i++)
        {
            if (d[i][k] == MAX_)
                continue;
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
        k++;
    }
    if(d[x][y]<MAX_)
        return d[x][y];
    return -1;
}

int main(void){
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> t[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j] = MAX_;
        }
    }
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = d[b][a] = c;
    }
    cin >> q;
    while(q--){
        int x, y, ti;
        cin >> x >> y >> ti;
        cout << floyd_(x,y,ti) << endl;
    }
    return 0;
}