#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
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
    ll query(int top, int l, int r);
    void update(int top, int l, int r, ll k);

private:
    vector<Node> v;
};

void SegmentTree::Build_Tree(int top, int l, int r)
{
    if (l == r)
    {
        v.at(top).l = v.at(top).r = l;
        v.at(top).sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build_Tree(2 * top, l, mid);
    Build_Tree(2 * top + 1, mid + 1, r);
    v.at(top).l = l, v.at(top).r = r;
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

ll SegmentTree::query(int top, int l, int r)
{
    if (v.at(top).l == l && v.at(top).r == r)
    {
        return v.at(top).sum;
    }
    Pushdown(top);
    int mid = (v.at(top).l + v.at(top).r) >> 1;
    ll ans = 0;
    if (mid >= r)
    {
        ans += query(top * 2, l, r);
    }
    else if (mid < l)
    {
        ans += query(top * 2 + 1, l, r);
    }
    else
    {
        ans += query(top * 2, l, mid);
        ans += query(top * 2 + 1, mid + 1, r);
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
    SegmentTree st;
    st.Build_Tree(1, 1, n);
    while (m--)
    {
        char op;
        cin >> op;
        if (op == 'x')
        {
            int x, y;
            cin >> x >> y;
            st.update(1, x, x, y);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << st.query(1, x, y) << endl;
        }
    }
    return 0;
}