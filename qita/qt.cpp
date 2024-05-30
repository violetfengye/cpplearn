#include <bits/stdc++.h>
using namespace std;
#define MAXN 100501

struct NODE
{
    int w;
    int e;
    int next; // next[i]表示与第i条边同起点的上一条边的储存位置
} edge[MAXN];

int cnt;
int head[MAXN];

void add(int u, int v, int w)
{                             // 加边，u起点，v终点，w边权
    edge[cnt].w = w;          // 权值
    edge[cnt].e = v;          // 终点
    edge[cnt].next = head[u]; // 更新以u为起点上一条边的编号
    head[u] = cnt++;          // 更新以u为起点的最后一条边的编号
}

int main()
{
    memset(head, 0, sizeof(head));
    cnt = 1;
    int n;
    cin >> n;
    int a, b, c;
    while (n--)
    {
        cin >> a >> b >> c;
        add(a, b, c); // 加边
    }
    int start;
    cin >> start;
    for (int i = head[start]; i != 0; i = edge[i].next) // 遍历以start为起点的边
        cout << start << "->" << edge[i].e << " " << edge[i].w << endl;
    return 0;
}
