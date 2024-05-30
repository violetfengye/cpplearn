#include<bits/stdc++.h>
using namespace std;
string a;
int main(){
	cin>>a;
	int ans=0;
	for(int i=0;i<=a.size()/2;i++){
		if(a[i]!=a[a.size()-i-1]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
