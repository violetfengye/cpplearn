#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, a[N];
bool check(int mid){
    long long sum{};
    for (int i = 0; i < n;i++){
        if(a[i]>mid){
            sum += a[i] - mid;
        }
    }
    return m <= sum;
}
int main(void){
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int l{0}, r{1000000000}, mid, ans;
    while(l<=r){
        mid = l + r >> 1;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}