//多重部分和问题-初想 
#include<iostream>
using namespace std;
#define max_n 100000
bool dp[101][max_n+1];
int a[101],m[101];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>m[i];
	}
	for(int i=0;i<=k;i++){
		dp[0][i]=false;
	}
	for(int i=0;i<=n;i++){
		dp[i][0]=true;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			for(int z=0;z*a[i]<=j&&z<=m[i];z++){
				dp[i][j]=dp[i][j]||dp[i-1][j-z*a[i]];
			}
			
		}
	}
	
	cout<<dp[n][k];

	return 0;
}

