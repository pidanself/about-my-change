//Saruman's Army
#include<iostream>
using namespace std;

int main(){
	int n,r,x[1000];
	cin>>n>>r;
	cout<<"请输入从左往右点距离原点的位置：";
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	
	int ans=0;
	int i=0;
	while(i<n){
		if(i==n-1||x[i+1]>x[i]+r){
			ans++;
			i++;
		}
		else{
			int t=x[i]+r;
			while(x[i+1]<=t){
				i++;
				if(i==n-1) break;
				
			}
			ans++;
			t=x[i]+r;
			while(x[i]<=t){
				i++;
				if(i==n)break;
			}
		}
	}
	
	cout<<"最多标记"<<ans<<"个点"; 


	return 0;
}

