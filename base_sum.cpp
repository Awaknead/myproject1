// 进制转换
#include<stdio.h>
#include<stdlib.h>
void to_base_n(unsigned long n,unsigned short t);
int main(void)
{
    unsigned long one;
    unsigned short two;
    printf("enter the integer and n for notation (q to quit ):");
    while(scanf("%lu%hu",&one,&two)==2)
    {
        if(two<2 ||two>10)
        {
            printf("pleasse input n between 2~10 \n");
            printf("Enter the integer and n for notation(q to quit):");
            continue;
        }
        printf("convert %lu to %hu notation is :",one,two);
        to_base_n(one,two);
        putchar('\n');
        printf("Enter integer and n for notation (q to quit ):");

    }
    system("pause");
    return 0;
}
void to_base_n(unsigned long n,unsigned short t)
{
    int r=0;
    r=n%t;
    if(n>=2)
       to_base_n(n/t,t);
    printf("%d",r);
}