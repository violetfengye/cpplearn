#include<bits/stdc++.h>
using namespace std;
class UnionFind
{
public:
    UnionFind(int n)//构造函数初始化
    {
        parent.resize(n + 5);
        rank.resize(n + 5);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)//如果这个节点的父亲节点不是头节点的话，那么继续往上寻找
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)//通过比较秩的大小来选择头节点
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
            {
                parent[rootX] = rootY;
            }
            else if (rank[rootX] > rank[rootY])
            {
                parent[rootY] = rootX;
            }
            else
            {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;//存储头节点
    vector<int> rank;//秩，代表所在层数
};

int n, m;
struct zf{
    int a, b, a_b;
};
vector<zf> v;
set<int> s1,s2;

int main(){
    cin >> n >> m;
    v.resize(m);
    for (int i = 0; i < m;i++){
        zf tmp;
        cin >> tmp.a>>tmp.b>>tmp.a_b;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), [](zf x1, zf x2)
         { return x1.a_b > x2.a_b; });
    for(int i = 0; i < m; i++){
        if (s1.count(v.at(i).a) == 0&&s2.count(v.at(i).b) == 0)
        {
            s1.insert(v.at(i).a);
            s2.insert(v.at(i).b);
        }
        else{
            cout<<v.at(i).a_b<<endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}