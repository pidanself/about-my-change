//埃氏筛法 时间复杂度近似为n 
#include<iostream>
using namespace std;

int main(){
	int n,ans=0;
	cin>>n;
	bool mem[n+1];
	for(int i=0;i<n+1;i++){
		mem[i]=true;
	}
	mem[1]=false;
	for(int i=2;i<=n;i++){
		if(mem[i]){
			for(int j=2*i;j<=n;j+=i){
				mem[j]=false;
			}
			ans++;
		}

	}
	cout<<ans; 

	return 0;
}

