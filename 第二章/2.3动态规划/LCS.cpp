//LCS最长公共子序列 
#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int n,m;
	cout<<"please input n,m:"<<endl;
	cin>>n>>m;
	char s[n],t[m];
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	cout<<"please input s,t"<<endl;
	cin>>s>>t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=max(dp[i-1][j-1]+1,max(dp[i-1][j],dp[i][j-1]));
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	cout<<"LCS is: "<<dp[n][m];


	return 0;
}

