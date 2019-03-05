//并查集相应功能及实现 
#include<iostream>
using namespace std;
#define MAX_N 10000
int par[MAX_N];
int rank[MAX_N];

//init n
void init(int n){
	for(int i=0;i<n;i++){
		par[i]=i;
		rank[i]=0;
	}
}

//find your root
int find(int x){
	if(par[x]==x){
		return x;
	}
	else{
		return par[x]=find(par[x]);
	}
}

//unite sets
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rank[x]<rank[y]){
		par[x]=y;
	}
	else{
		par[y]=x;
		if(rank[x]==rank[y]) rank[x]++;
	}
}

//judge
bool same(int x,int y){
	return find(x)==find(y);
}
int main(){



	return 0;
}

