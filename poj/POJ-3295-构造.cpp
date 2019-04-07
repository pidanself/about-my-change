//这是我构造的第一版既不正确代码又臃肿
//但是我的思考，下一版见 
#include<iostream>
#include<cstring>
using namespace std;
char s[120];

bool mem[100][2][2]={0};//初始化* 
int m[100]; //初始化为-1* 

bool di(int p,bool t){
	if(p==1){
		return !t;
	}
	else if(p==0){
		return t;
	}
	
	
	if(s[p-1]=='N'){
		return di(p-1,!t);
	}
	else{
		//p-1处字符已经出现过 
		if(m[s[p-1]]!=-1){
			return di(p-2,mem[s[p-2]][m[s[p-1]]][t]);
		}
		//未出现过 
		else{
			bool ans;
			//假设为1
			m[s[p-1]]=1;
			ans=di(p-2,mem[s[p-2]][m[s[p-1]]][t]); 
			//假设为0
			m[s[p-1]]=1;
			ans=ans&&di(p-2,mem[s[p-2]][m[s[p-1]]][t]);
			
			//还原
			m[s[p-1]]=-1;
			
			return ans; 
		}
	}
	
	
	
	
}


int main(){
	memset(m,-1,sizeof(m));
	mem['K'][0][0]=false;
	mem['K'][0][1]=false;
	mem['K'][1][0]=false;
	mem['K'][1][1]=true;
	
	mem['A'][0][0]=false;
	mem['A'][0][1]=true;
	mem['A'][1][0]=true;
	mem['A'][1][1]=true;
	
	mem['C'][0][0]=true;
	mem['C'][0][1]=true;
	mem['C'][1][0]=false;
	mem['C'][1][1]=true;
	
	mem['E'][0][0]=true;
	mem['E'][0][1]=false;
	mem['E'][1][0]=false;
	mem['E'][1][1]=true;
	
	cin>>s;
	int l=strlen(s);
	
	bool ans=di(l-1,false)&&di(l-1,true);
	
	cout<<ans;
	return 0;
}

