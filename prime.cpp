#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>
//素数(有很多种解法...列,牛顿失代)
//判断方法
//一个大于1的自然数，除1和数本身外不能被其它自然数整除的数

// int main(void)
// {
//     int start=100;   //设定起始值
//     int end=200;     //设定结束值
//     int sum,count=0;
//     for(;start<=end;start++)   //for循环要计算的范围值100 - 200
//     {
//        bool judge=0; //bool 标记初始值  ---假 '0'      
//         // for(sum=2;sum<start;sum++)//1(1).试除法（逐个1，2,3...n）
//         for(sum=2;sum<=sqrt(start);sum++)//1(2).试除法（开平方法）
//         {
//             if(start%sum == 0)  //判断能否被除1（和本身）外的自然数整除
//             {
//                 judge=1;        //能整除标记  ---真 '1'
//                 break;
//             }
//         } 
//         if(judge != 1)         //判断标记是否是---假‘0’
//         {
//             count++;
//             printf("%d is prime number.\n",start);
//         }
//     }
//     printf("%d is prime number.\n",start);
//     printf("count is %d\n",count);
//     system("pause");
//     return 0;
// }

// 调用函数
// 是素数返回 1   不是素数返回 0
int prime (int a)
{
    int sum;
    // 逐个计算法
    for(sum=2;sum<a;sum++)
        if(a%sum == 0)
            return 0;       
    return 1;
    // 开平方(试除法)
    // for(sum=2;sum<=sqrt(a);sum++)
    //     if(a%sum == 0)
    //        return 0;
    // return 1;
}
int main(void)
{
    // 打印100-200之间的素数
    int start=100;
    int end=200;
    int count=0;
    for(;start<=end;start++)
    {
        // 判断start是否为素数
        if(prime(start) == 1)
        {
            count++;
            printf("%d  ",start);
        }
    }
    printf("\n altogether=%d\n",count);
    system("pause");
    return 0;
}