#include<bits/stdc++.h>
using namespace std;
int E = 100, caoc = 1, kboss = 30,bestway=10000000; // 初始100能量，一株草,能量上限100
int way[20][20],mp[20],birth;
vector<int> endway,boss;
void findway(int e,int now,bool qiu,int cnt,int sum,bool can){
    if(sum>bestway) return;
    if(cnt==3){
        bestway=min(bestway,sum);
        return;
    }
    
    // if (e <= 70||mp[now]==9)
    // {
    //     e += 30;
    //     boss.push_back(now);
    // }
    for (int i = 0; i < 20;i++){
        if(way[now][i]==1){
            if(e>6){
               
            }
        }
    }
}
int main(){
    cin>>birth;
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            way[i][j] = 0;
        }
        mp[i] = 0;
    }
    for (int i = 0; i < 16;i++){//蓝球=1，红球=2，绿球=3，紫球=4，井分别对应5678，boss对应9
        int where, what;
        cin >> where >> what;
        mp[where] = what;
    }
    for (int i = 0; i <= 25; i++)
    {//每一条通道连通的图
        int a, b;
        cin >> a >> b;
        way[a][b] = 1;
        way[b][a] = 1;
    }
    findway(100,birth, false, 0, 0,true);
    cout << "最优路径：";
    for (int i = 0; i < (int)endway.size(); i++)
    {
        cout << endway[i] << " ";
    }
    cout << endl
         << "打怪顺序：";
    for (int i = 0;i < (int)boss.size();i++){
        cout << boss[i] << " ";
    }
    return 0;
}