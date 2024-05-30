#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main(void){
    int m, n;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        q.push(i);
    }
    while(!q.empty()){
        for (int i = 1; i < m;i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
queue <int> qu;
int main(void)
{
    int m,n,i,temp;
    cin>>n>>m;
    for(i=1;i<=n;i++)qu.push(i);
    while(!qu.empty()){//也可以改成while(qu.size()){
        for(i=1;i<m;i++){
            temp=qu.front();
            qu.pop();
            qu.push(temp);
        }
        cout<<qu.front()<<" ";
        qu.pop();
    }
    return 0;
}
*/