//���Բ�����ѹ������� 
//mat�����Ƿǵ�ѹ��������¼���̵ľ������ѹ����Ȼ�ռ�̫���� 
#include<iostream>
using namespace std;
bool mat[5][5]={0};//��ʼ������false����ر�+
int ans=100;
bool pro[5][5]={0};//��ʼ������false����δ��

void tra(int i,int j,int t){
	if(i==5){
		int tt=0;
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				if(!ma[i][j]){
					return;
				}
			}
		}
		if(t<ans){
			ans=t;
			pro=p;
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
	
	//����״̬
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			char t;
			cin>>t;
			if(t=='-'){
				ma[i][j]=true; 
			}
		}
	} 
	
	
	tra(1,1,0);
	
	
	cout<<ans<<endl;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			//�ж�ĳһλ�Ƿ�Ϊ1 
			if(pro[i][j]){
				cout<<i<<" "<<j<<endl;
			} 
		}
	}
	
	return 0;
}

