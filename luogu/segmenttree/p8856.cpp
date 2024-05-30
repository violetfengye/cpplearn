#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, m, s;
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
    ll query(int top, int l, int r);
    void update(int top, int l, int r, ll k);
    vector<Node> v;
};

void SegmentTree::Build_Tree(int top, int l, int r)
{
    v.at(top).l = l, v.at(top).r = r;
    v.at(top).sum = 0;
    if (l == r)
    {
        v.at(top).sum = 0;
        return;
    }
    int mid = (l + r) >> 1;
    Build_Tree(2 * top, l, mid);
    Build_Tree(2 * top + 1, mid + 1, r);
}

ll SegmentTree::query(int top, int l, int r)
{
    if (v.at(top).l == l && v.at(top).r == r)
    {
        return v.at(top).sum;
    }
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
        v.at(top).sum += k;
        return;
    }
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
    cin >> n >> s >> m;
    SegmentTree st;
    st.Build_Tree(1, 1, n);
    while (m--)
    {
        int o, d, n;
        cin >> o >> d >> n;
        if(st.query(1,1,n)>s){
            cout << "N" << endl;
        }
        else{
            cout << "Y" << endl;
            st.update(1, o, d, n);
        }
    }
    return 0;
}