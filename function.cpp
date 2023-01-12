#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<windows.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
// ------------------------------------------------------------函数

// 递归与迭代
// 斐波那契数
// 大于50递归过于浪费内存资源
// 不合适

// int count=0;
// int fibonacci(int long n)
// {
//     if(n == 3)
//        count++;
//     if(n<=2)
//        return 1;
//     else
//        return fibonacci(n-1)+fibonacci(n-2);
// }


// // 非递归方式
// int fibonacci (int long n)
// {
//     int a=1;
//     int b=1;
//     int c=1;
//     // 每次while运行一次n减一
//     // 1  1  2  3  5  8  13  21
//     // 1  2  3  4  5  6  7   8
//     while(n>2)
//     {
//         c=a+b;
//         a=b;
//         b=c;
//         n--;
//     }
//     return c;
// }


// int long fibonacci(long n)
//         {
//             long former1 = 1;
//             long former2 = 2;
//             long target = 0;
//             if (n==0)
//             {
//                 return 0;
//             }
//             if (n==1)
//             {
//                 return 1;
//             }
//             if (n==2)
//             {
//                 return 2;
//             }
//             else
//             {
//                 for (int i = 3; i <= n; i++)
//                 {
//                     target = former1 + former2;
//                     former1 = former2;
//                     former2 = target;
//                 }
//                 return target;
//             }
//         }
// // 斐波切纳递归与非递归
// int main(void)
// {
//     int long sum=0;
//     int acc=0;
//     printf("please enter fibonacci value");
//     scanf("%d",&sum);
//     acc=fibonacci(sum);
//     printf("fibonacci=%ld\n",acc);
//     system("pause");
//     return 0;
// }


// // 求n的阶乘
// int pro_uct(int pt)
// {
//     if(pt <= 1)
//        return 1;
//     else 
//        return pt*pro_uct(pt-1);
// }
// int main(void)
// {
//     int sum=0;//输入值
//     int product=0;//乘阶
//     scanf("%d",&sum);
//     product=pro_uct(sum);
//     printf("%d ",product);
//     system("pause");
//     return 0;

// }


// // 求字符串长度不允许创建临时变量
// int my_strlen (char* str)
// {
//     // // 不允许count创建变量(所以不符合要求)
//     // // 字符串长度计数器
//     // int count=0;
//     // while(str != 0)
//     // {
//     //     count++;
//     //     // 增加字符串地址值
//     //     str++;
//     // }
//     // return count;
//     if(*str != '\0')
//        return 1+my_strlen(str+1);
//     else
//        return 0;
// }
// int main(void)
// {
//     char arr[] ="bit";
//     // strlen计算字符串长度
//     // int len=strlen(arr);
//     // printf("%d \n",len);
//     // 调用函数my_strlen
//     // arr是数组，数组传参，传过去的不是整个数组，而是第一个元素的地址
//     int len= my_strlen(arr);
//     printf("%d \n",len);
// }


// //递归函数
// //主要思考方式
// // 大事化小
// // 1.存在限制条件，当满足这个限制条件的时候，递归便不再继续。
// // 2.每次递归调用之后越来越接近这个限制条件。
// void sum_cp (int n)
// {
//     // 递归限制条件
//     if(n>9)
//     // 递归函数语句
//        sum_cp(n/10);
//     printf("%d ",n%10);
// }
// int main(void)
// {
//     int sum=123;
//     //调用函数
//     sum_cp(sum);
//     printf("\n%d ",sum);
//     system("pause");
//     return 0;
// }


// // 函数的链式访问
// int main(void)
// {
//     //printf函数返回值为int类型（个数）
//     printf("%d",printf("%d",printf("%d",43)));
//     //            1           2         43
//     //4321
//     system("pause");
//     return 0;
// }


// // 函数的嵌套调用
// void new_line (void)
// {
//     printf("hehehehe.\n");
// }
// void three_line (void)
// {
//     int i=0;
//     for(i=0;i<3;i++)
//         new_line();
// }
// int main(void)
// {
//     three_line();
//     system("pause");
//     return 0;
// }


// // 每调用一次函数
// // 函数增加1
// void add (int* p)
// {
//     // 这样是不允许的是错误的
//     //++运算符高于指针‘*’
//     //*p++;
//     (*p)++;
// }
// int main(void)
// {
//     int num=0;
//     // 调用函数使用传地址的方法
//     add(&num);
//     printf("unm = %d\n",num);
//     add(&num);
//     printf("unm = %d\n",num);
//     add(&num);
//     printf("unm = %d\n",num);
//     system("pause");
//     return 0;
// }


// // 传值调用Sweap1
// // 函数形参和实参分别占有不同内存块
// // 形参的修改不会影响实参
// void Sweap1(int x,int y)
// {
//     int temp;
//     temp=x;
//     x=y;
//     y=temp;
// }
// // 传址调用Sweap2
// // 函数外部的变量的内存地址传递给函数参数
// // 使得函数和外部函数的变量建立起联系
// // 函数内部可以直接操作函数外部变量
// void Sweap2(int *x,int *y)
// {
//     int temp;
//     temp=*x;
//     *x=*y;
//     *y=temp;
// }
// int main(void)
// {
//     int a=10;
//     int b=20;
//     printf("one  a=%d,b=%d.\n",a,b);
//     // 调用Sweap1函数
//     Sweap1(a,b);
//     printf("two  a=%d,b=%d.\n",a,b);
//     // 调用Sweap2函数
//     Sweap2(&a,&b);
//     printf("three a=%d,b=%d.\n",a,b);
//     system("pause");
//     return 0;
// }



// void swap (int x,int y)
// 当实参传给形参的时候
// 形参其实是实参的一份临时拷贝
// 对形参的修改是不会修改实参

// memset 内存设置 
// memory -- 计算机（寄存器(内存)）   set -- 设置
// void * memset(void * ptr,int value,size_t num);
//                    指针 ，要设置的值， 要设置值的字节数
// int main(void)
// {
//     // arr指针   -- ptr
//     char arr[]={"hello world"};
//     // int value -- 要设置'*'
//     // size_t num --  要设置值的字节数 -- 6字节
//     memset(arr,'*',6);
//     printf("%s\n",arr);
//     system("pause");
//     return 0;
// }


// int main(void)
// {
//    // strcpy函数(字符串拷贝)
//    // char * strcpy (char * destination, const char * source);
//    //                         目的地                    源头
//     char arr1[]="bit";          //源头
//     char arr2[20]="#########";  //目的地
//    // arr1拷贝到arr2;
//     strcpy(arr2,arr1);
//    // 打印arr2的值是否拷贝成功
//     printf("%s\n",arr2); 
//     system("pause");
//     return 0;
// }

