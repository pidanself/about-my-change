//better answer
#include<iostream>
#include<algorithm>
using namespace std;
int n,r;
int x[10000];
int main(){
	cout<<"�������ĸ�����"<<endl;
	cin>>n;
	cout<<"���������R��"<<endl;
	cin>>r;
	cout<<"������ÿ�������������ԭ��ľ��룺"<<endl;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	//������
	sort(x,x+n);
	int i=0,ans=0;
	while(i<n){
		int s=x[i++];
		while(i<n&&x[i]<=s+r){
			i++;
		}
		int p=x[i-1];
		while(i<n&&x[i]<p+r){
			i++;
		}
		ans++;
	} 
	cout<<"���ǣ�"<<ans;


	return 0;
}

