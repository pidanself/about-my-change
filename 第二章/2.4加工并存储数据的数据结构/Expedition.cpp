/*
POJ 2431
Description

A group of cows grabbed a truck and ventured on an 
expedition deep into the jungle. Being rather poor 
drivers, the cows unfortunately managed to run over 
a rock and puncture the truck's fuel tank. The truck 
now leaks one unit of fuel every unit of distance it 
travels. 

To repair the truck, the cows need to drive to the 
nearest town (no more than 1,000,000 units distant) 
down a long, winding road. On this road, between the 
town and the current location of the truck, there are 
N (1 <= N <= 10,000) fuel stops where the cows can stop 
to acquire additional fuel (1..100 units at each stop). 

The jungle is a dangerous place for humans and is 
especially dangerous for cows. Therefore, the cows 
want to make the minimum possible number of stops 
for fuel on the way to the town. Fortunately, the 
capacity of the fuel tank on their truck is so large 
that there is effectively no limit to the amount of 
fuel it can hold. The truck is currently L units away 
from the town and has P units of fuel (1 <= P <= 1,000,000). 

Determine the minimum number of stops needed to reach 
the town, or if the cows cannot reach the town at all. 
Input

* Line 1: A single integer, N 

* Lines 2..N+1: Each line contains two space-separated 
integers describing a fuel stop: The first integer is 
the distance from the town to the stop; the second is 
the amount of fuel available at that stop. 

* Line N+2: Two space-separated integers, L and P
Output

* Line 1: A single integer giving the minimum number 
of fuel stops necessary to reach the town. If it is 
not possible to reach the town, output -1.
Sample Input

4
4 4
5 2
11 5
15 10
25 10
Sample Output

2
Hint

INPUT DETAILS: 

The truck is 25 units away from the town; the truck 
has 10 units of fuel. Along the road, there are 4 
fuel stops at distances 4, 5, 11, and 15 from the 
town (so these are initially at distances 21, 20, 14, and 10 from the truck). 
These fuel stops can supply up to 4, 2, 5, and 10 units of fuel, respectively. 

OUTPUT DETAILS: 

Drive 10 units, stop to acquire 10 more units of fuel, 
drive 4 more units, stop to acquire 5 more units of fuel, 
then drive to the town.

*/ 
//本题思路有点技巧，并且需要用到优先队列与堆得库若不知道库的话写起来会很麻烦 
#include<iostream>
#include<queue>
using namespace std;
int N,L,P,o=0;//N为加油站数量，L为总距离，P为初始卡车油量 

int main(){
	cin>>N>>L>>P;
	int A[N+1],B[N+1];
	for(int i=0;i<N;i++){
		cin>>A[i];
		cin>>B[i];
	} 
	A[N]=L,B[N+1]=0;
	priority_queue<int> que;
	for(int i=0;i<=N;i++){
		if(i==0){
			L=L-A[i];
			P=P-A[i];
		}
		else{
			L=L-(A[i]-A[i-1]);
			P=P-(A[i]-A[i-1]);
		}
		while(P<0){
			if(!que.empty()){
				P=P+que.top();
				que.pop();
				o++;
			}
			else{
				cout<<"无法到达";
				return 0;
			}
		}
		que.push(B[i]);
	}
	printf("至少%d个",o);

	return 0;
}

