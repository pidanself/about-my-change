//区间覆盖问题 
/*
 数轴上有n个闭区间[ai,bi]，
 选择尽量少的区间覆盖一条指定线段[s,t]。

*/
#include<iostream>
#include<algorithm>
using namespace std;
struct qu{
	int l,r;
}; 
bool cmp(qu a,qu b){
	return a.l<b.l; 
}


int main(){
	int n,l,r;
	qu ji[100];
	qu ans[100];
	int a=0;
	cin>>n>>l>>r;
	for(int i=0;i<n;i++){
		cin>>ji[i].l>>ji[i].r;
	}
	sort(ji,ji+n,cmp);
	int i=0;
	//算法开始
	//遍历每一个区间 
	while(l<r){
		if(i>=n){
			cout<<"impossible";
			return 0;
		}
		int rr=0,tt;
		while(ji[i].l<=l){
			if(ji[i].r>=rr&&ji[i].r>=l){
				rr=ji[i].r;
				tt=i;	
			}
			i++;
			if(i>=n){
				break;
			}
		}
		if(rr==0){
			cout<<"impossible";
			return 0;
		}
		
		ans[a].l=ji[tt].l;
		ans[a].r=ji[tt].r;
		a++;
		l=ji[tt].r;
		
	} 
	
	for(int i=0;i<a;i++){
		cout<<ans[i].l<<" "<<ans[i].r<<endl;
	}


	return 0;
}

