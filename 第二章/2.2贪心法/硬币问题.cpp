//硬币问题 
#include<iostream>
using namespace std;
//币种 
const int V[6]={1,5,10,50,100,500};
int main(){
	int c[6],t=0;
	//输入每种类型币的数量 
	for(int i=0;i<6;i++){
		cin>>c[i];
	}
	//输入需要支付的金额
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
		ans+=t; 另一种方法*/
	} 
	cout<<"共使用"<<t<<"枚";


	return 0;
}

