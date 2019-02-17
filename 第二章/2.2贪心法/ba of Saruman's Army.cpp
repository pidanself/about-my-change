//better answer
#include<iostream>
#include<algorithm>
using namespace std;
int n,r;
int x[10000];
int main(){
	cout<<"请输入点的个数："<<endl;
	cin>>n;
	cout<<"请输入距离R："<<endl;
	cin>>r;
	cout<<"请输入每个坐标点距离左边原点的距离："<<endl;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	//计算结果
	sort(x,x+n);
	int i=0,ans=0;
	while(i<n){
		int s=x[i++];
		while(i<n&&x[i]<=s+r){
			i++;
		}
		int p=x[i-1];
		while(i<n&&x[i]<p+r){
			i++;
		}
		ans++;
	} 
	cout<<"答案是："<<ans;


	return 0;
}

