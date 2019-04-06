//区间选点问题 
/*
数轴上有n个闭区间[ai, bi]。取尽量少的点，使得
每个区间内都至少有 一个点（不同区间内含的点可
以是同一个）。
*/
#include<iostream>
using namespace std;
#include<algorithm>

struct qu{
	int l,r;
}; 
bool cmp(qu a,qu b){
	if(a.r==b.r){
		return a.l>b.l;
	}
	return a.r<b.r; 
}


int main(){
	qu ji[100];
	int ans[100];
	int n,a=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ji[i].l>>ji[i].r;
	}
	
	sort(ji,ji+n,cmp); 
	int x=ji[0].r;
	ans[a++]=x;
	int i=1;
	//算法开始
	while(i<n){
		
		if(ji[i].l<=x){
			i++;
			continue;
		}
		x=ji[i++].r;
		ans[a++]=x;
	}
	cout<<a<<endl;
	for(int i=0;i<a;i++){
		cout<<ans[i]<<endl;
	}
	
	
	return 0;
}

