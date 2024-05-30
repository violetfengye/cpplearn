#include<bits/stdc++.h>
using namespace std;

class unionfind{
private:
    vector<int> parent;
    vector<int> rank;
public:
	unionfind(int n){
		parent.resize(n+5);
		rank.resize(n+5);
		for(int i=1;i<=n;i++){
			parent.at(i)=i;
			rank.at(i)=0;
		}
	}
	
	int find(int x){
		if(parent.at(x)!=x){
			parent.at(x)=find(parent.at(x));
		}
		return parent.at(x);
	}
	
	void unite(int a,int b){
		int fa=find(a),fb=find(b);
		if(fa!=fb){
			if(rank.at(fa)>rank.at(fb)){
				parent.at(fb)=fa;
			}
			else if(rank.at(fb)>rank.at(fa)){
				parent.at(fa)=fb;
			}
			else{
				parent.at(fb)=fa;
				rank.at(fa)++;
			}
		}
	}
};

 int main(void){
	int m,n,k;
	cin>>m>>n>>k;
	unionfind uf(m*n);
	while(k--){
		int a,b;
		cin>>a>>b;
		uf.unite(a,b);
	}
	int ans{};
	 for(int i=1;i<=m*n;i++){
		 if(uf.find(i)==i){
			 ans++;
		 }
	 }
	 cout<<ans;
	 return 0;
}
