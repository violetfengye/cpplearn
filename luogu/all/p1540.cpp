#include<bits/stdc++.h>
using namespace std;
queue<int> q;
set<int> s;
int main(void){
    int M, N;
    cin >> M >> N;
    int num{};
    for (int i = 0; i < N;i++){
        int a, b;
        cin >> a;
        b = s.size();
        s.insert(a);
        if(s.size()>b){
            q.push(a);
            num++;
        }
        if(q.size()>M){
            s.erase(q.front());
            q.pop();
        }
    }
    cout << num;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    queue<int>a;
    int hash[1023]={0};//记录
    int M,N,i,temp,j,num=0;
    bool flag=true;
    cin>>M>>N;
    while(N--){
        cin>>temp;
        flag=true;
        if(!hash[temp]){
            hash[temp]=1;
            num++;
            a.push(temp);
            if(a.size()>M){
                hash[a.front()]=0;
                a.pop();
                }
        }
    }
    cout<<num;
    return 0;
}
*/