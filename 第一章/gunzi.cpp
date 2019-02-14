using namespace std;
#include<iostream>
void qsort(int a[],int low,int high){
	if(low>=high){
		return;
	}
	int first=low,last=high;
	int k=a[first];
	while(first<last){
		while(first<last&&a[last]>=k){
			--last;
		}
		a[first]=a[last];
		while(first<last&&a[first]<=k){
			++first;
		}
		a[last]=a[first];
	}
	a[first]=k;
	qsort(a,low,first-1);
	qsort(a,first+1,high);
}
bool pan(int a,int b,int c){
	if(a<(b+c)){
		return true;
	}
	return false;
}

int main(){
	int n,m=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	qsort(a,0,n-1);
	for(int i=n-1;i>=2;i--){
		if(pan(a[i],a[i-1],a[i-2])){
			m=a[i]+a[i-1]+a[i-2];
			break;
		}
	}
	cout<<m;
	return 0;
}
