//选择不相交区间 
/*
数轴上有n个开区间(ai, bi)。选择尽量多个
区间，使得这些区间两两 没有公共点。
*/
#include<iostream>
using namespace std;
#include<algorithm>

struct qu{
	int l,r;
}; 
bool cmp(qu a,qu b){
	return a.l<b.l; 
}


int main(){
	qu ji[100];
	qu ans[100];
	int a=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ji[i].l>>ji[i].r;
	}
	sort(ji,ji+n,cmp);
	int i=1;
	int l=ji[0].l,r=ji[0].r;
	//算法开始
	while(i<=n){
		if(i==n){
			ans[a].l=l;
			ans[a].r=r;
			a++;
			break;
		}
		if(ji[i].l<r){
			if(ji[i].r<r){
				l=ji[i].l;
				r=ji[i].r;
				
			}
			i++;
			continue;
		}
		ans[a].l=l;
		ans[a].r=r;
		a++;
		l=ji[i].l;
		r=ji[i].r;
		i++;
	} 
	
	//进行输出
	for(int i=0;i<a;i++){
		cout<<ans[i].l<<" "<<ans[i].r<<endl;
	} 

	return 0;
}

