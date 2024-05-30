#include<bits/stdc++.h>
using namespace std;
struct s{
    int x, y, a, b;
    int xx, yy;
} s[10005];
int main(void){
    int n, X, Y;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> s[i].x >> s[i].y >> s[i].a >> s[i].b;
        s[i].xx = s[i].x + s[i].a;
        s[i].yy = s[i].y + s[i].b;
    }
    cin >> X >> Y;
    int ans;
    for (int i = 1; i <= n;i++){
        if(s[i].xx>=X&&s[i].x<=X&&s[i].yy>=Y&&s[i].y<=Y){
            ans = i;
        }
    }
    cout << ans;
    return 0;
}
/*
// P1003
#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct node{
    int a,b,g,k;
}carpet[N];
int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin>>n;
    for(int i=1;i<=n;++i)
        cin>>carpet[i].a>>carpet[i].b>>carpet[i].g>>carpet[i].k;
    int x,y; cin>>x>>y;
    for(int i=n;i;--i){
        if(x>=carpet[i].a&&x<carpet[i].a+carpet[i].g&&y>=carpet[i].b&&y<carpet[i].b+carpet[i].k){
            cout<<i<<endl; return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
*/