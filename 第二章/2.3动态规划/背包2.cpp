#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int n;
	cin>>n;
	int w[n],v[n],t;
	for(int i=0;i<n;i++){
		cin>>w[i];
		cin>>v[i];
	} 
	cin>>t;
	int dp[n+1][t+1];
	for(int i=0;i<n;i++){
		for(int j=0;j<t+1;j++){
			dp[i][j]=0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=t;j++){
			if(j<w[i]){
				dp[i+1][j]=dp[i][j];
			}
			else{
				dp[i+1][j]=max(dp[i][j],dp[i][j-w[i]]+v[i]);
			}
		}
	}
	cout<<"最大值为："<<dp[n][t];

	return 0;
}

