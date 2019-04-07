//2586 尝试深搜枚举所有情况，并剪枝 
//没有把情况想清楚，导致有一些漏洞，查漏洞
//花了很长时间 
#include<iostream>
using namespace std;
int ans=-1;
bool ea[13]={0};//false代表亏损，true代表盈利
int s,d; 

void dfs(int m){
	
	if(m==13){
		int tt=0;
		for(int i=1;i<13;i++){
			if(ea[i]){
				tt+=s;
			}
			else{
				tt-=d;
			}
		}
		ans=max(ans,tt);
		return ;
	}
	
	//假设第m月亏损
	ea[m]=false;
	if(m<5){
		dfs(m+1); 
	} 
	else{
		int tt=0;
		for(int i=0;i<5;i++){
			if(ea[m-i]){
				tt+=s;
			}
			else{
				tt-=d;
			}
		}
		if(tt<=0) dfs(m+1);
	}
	
	
	//假设第m月盈利 
	ea[m]=true;
	if(m<5){
		dfs(m+1); 
	} 
	else{
		int tt=0;
		for(int i=0;i<5;i++){
			if(ea[m-i]){
				tt+=s;
			}
			else{
				tt-=d;
			}
		}
		if(tt<=0) dfs(m+1);
	}
	ea[m]=false;
	
}


int main(){

	
	while(scanf("%d%d", &s, &d) != EOF){
		dfs(1);
	
		if(ans>=0){
			cout<<ans<<endl;
		}
		else{
			cout<<"Deficit"<<endl;
		}
		ans=-1;

	}
	
	return 0;
}

