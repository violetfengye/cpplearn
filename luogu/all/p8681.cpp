#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<ll> q;
ll N;
int main(){
    cin >> N;
    while(N--){
        ll a;
        cin >> a;
        q.push(a);
    }
    ll max{},p{},tt=0;
    while(q.size()>0){
        ll temp{};
        ll num = min(ll(q.size()), ll(pow(2, tt)));
        for(ll j=1; j<=num; j++){
            temp+=q.front();
            q.pop();
        }
        if(temp>max){
            p = tt + 1;
            max = temp;
        }
        tt++;
    }
    cout << p << endl;
    return 0;
}