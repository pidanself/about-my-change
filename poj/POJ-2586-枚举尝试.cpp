//2586 ��������ö���������������֦ 
//û�а�����������������һЩ©������©��
//���˺ܳ�ʱ�� 
#include<iostream>
using namespace std;
int ans=-1;
bool ea[13]={0};//false�������true����ӯ��
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
	
	//�����m�¿���
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
	
	
	//�����m��ӯ�� 
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

