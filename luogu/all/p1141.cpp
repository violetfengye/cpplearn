#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
bool vis[N];
int ans{0}, n, v[1005][1005];
struct zb
{
    int x, y;
}a;
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0},{0, -1}};
void bfs(int x,int y){
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    if(!q.empty()){
        ans++;
        q.pop();
        for (int i = 0; i <= 3;i++){
            int nx = x + d[i][0], ny = y + d[i][1];
            if(nx>=0&&nx<n&&ny<n&&ny>=0){
                if(v[nx][ny]){
                    
                }
            }
        }
    }
}