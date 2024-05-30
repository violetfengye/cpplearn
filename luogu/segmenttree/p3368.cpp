#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll a[N];
int n, m;
struct Node
{
    int l, r;
    ll sum = 0, lazy = 0;
};

class SegmentTree
{
public:
    SegmentTree()
    {
        v.resize(4 * n);
    }
    void Build_Tree(int top, int l, int r);
    void Pushdown(int top);
    ll query(int top, int dis);
    void update(int top, int l, int r, ll k);

private:
    vector<Node> v;
};

void SegmentTree::Build_Tree(int top, int l, int r)
{
    v.at(top).l = l, v.at(top).r = r;
    if (l == r)
    {
        v.at(top).sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build_Tree(2 * top, l, mid);
    Build_Tree(2 * top + 1, mid + 1, r);
    v.at(top).sum = v.at(2 * top).sum + v.at(2 * top + 1).sum;
}

void SegmentTree::Pushdown(int top)
{
    if (v.at(top).lazy == 0)
    {
        return;
    }
    v.at(top * 2).sum += (v.at(top * 2).r - v.at(top * 2).l + 1) * v.at(top).lazy;
    v.at(top * 2 + 1).sum += (v.at(top * 2 + 1).r - v.at(top * 2 + 1).l + 1) * v.at(top).lazy;
    v.at(top * 2).lazy += v.at(top).lazy;
    v.at(top * 2 + 1).lazy += v.at(top).lazy;
    v.at(top).lazy = 0;
}

ll SegmentTree::query(int top, int dis)
{
    if (v.at(top).l == dis && v.at(top).r == dis)
    {
        return v.at(top).sum;
    }
    Pushdown(top);
    int mid = (v.at(top).l + v.at(top).r) >> 1;
    ll ans = 0;
    if (mid >= dis)
    {
        ans += query(top * 2, dis);
    }
    else
    {
        ans += query(top * 2 + 1, dis);
    }

    return ans;
}

void SegmentTree::update(int top, int l, int r, ll k)
{
    if (v.at(top).l == l && v.at(top).r == r)
    {
        v.at(top).sum += k * (v.at(top).r - v.at(top).l + 1);
        v.at(top).lazy += k;
        return;
    }
    Pushdown(top);
    int mid = (v.at(top).l + v.at(top).r) >> 1;
    if (mid >= r)
    {
        update(top * 2, l, r, k);
    }
    else if (mid < l)
    {
        update(top * 2 + 1, l, r, k);
    }
    else
    {
        update(top * 2, l, mid, k);
        update(top * 2 + 1, mid + 1, r, k);
    }
    v.at(top).sum = v.at(top * 2).sum + v.at(top * 2 + 1).sum;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    SegmentTree st;
    st.Build_Tree(1, 1, n);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, z;
            cin >> x >> y >> z;
            st.update(1, x, y, z);
        }
        else
        {
            int x;
            cin >> x;
            cout << st.query(1, x) << endl;
        }
    }
    return 0;
}