//��ȫ���� 
#include<iostream>
using namespace std;

int main(){
	//input
	int n;
	cin>>n;
	int w[n],v[n];
	for(int i=0;i<n;i++){
		cin>>w[i];
		cin>>v[i];
	} 
	int W;
	cin>>W;
	//output
	int dp[n+1][W+1];
	for(int i=0;i<W+1;i++){
		for(int j=0;j<n+1;j++){
			dp[j][i]=0;
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<W+1;j++){
			for(int k=0;(k*w[i-1])<=j;k++){
				dp[i][j]=max(dp[i][j],dp[i-1][j-k*w[i-1]]+k*v[i-1]);
			}
		}
	}
	cout<<"max is :"<<dp[n][W]; 

	return 0;
}

