#include<iostream>
using namespace std;
unsigned int ma=57341;
void fan(int i,int j){
	
	for(int k=1;k<=4;k++){
		ma=(1<<((k-1+(i-1)*4)))^ma;
	}
	for(int k=1;k<=4;k++){
		ma=(1<<((j-1+(k-1)*4)))^ma;
	}
	ma=(1<<((j-1+(i-1)*4)))^ma;
	
	
}
int main(){
	fan(2,2);
	cout<<ma;
	return 0;
}

