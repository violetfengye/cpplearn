#include<bits/stdc++.h>
using namespace std;
int m, n, k;
set<int> s;

class unionfind{
private:
    vector<int> parent;
    vector<int> rank;
public:
    unionfind(int);
    int find(int);
    void unite(int, int);
};
unionfind::unionfind(int x){
    parent.resize(x + 10);
    rank.resize(x + 10);
    for (int i = 1;i<=x;i++){
        parent.at(i) = i;
        rank.at(i) = 1;
    }
}
int unionfind::find(int x){
    if(parent.at(x) !=x){
        parent.at(x) = find(parent.at(x));
    }
    return parent.at(x);
}
void unionfind::unite(int x, int y){
    int p1=find(x),p2=find(y);
    if(rank.at(p1) < rank.at(p2)){
        parent.at(p1) = parent.at(p2);
    }
    else if(rank.at(p1) > rank.at(p2)){
        parent.at(p2) = parent.at(p1);
    }
    else{
        parent.at(p1) = parent.at(p2);
        rank.at(p2)++;
    }
}

int main(){
    cin >> m >> n >> k;
    unionfind uf(m * n);
    while(k--){
        int a, b;
        cin>>a>>b;
        uf.unite(a,b);
    }
    for(int i=1;i<=m*n;i++){
        s.insert(uf.find(i));
    }
    cout<<s.size()<<endl;
    return 0;
}
