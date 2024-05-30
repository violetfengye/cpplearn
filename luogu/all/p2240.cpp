#include<bits/stdc++.h>
using namespace std;
struct xcc{
    int m;
    int n;
    double p;
} x[105];
int main(void){
    int N, T;
    double lr{};
    cin >> N >> T;
    for (int i = 0; i < N; i++)
    {
        cin >> x[i].m >> x[i].n;
        x[i].p = x[i].n*1.0 / x[i].m;
    }
    sort(x, x + N, [](xcc a, xcc b)
         { return a.p >= b.p; });
    int k = 0;
    while(T){
        lr += x[k].p;
        x[k].m--;
        T--;
        if(!x[k].m){
            k++;
        }
    }
    cout << fixed << setprecision(2) << lr;
    return 0;
}
/*
// P2240
#include <bits/stdc++.h>
using namespace std;
struct node{
    int m,v;
    double k;
};
struct cmp{
    bool operator()(node x,node y){
        if(x.k==y.k) return x.m<y.m;
        return x.k<y.k;
    }
};
priority_queue<node,vector<node>,cmp>pq;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,t; cin>>n>>t;
    node temp;
    for(int i=1;i<=n;++i){
        cin>>temp.m>>temp.v;
        temp.k=(double)temp.v/temp.m;
        pq.push(temp);
    }

    double res=0;
    while(t&&pq.size()){
        if(t<pq.top().m){
            res+=(double)t*pq.top().k; t=0; break;
        }
        t-=pq.top().m;
        res+=pq.top().v;
        pq.pop();
    }
    printf("%.2f",res);
    return 0;
}
*/