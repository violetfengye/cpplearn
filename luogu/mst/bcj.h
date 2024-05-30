#include<iostream>
#include<vector>

class unionfind
{
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    unionfind(int);
    int find(int);
    void unite(int, int);
};
unionfind::unionfind(int x)
{
    parent.resize(x + 10);
    rank.resize(x + 10);
    for (int i = 1; i <= x; i++)
    {
        parent.at(i) = i;
        rank.at(i) = 1;
    }
}
int unionfind::find(int x)
{
    if (parent.at(x) != x)
    {
        parent.at(x) = find(parent.at(x));
    }
    return parent.at(x);
}
void unionfind::unite(int x, int y)
{
    int p1 = find(x), p2 = find(y);
    if (rank.at(p1) < rank.at(p2))
    {
        parent.at(p1) = parent.at(p2);
    }
    else if (rank.at(p1) > rank.at(p2))
    {
        parent.at(p2) = parent.at(p1);
    }
    else
    {
        parent.at(p1) = parent.at(p2);
        rank.at(p2)++;
    }
}
