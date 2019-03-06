//Crazy Rows
//根本方法贪心法，不知道原因只能说见多了就有感觉
//加上预处理技巧 可以节省时间 
 
#include<iostream>
using namespace std;
#define maxx 40
int n,m[maxx][maxx],ans=0;
 
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>m[i][j];
		}
	}
	
	//预处理，计算每一行最后一个1的位置
	int a[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(m[i][j]==1){
				a[i]=j;
			}
		}
	} 
	
	//移动
	for(int i=0;i<n;i++){
		if(a[i]>i){
			for(int j=i+1;j<n;j++){
				if(a[j]<=i){
					for(int t=j;t>i;t--){
						swap(a[t],a[t-1]);
						ans++;
					}
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

