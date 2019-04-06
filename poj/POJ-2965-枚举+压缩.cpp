//使用压缩 
#include<iostream>
using namespace std;
//压缩后的4*4的矩阵 
unsigned int ma=0;
unsigned int pro=0;
int ans=100; 

void fan(int i,int j){
	
	for(int k=1;k<=4;k++){
		ma=(1<<((k-1+(i-1)*4)))^ma;
	}
	for(int k=1;k<=4;k++){
		ma=(1<<((j-1+(k-1)*4)))^ma;
	}
	ma=(1<<((j-1+(i-1)*4)))^ma;
	
	
}


void tra(int i,int j,int t,unsigned int p){
	if(i==5){
		if(ma==65535){
			if(t<ans){
				ans=t;
				pro=p;
			}
		}
		return ;
	}
	
	fan(i,j);
	p=(1<<((j-1+(i-1)*4)))^p;
	if(j==4){
		tra(i+1,1,t+1,p);
	}
	else{
		tra(i,j+1,t+1,p);
	}
	fan(i,j);
	p=(1<<((j-1+(i-1)*4)))^p;
	
	
	if(j==4){
		tra(i+1,1,t,p);
	}
	else{
		tra(i,j+1,t,p);
	}
	
	
}

int main(){
	
	
	//输入 
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			char t;
			cin>>t;
			if(t=='-'){
				ma=(1<<(j-1+(i-1)*4))|ma;
			}
		}
	}

	tra(1,1,0,0);
	
	cout<<ans<<endl;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			//判断某一位是否为1 
			if(pro>>(j-1+(i-1)*4)&1){
				cout<<i<<" "<<j<<endl;
			} 
		}
	}
	
	
	return 0;
}

