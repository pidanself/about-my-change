//字典序最小问题 my answer
#include<iostream>
using namespace std;
int M=10000;
int main(){
	int n;
	cout<<"input length of char:";
	cin>>n;
	char t[M];
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	int s=0,e=n-1;
	while(s<=e){
		bool left=false;
		for(int i=0;s+i<=e;i++){
			if(t[s+i]<t[e-i]){
				left=true;
				break; 
			}
			else if(t[s+i]>t[e-i]){
				break;
			}
		}
		if(left){
			putchar(t[s++]);
		}
		else{
			putchar(t[e--]);
		}
	}
	putchar('\n');

	return 0;
}

