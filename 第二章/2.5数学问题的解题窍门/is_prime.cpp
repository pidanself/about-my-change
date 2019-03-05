
#include<iostream>
using namespace std;
bool is_prime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return n!=1;
}

int main(){



	return 0;
}

