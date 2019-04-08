//�˻ʺ����� 
#include<iostream>
using namespace std;
bool mat[301][301]={0};
int ans[301]={0};

int n;

bool check(int c,int r){
	//������
	for(int i=1;i<=n;i++){
		if(mat[r][i]==1){
			return false;
		}
	}
	//������
	for(int i=1;i<=n;i++){
		if(mat[i][c]==1){
			return false;
		}
	}
	//�������
	int i=r+1,j=c-1;
	while((i<=n&&i>=1)&&(j<=n&&j>=1)){
		if(mat[i][j]==1){
			return false;
		}
		i++;
		j--;
	}
	
	
	//�������
	i=r+1,j=c+1;
	while((i<=n&&i>=1)&&(j<=n&&j>=1)){
		if(mat[i][j]==1){
			return false;
		}
		i++;
		j++;
	}
	
	//������� 
	i=r-1,j=c-1;
	while((i<=n&&i>=1)&&(j<=n&&j>=1)){
		if(mat[i][j]==1){
			return false;
		}
		i--;
		j--;
	}
	
	//������� 
	i=r-1,j=c+1;
	while((i<=n&&i>=1)&&(j<=n&&j>=1)){
		if(mat[i][j]==1){
			return false;
		}
		i--;
		j++;
	}
	
	return true;
	
}




void dfs(int c){
	if(c==n+1){
		
		throw true;
	}
	
	for(int i=1;i<=n;i++){
		if(check(c,i)){
			mat[i][c]=1;
			ans[c]=i;
			dfs(c+1);
			mat[i][c]=0;
		}
	}
	
}

int main(){
	
	cin>>n;
	try{
		dfs(1);	
	}catch(bool ifke){
		if(ifke){
			for(int i=1;i<=n;i++){
				cout<<ans[i]<<" ";
			}
		}
	}

	return 0;
}

