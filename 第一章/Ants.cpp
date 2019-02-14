//Ants
using namespace std;
#include<iostream>
int l,n,x[100];


int main(){
	cin>>l>>n;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	int mint=0,maxt=0;
	for(int i=0;i<n;i++){
		mint=max(mint,min(x[i],l-x[i]));
	}
	for(int i=0;i<n;i++){
		maxt=max(maxt,max(x[i],l-x[i]));
	}
	cout<<mint<<endl<<maxt;
	
	
	
	return 0;
}
