//POJ No.2386 
#include<iostream>
using namespace std;
int N,M;
char field[100][100];
void dfs(int x,int y){
	field[x][y]='.';
	for(int dx=-1;dx<=1;dx++){
		for(int dy=-1;dy<=1;dy++){
			int nx=dx+x,ny=dy+y;
			if(0<=nx&&nx<N&&0<=ny&&ny<M&&field[nx][ny]=='w'){
				dfs(nx,ny);
			} 
		}
	}
	return;
}

int main(){
	int res=0;
	cin>>N>>M;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>field[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(field[i][j]=='w'){
				dfs(i,j);
				res++;
			}
			
		}
	}
	cout<<"共有"<<res<<"个水洼"; 


	return 0;
}

