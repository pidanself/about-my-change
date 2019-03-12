//完全背包内存改善 
#include<iostream>
#include<cstring>
using namespace std;
#define max_n 100
#define max_w 10000
int dp[max_w+1];

int main(){
	//init
	memset(dp,0,sizeof(dp));
	
	int n,W;
	cin>>n>>W;
	int w[n+1],v[n+1];
	for(int i=1;i<n+1;i++){
		cin>>w[i]>>v[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=w[i];j<=W;j++){
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	
	
	cout<<dp[W];
	return 0;
}

