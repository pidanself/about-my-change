#include<stdio.h>

int main()
{
    int s, d, t;

    while(scanf("%d%d", &s, &d) != EOF)
    {
        if(4*s <= d)
            t=10*s - 2*d;
        else if(3*s <= 2*d)
            t=8*s-4*d;
        else if(2*s <= 3*d)
            t=6*s-6*d;
        else if(s <= 4*d)
            t=3*s-9*d;
        else
            t=-1;

        if(t>=0)
            printf("%d\n", t);
        else
            printf("Deficit\n", t);
    }
    return 0;
}
