//�������� ����
 #include<iostream>
 using namespace std;
 int w[100],v[100];	
 int n;
 int rec(int i,int t){
 	int res;
 	if(i==n){
 		res=0;
	 }
	 else if(w[i]>t){
	 	res=rec(i+1,t);
	 }
	 else{
	 	res=max(rec(i+1,t),rec(i+1,t-w[i])+v[i]);
	 }
	 return res;
 }	
 int main(){
	
	cout<<"��������Ʒ��n���Լ�����Ʒ����������ֵ";
	cin>>n;
	
	int t;
	for(int i=0;i<n;i++){
		cin>>w[i];
		cin>>v[i];
	} 
	cout<<"�����뱳�����ܳ���������";
	cin>>t;
	cout<<"����ܷ�����Ϊ��"<<rec(0,t);

 	return 0;
 }
