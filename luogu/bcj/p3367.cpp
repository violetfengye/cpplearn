#include <iostream>
#include <vector>

using namespace std;

class UnionFind
{
public:
    UnionFind(int n)
    {
        parent.resize(n+5);
        rank.resize(n+5);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y)
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
    vector<int> parent;
    vector<int> rank;
};

int main()
{
    int n, m, z;
    cin >> n >> m;
    UnionFind uf(n);

    while(m--){
        int tmp1, tmp2;
        cin>>z>>tmp1>>tmp2;
        if(z==1){
            uf.unite(tmp1, tmp2);
        }
        else{
            if(uf.find(tmp1)==uf.find(tmp2)){
                cout << "Y" << endl;
            }
            else{
                cout << "N" << endl;
            }
        }
    }
    return 0;
}