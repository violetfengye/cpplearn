#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;
ll input[N];
ll n, m, q;
struct Node
{
    ll l, r;
    ll sum;
    ll plz, mlz;
};
class SegmentTree
{
private:
    vector<Node> v;

public:
    SegmentTree()
    {
        v.resize(n * 4);
    }
    void Build_Tree(ll top, ll l, ll r);
    void Pushdown(ll top);
    void Pushup(ll top);
    void add(ll top, ll l, ll r, ll k);
    void mult(ll top, ll l, ll r, ll k);
    ll query(ll top, ll l, ll r);
};
void SegmentTree::Build_Tree(ll top, ll l, ll r)
{
    v.at(top).l = l, v.at(top).r = r;
    v.at(top).mlz = 1, v.at(top).plz = 0;
    if (l == r)
    {
        v.at(top).sum = input[l] % m;
        return;
    }
    ll mid = (v[top].l + v[top].r) >> 1;
    Build_Tree(top << 1, l, mid);
    Build_Tree(top << 1 | 1, mid + 1, r);
    Pushup(top);
}
void SegmentTree::Pushdown(ll top)
{
    if (v.at(top).plz == 0 && v.at(top).mlz == 1)
    {
        return;
    }
    ll k1 = v[top].mlz, k2 = v[top].plz;
    v[top << 1].sum = (ll)(k1 * v[top << 1].sum + k2 * (v[top << 1].r - v[top << 1].l + 1) % m) % m;
    v[top << 1 | 1].sum = (ll)(k1 * v[top << 1 | 1].sum + k2 * (v[top << 1 | 1].r - v[top << 1 | 1].l + 1) % m) % m;
    v[top << 1].mlz = (ll)k1 * v[top << 1].mlz % m;
    v[top << 1 | 1].mlz = (ll)k1 * v[top << 1 | 1].mlz % m;
    v[top << 1].plz = (ll)(k2 + v[top << 1].plz * k1 % m) % m;
    v[top << 1 | 1].plz = (ll)(k2 + v[top << 1 | 1].plz * k1 % m) % m;
    v[top].mlz = 1, v[top].plz = 0;
}
void SegmentTree::Pushup(ll top)
{
    v[top].sum = (v[top << 1].sum + v[top << 1 | 1].sum) % m;
}
void SegmentTree::add(ll top, ll l, ll r, ll k)
{
    if (v[top].l == l && v[top].r == r)
    {
        v[top].sum = (v[top].sum + k * (v[top].r - v[top].l + 1) % m) % m;
        v[top].plz = (v[top].plz + k) % m;
        return;
    }
    Pushdown(top);
    ll mid = (v[top].l + v[top].r) >> 1;
    if (mid >= r)
    {
        add(top * 2, l, r, k);
    }
    else if (mid < l)
    {
        add(top * 2 + 1, l, r, k);
    }
    else
    {
        add(top * 2, l, mid, k);
        add(top * 2 + 1, mid + 1, r, k);
    }
    /*
    if(mid>=l){
        add(top<<1, l, r, k);
    }
    if(mid<r){
        add(top<<1|1, l, r, k);
    }
    */
    Pushup(top);
}
void SegmentTree::mult(ll top, ll l, ll r, ll k)
{
    if (v[top].l == l && v[top].r == r)
    {
        v[top].sum = v[top].sum * k % m;
        v[top].mlz = v[top].mlz * k % m;
        v[top].plz = v[top].plz * k % m;
        return;
    }
    Pushdown(top);
    ll mid = (v[top].l + v[top].r) >> 1;
    if (mid >= r)
    {
        mult(top * 2, l, r, k);
    }
    else if (mid < l)
    {
        mult(top * 2 + 1, l, r, k);
    }
    else
    {
        mult(top * 2, l, mid, k);
        mult(top * 2 + 1, mid + 1, r, k);
    }
    /*
    if (mid >= l)
    {
        mult(top<<1, l, r, k);
    }
    if (mid < r)
    {
        mult(top<<1|1, l, r, k);
    }
    */
    Pushup(top);
}
ll SegmentTree::query(ll top, ll l, ll r)
{
    if (v[top].l == l && v[top].r == r)
    {
        return v[top].sum % m;
    }
    Pushdown(top);
    ll ans{}, mid = (v[top].l + v[top].r) >> 1;
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
    /*
    if (mid >= l)
    {
        ans+=query(top<<1, l, mid);
    }
    if (mid < r)
    {
        ans+=query(top<<1|1, mid + 1, r);
    }
    */
    return ans % m;
}
int main(void)
{
    cin >> n >> q >> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> input[i];
    }
    SegmentTree st;
    st.Build_Tree(1, 1, n);
    while (q--)
    {
        ll op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            st.mult(1, x, y, k);
        }
        else if (op == 2)
        {
            cin >> x >> y >> k;
            st.add(1, x, y, k);
        }
        else
        {
            cin >> x >> y;
            cout << st.query(1, x, y) << endl;
        }
    }
    return 0;
}