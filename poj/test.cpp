
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
struct node{
    double left,rigth;//我们用来记录每个小岛与x轴相交的左右两点
}num[1005];
bool cmp(node a,node b)
{
    return a.left<=b.left;//每个小岛左坐标按照横坐标从小到大排序
}
int main()
{
    int n,flag,cnt,i,k=1;
    double x,y,d,p;
    while(cin>>n>>d&&n&&d)//输入数据
    {
        flag=1;
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            if(d<y)//如果该点的纵坐标比雷达半径大，雷达无法覆盖
            {
                flag=0;
                continue;
            }
            num[i].left=x-sqrt(d*d-y*y);//求出以小岛为中心，以雷达半径为半径的圆与x轴相交的左右横坐标
            num[i].rigth=x+sqrt(d*d-y*y);
        }
        if(flag)//如果能够找到能够覆盖点的雷达
        {
            sort(num,num+n,cmp);//从小到大排序
            cnt=1;
            p=num[0].rigth;//第一个雷达的横坐标
            for(i=1;i<n;i++)
            {
                if(num[i].left>p)
                {
                    p=num[i].rigth;//如果该点的左坐标比雷达大，那么雷达无法覆盖，则增加雷达，并把该点的右坐标设定为雷达
                    cnt++;
                }else if(num[i].rigth<p)//如果该点能够被雷达覆盖，但是我们要求出最少的雷达数，我们需要使雷达尽可能的多覆盖，所以要把雷达的位置缩小
                {
                    p=num[i].rigth;
                }
            }
            cout<<"Case "<<k++<<": "<<cnt<<endl;
        }
        else{//雷达不能全部覆盖
            cout<<"Case "<<k++<<": "<<"-1"<<endl;
        }
        //cout<<"Case "<<k++<<": "<<cnt<<endl;
    }
    return 0;
}
