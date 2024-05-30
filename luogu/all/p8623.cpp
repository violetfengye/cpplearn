#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;;
ll w, m, n;
p zb(ll x){
    p temp;
    if(x<=w){
        temp.first = 1;
        temp.second = x;
        return temp;
    }
    if(x%w == 0){
        temp.first = x / w;
        if(temp.first%2==0){
            temp.second = 1;
        }
        else{
            temp.second = w;
        }
        return temp;
    }
    temp.first = x / w + 1;
    if(temp.first%2==0){
        temp.second = w - x%w + 1;
    }
    else{
        temp.second = x % w;
    }
    return temp;
}
int main()
{
    cin >> w >> m >> n;
    p a = zb(m), b = zb(n);
    ll ans = abs(a.first - b.first) + abs(a.second - b.second);
    cout << ans << endl;
    return 0;
}