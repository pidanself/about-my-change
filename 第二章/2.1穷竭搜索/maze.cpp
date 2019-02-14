//迷宫问题 
#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int> P;
const int INF=10000000;

int main(){
	char maze[100][100];
	int N,M;
	cout<<"请输入maze规模"<<endl;
	cin>>N>>M;
	int sx,sy;
	int gx,gy;
	cout<<"请输入maze构造，#墙，.通道，S起点，G终点"<<endl;
	for(int x=0;x<N;x++){
		for(int y=0;y<M;y++){
			cin>>maze[x][y];
			if(maze[x][y]=='S'){
				sx=x;
				sy=y;
			}
			else if(maze[x][y]=='G'){
				gx=x;
				gy=y;
			}
		}
	}
	cout<<"输入结束"; 
	int d[100][100];
	for(int x=0;x<N;x++){
		for(int y=0;y<M;y++){
			d[x][y]=INF;
		}
	}
	
	//四个方向移动的向量
	int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
	queue<P> que;
	que.push(P(sx,sy));
	d[sx][sy]=0;
	while(que.size()){
		P p=que.front();que.pop();
		if(p.first==gx&&p.second==gy){
			break;
		}
		for(int i=0;i<4;i++){
			int nx=dx[i]+p.first;
			int ny=dy[i]+p.second;
			
			if(maze[nx][ny]!='#'&&nx<N&&nx>=0&&ny<M&&ny>=0&&d[nx][ny]==INF){
				que.push(P(nx,ny));
				d[nx][ny]=d[p.first][p.second]+1;
			}
			
		}
		
	}
	cout<<"最短距离为"<<d[gx][gy];


	return 0;
}

