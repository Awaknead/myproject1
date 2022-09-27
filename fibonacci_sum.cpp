// 斐波那契数列
#include<stdio.h>
#include<stdlib.h>
// for循环
void fibonacci(int one);
// 递归
int fibonacci_recursion(int one);
int main(void)
{
    int value;
    printf("Enter fibonacci value:\n");
    scanf("%d",&value);
    printf("%d fibonacci number storage value is :\n",value);
    printf("for.");
    fibonacci(value);
    printf("recursion=%d",fibonacci_recursion(value));
    system("pause");
    return 0;
}
void fibonacci(int one)
{
    int temp;
    int f1=0;
    int f2=1;
    for(int i=1;i<one;i++)
    {
        temp=f1+f2;
        f1=f2;
        f2=temp;
    }
    printf("%d",f2);
}
int fibonacci_recursion(int one)
{
    if(one<2)
       return one;
    else 
        return fibonacci_recursion(one-1)+fibonacci_recursion(one-2);
    printf("one=%d",one);
}