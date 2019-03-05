//二分图问题 
#include<iostream>
#include<vector>
#define MAX_V 10000
using namespace std;
vector<int> G[MAX_V];
int color[MAX_V]={0};
bool dfs(int i,int c){
	color[i]=c;
	for(int j=0;j<G[i].size();j++){
		if(color[G[i][j]]==c){
			return false;
		}
		if(color[G[i][j]]==0&&!dfs(G[i][j],-c))return false;
		
	}
	return true;
}	
int main(){
	int v;
	cin>>v;
	for(int i=0;i<v;i++){
		int num,x;
		cin>>num;
		for(int j=0;j<num;j++){
			cin>>x;
			G[i].push_back(x);
		}
	}
	
	for(int i=0;i<v;i++){
		if(color[i]==0){
			if(!dfs(i,1)){
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";

	return 0;
}

