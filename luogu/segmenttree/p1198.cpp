#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ls top<<1
#define rs top<<1|1
const ll N = 2e5 + 10;
ll M, D, t, dis, cnt;
struct Node{
    ll max, l, r;
};
class SegmentTree{
private:
    vector<Node> v;
public:
    SegmentTree(){
        v.resize(N << 2);
    }
    void Pushup(int top){
        v[top].max=max(v[ls].max,v[rs].max);
    }
    void Build_tree(ll top, ll l, ll r){
        v[top].l = l, v[top].r = r;
        if(l==r){
            v[top].max = (ll)-2e9;
            return;
        }
        ll mid = (l + r) >> 1;
        Build_tree(ls, l, mid);
        Build_tree(rs, mid + 1, r);
        Pushup(top);
    }
    void update(ll top, ll l,ll r){
        if(v[top].l >= l&&v[top].r <= r){
            v[top].max = t % D;
            return;
        }
        Pushup(top);
    }
    ll query(ll top, ll l,ll r){
        ll ans{(ll)-2e9};
        if(v[top].l >= l&&v[top].r <= r){
            ans = max(ans, v[top].max);
            return ans;
        }
        ll mid= (v[top].l +v[top].r) >> 1;
        if(mid>=l){
            ans = max(ans, query(ls, l, r));
        }
        if(mid<r){
            ans = max(ans, query(rs, l, r));
        }
        return ans;
    }
};
int main(){
    cin >> M >> D;
    SegmentTree st;
    st.Build_tree(1, 1, N);
    while(M--){
        char op;
        ll L;
        cin >> op >> L;
        if(op=='Q'){
            t = st.query(1, cnt + 1 - L, cnt);
            cout << t;
        }
        else{
            t += L;
             
        }
    }
    return 0;
}