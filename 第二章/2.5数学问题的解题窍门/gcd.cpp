//求最大公约数 
#include<iostream>
using namespace std;
int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main(){
	cout<<gcd(6,5);


	return 0;
}

