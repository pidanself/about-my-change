#include<iostream>
using namespace std;

class node{
	public:
	int val;
	node *next=NULL;
};
//存储最终结果用以输出
int ans[100][100];

int main(){
	node *head=new node;
	node *tail=new node;
	head->next=tail;
	node *t=tail;
	node *t0=head;
	int times=0;
	cin>>times;

	 
	for(int i=0;i<times;i++){
		//用以读入一串数字 
		int num,c=0;
		while(cin>>num){
			c++;
			if(cin.get()=='\n'){
				tail->val=num;
				break;
			}
			tail->val=num;
			tail->next=new node;
			tail=tail->next;
			
		}
	
		int x;
		cin>>x;
		//重新排列 
		for(int i=0;i<c;i++){
			if(t->val>=x){
				tail->next=t;
				t=t->next;
				t0->next=t;
				tail=tail->next;
				tail->next=NULL;
			} 
			else{
				t0=t0->next;
				t=t->next;
			}
		}
	
		//新队列 
		t=head->next;
		int j=0;
		while(t->next!=NULL){
			ans[i][j++]=t->val;
			node *tt=t;
			//释放内存 防止内存泄漏 
			t=t->next;
			delete tt;
		}
		ans[i][j++]=t->val;
		delete t->next;
		ans[i][j]=-1;//后面输出的时候来判断何时结束本行输出
		 
		//为下一轮输入做初始化 
		tail=new node;
		head->next=tail;
		t=tail;
		t0=head;
	}
	
	//输出结果 
	for(int k=0;k<times;k++){
		for(int j=0;j<1000;j++){
			if(ans[k][j+1]==-1){
				cout<<ans[k][j];
				break;	
			} 
			cout<<ans[k][j]<<" ";
		}
		
		if(k==times-1){
			return 0;
		}
		cout<<endl;
	}
	
}

