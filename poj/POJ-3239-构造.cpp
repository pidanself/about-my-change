//八皇后问题 
#include<iostream>
#include<cstring>
using namespace std;
short int mat[301]={0};
bool he[301]={0};
bool zuo[610]={0};
bool you[610]={0};

int n;

bool check(int c,int r){
	//检查该行
	if(he[r]){
		return false;
	}
	//检查左上到右下
	if(zuo[r-c+n-1]){
		return false;
	} 
	
	//检查右上到左下
	if(you[r-c+n-1]){
		return false;
	} 
	
	return true;
	
}




void dfs(int c){
	if(c==n+1){
		throw true;
	}
	
	for(int i=1;i<=n;i++){
		if(check(c,i)){
			mat[c]=i;
			he[i]=true;
			zuo[i-c+n-1]=1;
			you[i-c+n-1]=1;
			dfs(c+1);
			mat[c]=0;
			he[i]=false;
			zuo[i-c+n-1]=0;
			you[i-c+n-1]=0;
		}
	}
	
}

int main(){
	
	cin>>n;
	while(n!=0){
		try{
			dfs(1);	
		}catch(bool ifke){
		if(ifke){
			for(int i=1;i<=n;i++){
				cout<<mat[i]<<" ";
			}
			cout<<endl;
		}
		
	}
		memset(mat,0,sizeof(mat));
		memset(he,0,sizeof(he));
		memset(zuo,0,sizeof(zuo));
		memset(you,0,sizeof(you));
		cin>>n;
	}
	

	return 0;
}


