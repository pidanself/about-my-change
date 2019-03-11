#include<iostream>
using namespace std;
#define max_q 10000
#define int_max 1000000
int p,q,a[max_q+2];

int main(){
	cin>>p>>q;
	for(int i=1;i<=q;i++){
		cin>>a[i];
	}
	a[0]=0,a[q+1]=p+1;
	int dp[q+1][q+2];
	//初始化dp矩阵
	for(int i=0;i<=q;i++){
		dp[i][i+1]=0;
	} 
	
	//从最短区间开始向上推以求得dp[0][q+1]
	for(int w=2;w<=q+1;w++){
		for(int i=0;i+w<=q+1;i++){
			int j=i+w,t=int_max; 
			for(int k=i+1;k<j;k++){
				t=min(t,dp[i][k]+dp[k][j]);
			}
			dp[i][j]=t+a[j]-a[i]-2;
		}
	} 
	
	cout<<dp[0][q+1];
	return 0;
}

