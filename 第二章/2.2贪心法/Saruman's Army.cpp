//Saruman's Army
#include<iostream>
using namespace std;

int main(){
	int n,r,x[1000];
	cin>>n>>r;
	cout<<"������������ҵ����ԭ���λ�ã�";
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	
	int ans=0;
	int i=0;
	while(i<n){
		if(i==n-1||x[i+1]>x[i]+r){
			ans++;
			i++;
		}
		else{
			int t=x[i]+r;
			while(x[i+1]<=t){
				i++;
				if(i==n-1) break;
				
			}
			ans++;
			t=x[i]+r;
			while(x[i]<=t){
				i++;
				if(i==n)break;
			}
		}
	}
	
	cout<<"�����"<<ans<<"����"; 


	return 0;
}

