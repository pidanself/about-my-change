#include<iostream>
using namespace std;

class node{
	public:
	int val;
	node *next=NULL;
};
//�洢���ս���������
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
		//���Զ���һ������ 
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
		//�������� 
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
	
		//�¶��� 
		t=head->next;
		int j=0;
		while(t->next!=NULL){
			ans[i][j++]=t->val;
			node *tt=t;
			//�ͷ��ڴ� ��ֹ�ڴ�й© 
			t=t->next;
			delete tt;
		}
		ans[i][j++]=t->val;
		delete t->next;
		ans[i][j]=-1;//���������ʱ�����жϺ�ʱ�����������
		 
		//Ϊ��һ����������ʼ�� 
		tail=new node;
		head->next=tail;
		t=tail;
		t0=head;
	}
	
	//������ 
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

