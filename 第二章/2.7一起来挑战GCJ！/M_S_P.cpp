//Minimum Scalar Product
//����һ������һ����˳Ѱ��ö����һ�������п��ܣ���large�޷��ɹ�
//�����������������ҹ��ɾͺܼ� 
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
bool compare(int a,int b){
	return a>b;
}
#define maxx 100000

int n,v1[maxx],v2[maxx];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v1[i];
	}
	for(int i=0;i<n;i++){
		cin>>v2[i];
	}
	
	sort(v1,v1+n,compare);
	sort(v2,v2+n);
	
	ll ans=0;
	for(int i=0;i<n;i++){
		ans+=v1[i]*v2[i];
	}
	cout<<ans;
	return 0;
}

