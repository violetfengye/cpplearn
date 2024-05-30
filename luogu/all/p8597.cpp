#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
int main(){
	cin>>a>>b;
	int ans=0;
	for(int i=0;i<a.size()-1;i++){
		if(a[i]!=b[i]){
			if(a[i+1]=='o'){
				a[i+1]='*';
			}
			else{
				a[i+1]='o';
			}
			ans++;
		}
	}
	if(a[a.size()-1]!=b[b.size()-1])
		ans++;
	cout<<ans<<endl;
	return 0;
}
