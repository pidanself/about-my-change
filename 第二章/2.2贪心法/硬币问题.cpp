//Ӳ������ 
#include<iostream>
using namespace std;
//���� 
const int V[6]={1,5,10,50,100,500};
int main(){
	int c[6],t=0;
	//����ÿ�����ͱҵ����� 
	for(int i=0;i<6;i++){
		cin>>c[i];
	}
	//������Ҫ֧���Ľ��
	int A;
	cin>>A;
	for(int i=5;i>=0;i--){
		while(V[i]<=A&&c[i]!=0){
			c[i]--;
			A-=V[i];
			t++;
		}
		/*int q=min(A/V[i],c[i]);
		A-=q*V[i];
		ans+=t; ��һ�ַ���*/
	} 
	cout<<"��ʹ��"<<t<<"ö";


	return 0;
}

