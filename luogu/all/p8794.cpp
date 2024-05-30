#include<bits/stdc++.h>
using namespace std;

int dmin[105][105], n, q, l[105][105], t{1}, d[105][105],vis[105][105];

int p(){
    int x{};
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            x += dmin[i][j];
    return x*2;
}

bool check(){
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(d[i][j]!= l[i][j])
                return false;
    return true;
}

void floyd(){
    int tmp = (t - 1) % n;
    for(int i=0;i<n;i++){
        if(vis[tmp][i]==0)
            d[tmp][i] -= 1;
        if(d[tmp][i]<l[tmp][i]){
            d[tmp][i] = l[tmp][i];
            vis[tmp][i] = 1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(vis[tmp][j]==0)
            dmin[i][j] = min(dmin[i][j], dmin[tmp][j] + dmin[tmp][i]-2);
        }
    }
    t++;
}

int main(void){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> d[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> l[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dmin[i][j] = d[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dmin[i][j] = min(dmin[i][j], dmin[i][k] + dmin[k][j]);
            }
        }
    }
    if(p()<=q){
        cout << 0;
        return 0;
    }
    while(p()>=q){
        floyd();
        if(check()&&q<p()){
            cout << -1;
            return 0;
        }
    }
    cout << t;
    return 0;
}