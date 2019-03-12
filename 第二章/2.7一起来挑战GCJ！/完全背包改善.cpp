//完全背包问题 进一步改善 
#include<iostream>
#include<cstring>
using namespace std;
#define max_n 100
#define max_w 10000
int dp[max_n+1][max_w+1];

int main(){
	//init
	memset(dp,0,sizeof(dp));
	
	int n,W;
	cin>>n>>W;
	int w[n+1],v[n+1];
	for(int i=1;i<n+1;i++){
		cin>>w[i]>>v[i];
	}
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<W+1;j++){
			if(j<w[i]){
				dp[i][j]=dp[i-1][j];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-w[i]]+v[i]);
			}
			
			 
		}
		
	}
	
	
	cout<<dp[n][W];
	return 0;
}
