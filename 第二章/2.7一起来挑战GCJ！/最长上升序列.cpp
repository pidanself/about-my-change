//最长上升子序列 
#include<iostream>
#include<cstring>
using namespace std;
#define max_n 1000
int dp[max_n+1];
int a[max_n+1];
int main(){
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(dp,-1,sizeof(dp)); 
	for(int i=1;i<=n;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(a[j]<a[i]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;

	return 0;
}

