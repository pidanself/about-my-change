#include<iostream>
#include<stack>
#include<queue> 
using namespace std;

int main(){
	//��ջ��ʹ�� 
	stack<int> s;
	s.push(3);
	s.push(5);
	cout<<s.top();
	s.pop();
	cout<<endl<<s.top();
	s.pop();
	//���е�ʹ��
	queue<int> p;
	p.push(1);
	p.push(2);
	p.push(3);
	cout<<p.front();
	p.pop();
	cout<<endl<<p.front();
	
	return 0;
}

