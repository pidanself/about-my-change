//Fence Repair
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n,ans;
	cout<<"请输入板数："<<endl;
	cin>>n;
	int l[n];
	cout<<"请输入每个板子的长度："<<endl;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	sort(l,l+n);
	int i=0;
	while(i<n-1){
		int t=l[i]+l[i+1];
		i++;
		ans+=t;
		l[i]=t;
		int g=i;
		for(int j=i+1;j<n;j++){
			if(l[g]>l[j]){
				int te=l[g];
				l[g]=l[j];
				l[j]=te;
				g++;
			}
			else{
				break;
			}
		}
		
	}
	cout<<"最小开销为："<<ans;
	return 0;
}

