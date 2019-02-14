//�Թ����� 
#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int> P;
const int INF=10000000;

int main(){
	char maze[100][100];
	int N,M;
	cout<<"������maze��ģ"<<endl;
	cin>>N>>M;
	int sx,sy;
	int gx,gy;
	cout<<"������maze���죬#ǽ��.ͨ����S��㣬G�յ�"<<endl;
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
	cout<<"�������"; 
	int d[100][100];
	for(int x=0;x<N;x++){
		for(int y=0;y<M;y++){
			d[x][y]=INF;
		}
	}
	
	//�ĸ������ƶ�������
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
	cout<<"��̾���Ϊ"<<d[gx][gy];


	return 0;
}

