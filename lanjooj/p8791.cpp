#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll GB=1073741824;
const ll MB=1048576;
const ll KB=1024;
void ans(ll x){
	ll Gb=x/GB;
	ll Mb=x%GB/MB;
	ll Kb=x%MB/KB;
	ll b=x%KB;
	if(Gb>0)cout<<Gb<<"GB";
	if(Mb>0)cout<<Mb<<"MB";
	if(Kb>0)cout<<Kb<<"KB";
	if(Gb>0)cout<<b<<"B";
}
int main(void){
	ll num{},sum{};
	cin>>num;
	while(num--){
		string a;
		cin>>a;
		if(a=="int"){
			string b;
			ll cnt{};
			cin>>b;
			for(int i=0;i<b.size(),i++){
				if(b[i]==','){
					cnt++;
				}
			}
			sum+=(cnt+1)*4;
		}
		if(a=="long"){
			string b;
			ll cnt{};
			cin>>b;
			for(int i=0;i<b.size(),i++){
				if(b[i]==','){
					cnt++;
				}
			}
			sum+=(cnt+1)*8;
		}
		if(a=="String"){
			string b;
			ll cnt{},p;
			cin>>b;
			for(int i=0;i<b.size(),i++){
				if(b[i]=='"'){
					
				}
			}
		}
		if(a=="int[]"){
			
		}
	}
	ans(sum);
	return 0;
}
