#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, w, tmp;
set<ll> s;//answer
queue<ll> q;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> w;
        if(i==1){
            s.insert(w);
            continue;
        }
        for(auto j=s.begin(); j!=s.end(); j++){
            q.push(*j);
        }
        while(!q.empty()){
            tmp=q.front();
            q.pop();
            s.insert(abs(tmp-w));
            s.insert(tmp+w);
        }
        s.insert(w);
    }
    s.erase(0);
    cout << s.size() << endl;
    return 0;
}