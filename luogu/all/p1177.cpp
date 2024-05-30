#include<bits/stdc++.h>
using namespace std;
int a[100005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(i<n-1)
            printf("%d ",a[i]);
        else
            printf("%d\n",a[i]);
    }
    return 0;
}