//扩展欧几里得算法 
#include<iostream>
using namespace std;
int extgcd(int a,int b,int& x,int& y){
	int d=a;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	else{
		x=1;
		y=0;
	}
	return d;
}


int main(){
	int a,b,x,y;
	cin>>a>>b;
	extgcd(a,b,x,y);
	cout<<x<<endl<<y;

	return 0;
}

