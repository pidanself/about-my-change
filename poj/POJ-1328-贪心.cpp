//这道题类似区间覆盖问题（贪心），因此我也找到了
//区间覆盖问题并做了下，请参见代码“区间覆盖问.cpp” 

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int d;
class po{
	public:
		int x,y;
		double l,r;
		void cal(){
			l=x-pow(d*d-y*y,0.5);
			r=x+pow(d*d-y*y,0.5);
		}
};

bool cmp(po a,po b){
	if(a.r==b.r){
		return a.l<b.l;
	}
	return a.r<b.r;
	
}
po p[1005];
int n,ans[1000]={0},a=0;

int main(){
	
	cin>>n>>d;
	
	while(n!=0||d!=0){
		double xx;
		int ii;
		for(int i=0;i<n;i++){
			cin>>p[i].x>>p[i].y;
			if(p[i].y>d){
				ans[a]=-1;
			}
			p[i].cal();
			
		}
		if(ans[a]==-1){
			goto end1;
		}
		sort(p,p+n,cmp); 
		
		ii=1;
		xx=p[0].r;
		ans[a]=1;
		while(ii<n){
			if(p[ii].l<=xx){
				ii++;
				continue;
			}
			ans[a]++;
			xx=p[ii].r;
		}
		
	end1:
		
		a++;
		char k;
		
		gets(&k);
		cin>>n>>d;
		
	}
	
	for(int i=0;i<a;i++){
		cout<<"Case "<<i+1<<": "<<ans[i]<<endl;
	}
	return 0;
}

