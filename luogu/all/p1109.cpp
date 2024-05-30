#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n, L, R, s[55], ans{}, sum{};
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> s[i];
        sum += s[i];
    }
    cin >> L >> R;
    int a{}, b{};
    if(sum*1.0/n>=L&&sum*1.0/n<=R){
        for (int i = 0; i < n; i++){
            if(s[i]>R){
                a+=s[i]-R;
            }
            if(s[i]<L){
                b+=L-s[i];
            }
        }
        ans = max(a, b);
        cout << ans;
    }
    else{
        cout << -1;
    }
    return 0;
}
/*
// P1109
#include <bits/stdc++.h>
using namespace std;
int st[66];
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin>>n;
    int sum=0,res1=0,res2=0;//res1记录多的,res2记录少的
    for(int i=1;i<=n;++i){
        cin>>st[i];
        sum+=st[i];
    }
    int L,R; cin>>L>>R;
    if(sum<L*n||sum>R*n){cout<<-1<<endl; return 0;}
    for(int i=1;i<=n;++i){
        if(st[i]>R) res1+=st[i]-R;
        else if(st[i]<L) res2+=L-st[i];
    }
    cout<<max(res1,res2)<<endl;
    return 0;
}
*/