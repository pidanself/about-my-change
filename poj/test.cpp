
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
    double left,rigth;//����������¼ÿ��С����x���ཻ����������
}num[1005];
bool cmp(node a,node b)
{
    return a.left<=b.left;//ÿ��С�������갴�պ������С��������
}
int main()
{
    int n,flag,cnt,i,k=1;
    double x,y,d,p;
    while(cin>>n>>d&&n&&d)//��������
    {
        flag=1;
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            if(d<y)//����õ����������״�뾶���״��޷�����
            {
                flag=0;
                continue;
            }
            num[i].left=x-sqrt(d*d-y*y);//�����С��Ϊ���ģ����״�뾶Ϊ�뾶��Բ��x���ཻ�����Һ�����
            num[i].rigth=x+sqrt(d*d-y*y);
        }
        if(flag)//����ܹ��ҵ��ܹ����ǵ���״�
        {
            sort(num,num+n,cmp);//��С��������
            cnt=1;
            p=num[0].rigth;//��һ���״�ĺ�����
            for(i=1;i<n;i++)
            {
                if(num[i].left>p)
                {
                    p=num[i].rigth;//����õ����������״����ô�״��޷����ǣ��������״���Ѹõ���������趨Ϊ�״�
                    cnt++;
                }else if(num[i].rigth<p)//����õ��ܹ����״︲�ǣ���������Ҫ������ٵ��״�����������Ҫʹ�״ﾡ���ܵĶา�ǣ�����Ҫ���״��λ����С
                {
                    p=num[i].rigth;
                }
            }
            cout<<"Case "<<k++<<": "<<cnt<<endl;
        }
        else{//�״ﲻ��ȫ������
            cout<<"Case "<<k++<<": "<<"-1"<<endl;
        }
        //cout<<"Case "<<k++<<": "<<cnt<<endl;
    }
    return 0;
}
