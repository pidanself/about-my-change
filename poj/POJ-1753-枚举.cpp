//我感觉这道题不压缩也可 
#include<iostream>
using namespace std;
unsigned int c;
int ans=17;

void flip(int i,int j,unsigned int &x){
	x=x^(0x1<<(4*i+j));
	if(j+1<4){
		x=x^(0x1<<(4*i+j+1));
	}
	if(j-1>=0){
		x=x^(0x1<<(4*i+j-1));
	}
	if(i+1<4){
		x=x^(0x1<<(4*(i+1)+j));
	}
	if(i-1>=0){
		x=x^(0x1<<(4*(i-1)+j));
	}
}


//i,j代表位置，x代表棋盘状态，t代表已经反转的次数 
void dfs(int i,int j,unsigned int x,int t){
	
	if(x==0||x==65535){
		ans=min(ans,t);
		return;
	}
	if(i>=4){
		return;
	}
	
	//i,j位置进行反转
	flip(i,j,x);
	if(j+1>=4){
		dfs(i+1,0,x,t+1);
	}
	else{
		dfs(i,j+1,x,t+1);
	}
	flip(i,j,x);
	
	//未进行反转
	if(j+1>=4){
		dfs(i+1,0,x,t);
	}
	else{
		dfs(i,j+1,x,t);
	}
}


int main(){
	c=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			char t;
			cin>>t;
			if(t=='w'){
				c=(0x1<<(4*i+j))|c;
			}
		}
	}
	
	if(c==0||c==65535){
		cout<<0;
		return 0;
	}
	dfs(0,0,c,0);
	
	if(ans==17){
		cout<<"Impossible";
	}
	else{
		cout<<ans;
	}
	return 0;
}

