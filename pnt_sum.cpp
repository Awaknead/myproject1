#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<windows.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>

// ------------------------------------------------------------数组

// // sizeof(数组名)，计算整个数组的大小，(表示整个数组)
// // &数组名，取出的是数组的地址。(表示整个数组)
// // 除了(sizeof(*)  /  &*)以外.其他数组名表示的都是数组首元素的地址
// // 冒泡排序
// // 数组按照顺序排序
// void array_sorting(int arr[],int n)
// {
//     //  arr[]元素首地址
//     // n   arr[]元素个数
//     int i; //一趟for计数值
//     int k; //一趟元素要执行的次数
//     // int judge;//判断是否需要排序
//     for(i=0;i<n-1;i++)  //一趟for执行语句n10个元素
//     {
//        // 数组是第0元素开始0~9  10个元素 
//         // judge=1;
//         for(k=0;k<n-1-i;k++)
//         {
//         // 每次元素冒泡排序每次减一
//         // 第一次0~9  10个元素
//         // 第二次0~8  9个元素
//         // 第三次0~7  8个元素
//         //...
//         // 第八次0~1  1个元素
//             if(arr[k] > arr[k+1])
//             {
//                 int temp=arr[k];
//                 arr[k]=arr[k+1];
//                 arr[k+1]=temp;
//                 // judge=0;
//             }
//         }
//         // if(judge == 1)
//         // {
//         //     break;
//         // }
//     }
// }
// int main(void)
// {
//     // 数组
//     // 数组 
//     int arr[]={9,2,4,6,7,0,3,17,38};
//     // int arr[]={9,8,7,6,5,4,3,2,1,0};
//     int i=0;
//     // 数组元素个数
//     int sz=sizeof(arr)/sizeof(arr[0]);//10个元素
//     array_sorting(arr,sz);
//     for(i=0;i<sz;i++)
//     {
//         printf("%d--",arr[i]);
//     }
//     system("pause");
//     return 0;
// }

// ------------------------------------------------------------循环

// //猜数字游戏(number gessing game)
// #define SEP 40 //分隔符长度
// #define LIST "Number gessing game"
// #define ONE "1.play"
// #define TWO "2.quit"
// #define JUDGE 1
// // 游戏内容
// void gameplay (unsigned k)
// {
//     unsigned i;//用户输入值
//     printf("Enter the number you guessed.\n");
//     while(1)
//     {
//         //注意
//         //要先if判断大在判断小
//         //如果if判断小在判断大会永远找不到要猜的数字
//         if(scanf("%lu",&i) == 1)
//         {
//             //输入大了
//             if(i>k)
//               printf("You guess is worth a lot.\n");
//             //输入小了
//             else if(i<k)
//                  printf("You guess is low.\n");
//             else if(i==k)
//             {
//                 printf("You guess bingo.\n");
//                 break;
//             }
//         }
//         //读取换行符和其它字符
//         else
//         {
//             while(getchar() != '\n')
//                 continue;
//             continue;
//         }
//     }
// }
// // 随机函数
// unsigned random(void)
// {
//     int k;
//     //时间戳--来设置随机数起点
//     srand( (unsigned)time( NULL ) );
//     //模上100 随机值范围在1-99之间
//     //模上1000 随机值范围在1-999之间
//     k=rand()%100;
//     return k;
// }  
// //分隔符函数
// void separator (void)
// {
//     int i;
//     for(i=0;i<SEP;i++)
//        putchar('*');
//     putchar('\n');
// }
// // 居中函数
// void center (int i)
// {
//     int sum;
//     int x;
//     //（边框总长-字符数）/2  获得居中值
//     sum=(SEP-i)/2;
//     //输出空格
//     for(x=0;x<sum;x++)
//        putchar(' ');
// }
// // 目录函数
// int list (void)
// {
//     separator();//分隔符
//     center(strlen(LIST));
//     printf("%s\n",LIST);
//     center(strlen(ONE));
//     printf("%s\n",ONE);
//     center(strlen(TWO));
//     printf("%s\n",TWO);
//     separator();
//     //分端口输入值
//     int i;
//     //判断变量
//     int judge;
//     //随机值
//     unsigned k;
//     //判断输入是否正确
//     while(1)
//     {
//         if(scanf("%d",&i) == 1)
//         {
//             if(i == 1 || i == 2)
//               break;
//             else
//               continue;
//         }
//         else
//         {
//             while(getchar() != '\n')
//                 continue;
//             continue;
//         }
//     }
//     // 执行分端接口
//     switch(i)
//     {
//         //play 接口
//         case 1:
//             system("cls");
//             k=random();
//             gameplay(k);
//             judge=1;
//             break;
//         //quit 接口
//         case 2:
//             system("cls");
//             printf("Game over.\n");
//             judge=0;
//             break;
//     }
//     return judge;
// }

// int main(void)
// {
//     int judge;
//     do
//     {
//         judge=list();
//         system("cls");
//     } while (judge == 1);
//     system("pause");
//     return 0;
// }


// //9*9乘法口诀表
// //        列=1 ---------------|=9
// // 行=1 |1*1=1 |                     
// //  .   |2*1=2 |2*2=4 |
// //  .   |3*1=3 |3*2=6 |3*3=9
// //  .   |...
// //  .=9 |9*1=9 |...   |...    |9*9=81
// //  
// //先确定列=9，设定为i;
// //在确定列,一行有i列，所以设定为j;
// int main(void)
// {
//     int i;//列=9
//     int j;//行=9
//     //先定列i
//     for(i=1;i<=9;i++)
//     {
//         //在定行
//         for(j=1;j<=i;j++)
//         {
//             printf("%d*%d=%-2d ",i,j,i*j);
//             //%2d(右对齐)   %-2d(左对齐)
//         }
//         printf("\n");
//     }
//     system("pause");
//     return 0;
// }

// //求最大值
// int main(void)
// {
//     //比较法
//     int arr[]={1,2,3,4,5,6,7,8,9,10};//数组定范围
//     //int max=0;   //如果数组地址储存值为负数，该max=0是错误的
//     int max=arr[0];//最大值初始化，随机定义数组arr[0]为 max
//     int siz=sizeof(arr)/sizeof(arr[0]);//数组值
//     int i;//for计数值, 数组定义的max值，i的值可以从1开始
//     for(i=1;i<siz;i++)
//     {
//         if(arr[i]>max)//比较法数组arr[i]大于max
//           max=arr[i]; //将arr[i]值赋给max
//     }                 //arr[i]<max 则跳过if语句
//     printf("max=%d",max);
//     system("pause");
//     return 0;
// }

// // 分数求和
// int main(void)
// {
//     int i;
//     double sum=0.0;
//     int flag=1;
//     for(i=1;i<=100;i++)
//     {
//         sum+=flag*1.0/i;//   1/1-1/2+1/3-1/4...1/99-1/100=sum  求和
//         flag=-flag;      //负负得正
//     }
//     printf("%lf is",sum);
//     system("pause");
//     return 0;
// }

// //模数，商数的运用
// //模数(余数)---列模10(%10)  --得1.4,1.8,2.9  --取‘.’后的值 .4  .8  .9
// int main(void)
// {
//     int i;//计数
//     int count=0;//累积值
//     for(i=0;i<100;i++)
//     {
//         if(i%10 == 9) //余9  99判断第1次
//         {
//            printf("%d ",i); 
//            count++;  
//         }
           
//         if(i/10 == 9)  //商9  99判断第2次
//         {
//             printf("%d ",i);
//             count++;
//         }
//     }
//     printf("\n count is %d .\n",count);
//     system("pause");
//     return 0;
// }

// //素数(有很多种解法...列,牛顿失代)
// //判断方法
// //一个大于1的自然数，除1和数本身外不能被其它自然数整除的数
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
//     printf("count is %d\n",count);    
//     system("pause");
//     return 0;
// }

// //计算闰年
// //用年份除以4。因为每四年增加一日，所以用年份除以四，不能整除的就是平年，能够整除的多数是闰年。
//     //例如：2019年是不是闰年呢？用2019*4=504·····3，不能整除，所以2019年是平年。
// //非世纪年（即年份最后两位不都是0）能够被四整除且不能被100整除的年份为闰年。
//     //例如2020年，2020*4=505,2020*100=20.2,2020能够被4整除，且不能被100整除，所以2020年是闰年。
// //世纪年（即年份最后两位都是0）能够被400整除的才是闰年，
//     //例如2000年，2000*400=5，所以2000年为闰年，2100年，2100*400=5·····100
// int main(void)
// {
//     int start,end,count=0;
//     printf("start\n");
//     scanf("%d",&start);
//     printf("end\n");
//     scanf("%d",&end);
//     // 判断闰年并计数和显示年份
//     for(;start<=end;start++)
//     {
//         // if(start%100 == 0)
//         // {
//         //     if(start%400 == 0)
//         //     {
//         //        printf("%d0000000leap\n",start); 
//         //        count++;
//         //     } 
//         // }
//         // else
//         // {
//         //     if(start%4 == 0)
//         //     {
//         //         printf("%dleap\n",start); 
//         //         count++;
//         //     }
//         // }
//         if(((start%4 == 0) && (start%100 != 0)) || (start%400 == 0))
//         {
//             printf("%d ",start);
//             count++;
//         }
//     }
//     printf("leap year haue %d.\n",count);
//     //计算闰年数  （设0~n，n为年）
//     // int(n%4)-int(n%100)+int(n%400)
//     printf("leap year is %d years total.\n",((end/4)-(end/100)+(end/400)));
//     system("pause");
//     return 0;
// }



// //最大公约数(辗转相除法)
// //运算方法
// //st3=st1%st2,st3等于0，st2就是最大公约数
// //st3=st1%st2,st3不等于0，则st2赋值给st1---st3赋值给st2，在进行st3=st1%st2运算(判断)---循环直到等于0
// int main(void)
// {
//     int m,n,r;//st1,st2,st3
//     scanf("%d%d",&m,&n);
//     //while(m%n)     重复m%n运算
//     while(r=m%n)    //运算合并 判断m%n是否不等于0 （st3=st1%st2）
//     {
//         //r=m%n;
//         m=n;           //st1=st2;
//         n=r;           //st2=st3;
//     }
//     printf("%d",n);//最大公约数
//     system("pause");
//     return 0;
// }



// // 3的倍数
// int main(void)
// {
//     int i;
//     for(i=1;i<=100;i++)
//     {
//         if(i%3 == 0)
//            printf("%d \n",i);
//     }
//     system("pause");
//     return 0;
// }


// // 从大到小(指针的错误用法)
// int main(void)
// {
//     int A=1,B=2,C=0;
//     int *a=&A;  //*a只是表示定义的是个指针变量，并没有间接取值的意思
//     int *b=&B;  //*b=2 是错误的(除*b=0 该语句表示指针为空)
//     int *c=&C;
//     // Int *s=15;
//     // Int *s={2,3,5};
//     // Int *s=a;
//     // 以上都是错误的
//     int temp;//转移
//     if(*a < *b)
//     {
//         temp=*a;
//         *a=*b;
//         *b=temp;
//     }
//     if(*a < *c)
//     {
//         temp=*a;
//         *a=*c;
//         *c=temp;
//     }
//     if(*b < *c)
//     {
//         temp=*b;
//         *b=*c;
//         *c=temp;
//     }
//     printf("%d,%d,%d\n",*a,*b,*c);
//     printf("%p,%p,%p\n",*a,*b,*c);
//     system("pause");
//     return 0;
// }

// //用户密码--字符串判断strcmp()函数
// #define PASS "123456"
// int main(void)
// {
//   int i=0;//计算
//   char pass[20]={0};//字符串变量，[20]字节，{0}初始化0；
//   for(i=0;i<3;i++)
//   {
//     printf("Enter user password:>");
//     scanf("%s",pass);
//     //strcmp()函数文件头 ---#include<windows.h>
//     //strcmp(st1,st2);strcmp函数比较两字符串；st1=st2,则返回0；st1>st2,则返回正数'1'；st1<st2,则返回负数'-1'
//     if(strcmp(pass,PASS) == 0)//== 不能用来比较两个字符串是否相等，应该使用一个库函数-strcmp(介入值，常量值)
//     {
//       printf("success.\n");   //登录成功
//       break;
//     }
//     printf("%d\n",strcmp(pass,PASS));//输出strcmp()函数比较值
//   }
//   if(i==3)
//   {
//     printf("Password error.\n");//登录失败
//   }
//   system("pause");
//   return 0;
// }
// 数组替换数组(循环结构)
// int main (void)
// {
//   char ch1[]="welcome to bit!!!!!";
//   char ch2[]="###################";
//   int left=0;
//   int right=strlen(ch1)-1;//strlen计算字符串长度(不包括\0空白符)  sizeof计算对象总体大小(包括\0空白符)
//   while(left<=right)//ch1替换ch2
//   {
//     ch2[left]=ch1[left];//数组左侧开始
//     ch2[right]=ch1[right];//数组右侧开始
//     printf("%s\n",ch2);
//     //休息1秒
//     Sleep(1000);
       //system()函数头文件 ----#include<stdlib.h>
//     system("cls");//执行系统命令的一个函数 cls-清空屏幕
//     left++;
//     right--;
//   }
//   system("pause");
//   return 0;
// }

   
// //二分查找法
// int main(void)
// {
//     int arr[]={1,2,3,4,5,6,8,9,10,11};//数组
//     int range=sizeof(arr)/sizeof(arr[0]);//范围
//     int left=0;//右下标
//     int right=range-1;//左下标
//     int mid;//中间值
//     int find;//查找值
//     printf("Enter the find value:\n");
//     scanf("%d",&find);
//     while(left<=right)
//     {
//       mid=(left+right)/2;//二分查找法计算公式
//       if(arr[mid] < find)
//         left=mid+1;
//       else if(arr[mid] > find)
//         right=mid-1;
//       else 
//         {
//           printf("The value %d is stored in the array subscript %d\n",find,mid);
//           break;
//         }
//     }
//     if(left>right)
//     {
//       printf("No in array.\n");
//     }
//     system ("pause");
//     return 0;
// }

// //for数组联合使用
// int main(void)
// {
//   int arr[]={1,2,3,4,5,6,7,8,9,10};
//   int find;//查询值
//   int range;//范围值
//   int i;   //for计数
//   printf("Enter the find value:\n");
//   scanf("%d",&find);
//   range=sizeof(arr)/sizeof(arr[0]);//sizeof计算数组范围   总字节数 除以 单个字节数
//   for(i=0;i<range;i++)
//   {
//       if(find==arr[i])
//       {
//         printf("The value %d is stored in the array subscript %d\n",find,i);
//         break;
//       }
//   }
//   if(i==range)
//   {
//     printf("No in array.\n");
//   }
//   system("pause");
//   return 0;
// }


// for 循环练习
// int main(void)
// {
//     int end=0;
//     int start=1;
//     int factorial,i,j;  //阶乘
//     printf("Enter the value of factorial:"); 
//     scanf("%d",&factorial);
//     printf("\n");
//     for(i=1;i<=factorial;i++)
//     {
//       start*=i;
//       // for(j=1,start=1;j<=i;j++)     //优化代码sum*=i
//       // {
//       //   start*=j;
//       //   printf("start=%d factorial=%d\n",j,start);
//       // }
//       end+=start;
//       printf("value=%d  factoral=%d  end=%d\n",i,start,end);    
//     }
    // for(i=1;i<=factorial;i++)
    // {
    //   start*=i;   //阶乘计算1*2*3...*n
    //   printf("start=%d factorial=%d\n",i,start); 
    // }
//     printf("factorial end=%d\n",end);
//     system("pause");
//     return 0;
// }

// int main (void)
// {
//     int i=1;
//     do                          //do{}while循环
//     {
//        if(1==(i%2))
//          printf("i=%d\n",i);
//     }while(++i<100);
//     // while(++i<=100)           //while循环
//     // {
//     //   if(1==(i%2))
//     //     printf("i=%d\n",i);
//     // }
//     // for(i=1;i<=100;i++)       //for循环
//     // {
//     //   if(1==(i%2))
//     //     printf("i=%d\n",i);
//     // }
//     system("pause");
//     return 0;
// }
// int main()
// {
//    int num=3;
//    if(4==num)  //if判断语句将判断常量放在左侧是一个好的代码风格
//    {
//       printf("hehe\n");
//    }
//    system("pause");
//    return 0;
// }
// // 结构体类型
// struct book {
//   char name[22];
//   int price;
// };
// int main(void)
// {
//   // 利用结构体类型-创建一个该类型的结构体变量
//    struct book c ={"c语言程序设计",109};
//    strcpy(c.name,"c++");                      //strcpy-string copy -字符串拷贝-库函数-头文件（string.h）
//   //  struct book* pd = &c;                   //struct book* 指针类型  
//   //  printf("book naame is :%s\n",(*pd).name);   //.结构体变量，指向成员
//   //  printf("book price is :%d\n",(*pd).price);  
//   // printf("%s\n",pd->name);                        //->结构体指针,指向成员
//   // printf("%d\n",pd->price); 
//     printf("book name is :%s\n",c.name);
//   //  printf("book price is :%d\n",c.price);
//     c.price=181;                        //修改结构体值
//     printf("book price is :%d\n",c.price);
//    system("pause");
//    return 0;
// }


// #define SINE 4
// int main(void)
// {
//     short one[SINE];
//     short * pit;                      //pit指向short类型的指针
//     short index;
//     double two[SINE];
//     double * ptf;                    //ptf指向double类型的指针
//     pit=one;
//     ptf=two;
//     printf("%23s  %15s\n","short","double");
//      for(index=0;index<SINE;index++)
//        printf("pointers + %d: %10p %10p\n",index,pit+index,ptf+index);
//     system("pause");
//     return 0;
// }