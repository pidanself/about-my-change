//Fence Repair
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n,ans;
	cout<<"�����������"<<endl;
	cin>>n;
	int l[n];
	cout<<"������ÿ�����ӵĳ��ȣ�"<<endl;
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
	cout<<"��С����Ϊ��"<<ans;
	return 0;
}

