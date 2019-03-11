//最长公共子序列 
#include<iostream>
#include<string>
#include<cstring>
#include<math.h> 
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;
	cout<<s[0]<<endl<<t[0];
	int dp[n+1][m+1];
	//初始化 
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=max(max(1+dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
				
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				
			}
		}
	}
	
	cout<<dp[n][m];

	return 0;
}

