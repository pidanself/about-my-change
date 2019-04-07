#include<iostream>
#include<stack> 
#include<cstring>
using namespace std;
#define K(w,x) (w&&x)
#define A(w,x) (w||x)
#define C(w,x) ((!w)||x)
#define E(w,x) (w==x)


char s[120];
int getc(char s,int i);

//K, A, N, C, E, p, q, r, s, t
bool cal(int l,int i);

int main(){
	
	cin>>s;
	while(s[0]!='0'){
		//对32种情况进行遍历 
		for(unsigned int i=0;i<32;i++){
			bool ans;
			ans=cal(strlen(s),i);
			if(!ans){
				cout<<"not"<<endl;
				break;
			}
			if(i==31) cout<<"tautology"<<endl;
		}
		//重来 
		s[0]='\0';
		cin>>s;
	}
	
	

	return 0;
}

int getc(char s,int i){
	if(s=='K'||s=='A'||s=='N'||s=='C'||s=='E'){
		return 2;
	}
	else{
		switch(s){
			case 'p':
				return (i&1);
			case 'q':
				return ((i>>1)&1);
			case 'r':
				return ((i>>2)&1);
			case 's':
				return ((i>>3)&1);
			case 't':	
				return ((i>>4)&1);
		}
			
	}
}

bool cal(int l,int i){
	//定义一个堆栈 
	stack<int> st;
	
	for(int j=l-1;j>=0;j--){
		int t=getc(s[j],i);
		//s[j]是变量 
		if(t!=2){
			//压栈
			st.push(t); 
		}
		else{
			
			if(s[j]=='N'){
				int w=st.top();
				st.pop();
				st.push(!w);
			}
			else if(s[j]=='K'){
				int w=st.top();
				st.pop();
				int x=st.top();
				st.pop();
				int tt=K(w,x);
				st.push(tt);
			}
			else if(s[j]=='A'){
				int w=st.top();
				st.pop();
				int x=st.top();
				st.pop();
				int tt=A(w,x);
				st.push(tt);
			}
			else if(s[j]=='C'){
				int w=st.top();
				st.pop();
				int x=st.top();
				st.pop();
				int tt=C(w,x);
				st.push(tt);
			}
			else if(s[j]=='E'){
				int w=st.top();
				st.pop();
				int x=st.top();
				st.pop();
				int tt=E(w,x);
				st.push(tt);
			}
		}
		
	}
	//循环结束栈顶即为结果
	return st.top(); 
}

