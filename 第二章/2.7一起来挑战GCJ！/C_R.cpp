//Crazy Rows
//��������̰�ķ�����֪��ԭ��ֻ��˵�����˾��ио�
//����Ԥ������ ���Խ�ʡʱ�� 
 
#include<iostream>
using namespace std;
#define maxx 40
int n,m[maxx][maxx],ans=0;
 
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>m[i][j];
		}
	}
	
	//Ԥ��������ÿһ�����һ��1��λ��
	int a[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(m[i][j]==1){
				a[i]=j;
			}
		}
	} 
	
	//�ƶ�
	for(int i=0;i<n;i++){
		if(a[i]>i){
			for(int j=i+1;j<n;j++){
				if(a[j]<=i){
					for(int t=j;t>i;t--){
						swap(a[t],a[t-1]);
						ans++;
					}
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

