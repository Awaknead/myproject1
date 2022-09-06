#include<stdio.h>
#include<stdlib.h>
int interght (int  a ,int b);
int main (void)
{
    int a,b,c;
    printf("please enter two value:\n");
    scanf("%d%d",&a,&b);
    c=interght(a,b);
    printf("value and:%d\n",c);
    system("pause");
    return 0;
}
int interght (int a, int b)
{
    int d;
    d=a+b;
    return d;
}