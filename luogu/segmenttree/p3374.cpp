#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n, m;
ll a[N];
struct Node{
    int l, r;
    ll sum;
};
class SegmentTree{
    vector<Node> v;
public:
    SegmentTree() { v.resize(n * 4); }
    void Build_Tree(int top,int l,int r){
        v.at(top).l = l, v.at(top).r = r;
        if(l==r){
            v.at(top).sum = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        Build_Tree(top*2,l,mid);
        Build_Tree(top*2+1,mid+1,r);
        v.at(top).sum = v.at(top * 2).sum + v.at(top * 2 + 1).sum;
    }
    void update(int top,int dis,ll k){
        if(v.at(top).l==dis&&v.at(top).r==dis){
            v.at(top).sum += k;
            return;
        }
        int mid = (v.at(top).l + v.at(top).r) >> 1;
        if(mid>=dis){
            update(top * 2, dis, k);
        }
        else{
            update(top * 2 + 1, dis, k);
        }
        v.at(top).sum = v.at(top * 2).sum + v.at(top * 2 + 1).sum;
    }
    ll query(int top,int l,int r){
        if(v.at(top).l==l&&v.at(top).r==r){
            return v.at(top).sum;
        }
        int mid = (v.at(top).l + v.at(top).r) >> 1;
        ll s = 0;
        if(mid>=r){
            s += query(top * 2, l, r);
        }
        else if(mid<l){
            s += query(top * 2 + 1, l, r);
        }
        else{
            s += query(top * 2, l, mid);
            s += query(top * 2 + 1, mid + 1, r);
        }
        return s;
    }
};
int main(){
    cin >> n >> m;
    for (int i = 1;i<=n;i++){
        cin>>a[i];
    }
    SegmentTree st;
    st.Build_Tree(1, 1, n);
    while(m--){
        int op, x, y;
        cin >> op >> x >> y;
        if(op==1){
            st.update(1, x, y);
        }
        else{
            cout << st.query(1, x, y) << endl;
        }
    }
    return 0;
}