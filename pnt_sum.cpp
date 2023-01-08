#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<windows.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
// ------------------------------------------------------------指针

//字符指针
// ""在双引号内的是常量字符串无法修改
// 1.使用字符数组变量 -配合指针使用   -char* p=arr; // 字符变量char arr[]="hello";
// 2.使用常量字符串"" -配合指针使用   -char* p="hello";
int main()
{
    // char* p= "hello";//"hello"是一个常量字符串  因该使用const关键字
    const char* p= "hello world";
    // *p = "hello world";//对象是const常量字符串无法修改
    printf("%c\n",*p);//指向的是"hello"的字符串 - 首字符地址"h"的地址
    printf("%s\n",p);//指向的是"hello"的字符串地址
    // char arr[]="agbdg";//字符串数组
    // char* p=arr;//字符串数组指针变量
    // // *p = "hello world";//对象是const常量字符串无法修改
    // // *p - 指向arr首元素地址 - 首元素地址内容就是字符串本身“agbdg”
    // printf("%s\n",p);
    // printf("%s\n",arr);
    system("pause");
    return 0;
}

// // 指针数组 - 数组 -存放指针的数组
// // 整型数组 - 存放整型
// // 字符数组 - 存放字符
// // 指针数组 - 存放指针
// int main()
// {
//     int a=10;
//     int b=29;
//     int c=40;
//     // int arr[10]={1,2,3,4,...,9};//是一个整型数组
//     int* arr1[3]={&a,&b,&c};//是一个存放整型指针的数组
//     int sz=sizeof(arr1)/sizeof(arr1[0]);
//     //访问指针数组中的值
//     for(int i=0;i<sz;i++)
//     {
//         // *(arr[i])  - 解引用arr[i] - arr[0]=&a  
//         printf("%d ",*(arr1[i]));
//     }
//     system("pause");
//     return 0;
// }

// //二级指针
// int main()
// {
//     int a=10;
//     int* b=&a;//一级指针 int* b - *b(是一个指针变量)指向一个int类型
//     int** p=&b;//二级指针 int** p - *p(是一个指针变量)指向一个int*类型
//     int*** g=&p;//三级指针 int*** g - *g(是一个指针变量)指向一个int**类型
//     //四级指针,五级指针...n级指针
//     ***g=19;//可以直接修改a的值
//     printf("%d\n",***g);//可以直接访问到a的值
//     printf("%d",a);
//     system("pause");
//     return 0;
// } 

// // 地址-首元素地址不同使用方法
// int main()
// {
//     // 相同都为arr首地址但加1的字节量是不一样的
//     int arr[10]={0};
//     //取地址arr - 为arr首地址arr[0]
//     printf("%p\n",arr);
//     //取地址arr+1 - 为arr首地址arr[0]元素加1 = arr[1]  加4字节
//     printf("%p\n",arr+1);
//     //取地址&arr[0] - arr首地址arr[0]
//     printf("%p\n",&arr[0]);
//     //取地址&arr[0]+1 - &arr[0]元素加1 = &arr[1]   加4字节
//     printf("%p\n",&arr[0]+1);
//     //取地址&arr - 为arr首地址arr[0]
//     printf("%p\n",&arr);
//     //取地址&arr+1 - 为arr整个数组全部地址加相同元素的数组地址
//     // 0x00df0 +1  = 0x00e18   跨越40个字节
//     printf("%p\n",&arr+1);
//     system("pause");
//     return 0;
// }

//多维数组和指针
// int main()
// {
//     //多维数组
//     //arr = arr[0][0]
//     //arr[0] = arr[0][0]
//     //*arr = arr[0][0]
//     int arr[3][2]={{1,2},{3,4},{5,6}};
//     //*arr[0]  等于  arr[0][0]
//     // printf("%d\n",*arr[0]);
//     // *(*(arr+n)+n)  等于  arr[0][0]
//     // printf("%d\n",*(*(arr)+5));
//     // *arr[1]  等于  arr[1][0]
//     printf("%d\n",*(*(arr+2)));
//     system("pause");
//     return 0;
// } 

// const使用注意事项
// 把const和非const数据的地址初始化为指向const的指针或为其赋值时合法的
// 然而，非const数据的地址只能赋给普通指针
// 如果，将const数据的地址赋给普通指针是非法的 error:
// int main()
// {
//     double rates[5]={88.61,445.4,225.48,776.556,345.3};
//     const double locked[4]={0.0388,0.01,0.06,0.0498};//const不允许更改数组元素内参数
//     // double* pc=rates;
//     const double* pc=rates;
//     pc=locked;
//     pc=&rates[3];
// }

// // 数组指针 - 指针
// // void show(int* x,int y)
// // {
// //     for(int i = 0; i<y; i++)
// //     {
// //         printf("%d,%d,%p\n",i,x[i],x[i]);
// //     }
// // }
// int main()
// {
//     int arr[10] = {0};
//     int* b=arr; //指针存放数组首元素的地址
//     int sz=sizeof(arr)/sizeof(arr[0]);
//     for(int i=0; i<sz; i++)
//     {
//         // 使用指针解引用访问数组下标并赋值
//         *(b+i)=i;
//     }
//     for(int i=0; i<sz; i++)
//     {
//         // printf("%d ",arr[i]);  //直接访问数组下标
//         printf("%d  ",*(b+i));  //使用指针解引用访问数组下标
//     }
//     // int a[5]={15,23,44,55,65};
//     // int* b=a;
//     // int sz=sizeof(a)/sizeof(a[0]);
//     // for(int i=0;i<sz;i++)
//     // {
//     //     printf("%d,%d,%p\n",i,b[i],b[i]);
//     // }
//     // // show(b,sz);
//     system("pause");
//     return 0;
// }

// 指针运算只作用于数组中，结果才是可以预测的
// 非指向数组元素的指针执行算术运算都是非法的
// int main(void)
// {
//     // char a[10]="shutdown";//数组本身就是地址strlen(a)可以直接调用
//     char a[7]={1,2,3,4,5,6,7};//
//     // char* b=&a;
//     // assert(a!=NULL);
//     // *b=a++;
//     for(int i=0; i<7; i++)
//     {
//         printf("%p\n",a[i]);
//     }
//     char* p=a;
//     // printf();函数表达式运算方法由右至左进行计算，
//     // 指针为例*p=a(首元素地址) 
//     // 先执行--*p = {a[0]-1 =a[-1](非法地址)} 
//     // 在执行++*p ={在a[-1]的基础上加1 = a[-1]+1 =a[0] 数组首元素}
//     // printf("%d\n",p+4);//增加的是p指针地址里的值(是非法的)
//     // printf("%d,%d\n",++*p,--*p);//指针只有在解引用后才能指向指针所指向的变量地址里的值*p+n,*(p+n)等同于a[n]  
//     // // {1访问a[0]  ,0(越界访问a[-1])}
//     // printf("%p,%p\n",++*p,--*p);
//     system("pause");
//     return 0;
// }
//假设变量a储存在100所储存的变量里
// *100=25；//字面值100的类型是整型，而间接访问操作只能作用于指针类型表达式
// 这是非法的，如果必须使用--强制类型转换
// *(int*)100=25;
// 强制类型转换把值100从‘整型’转换为‘指向整型的指针’

// 指针的指针
// int a=12;  //变量a            12赋值给a
// int* b=&a; //指针变量b        a的地址赋值给指针变量b
// int** c=&b;//指针的指针变量c   b的地址赋值给指针变量c *解引用b的地址指向a的地址(双重间接访问‘int** c’)
// int main(void)
// {
//     int a=12;
//     int* b=&a;
//     int** c=&b;
//     printf("%p,%p,%p,%p\n",a,*b,b,**c);
//     system("pause");
//     return 0;
// }

//在数组作为函数指针形参时. 1.可修改 2.不可修改
// // 1.需要修改数组原始数据
// void sum (int* arr,int siz,int val)
// {
//     for(int i=0;i<siz;i++)
//     // 将数组元素中的值都加val值
//        arr[i]+=val;
// }
// // 2.不需要修改数组原始数据.使用const 是将数组视为常量，不可更改
// void sum(const int* arr, int count)
// {
//     // 保护数组防止被修改
//     int count = 0;
//     for(int i=0;i<siz;i++)
//     // 计算数组中值和
//        count += arr[i];
// }

// // 指针的关系运算
// int my_strlen(char* str)
// {
//     // // 2.计算数组个数‘递归’
//     // if(*str != '\0')
//     // {
//     //     return 1+my_strlen(str+1);
//     // }
//     // else
//     //    return 0;
//     // //3.计算数组个数‘指针-指针’
//     // char* start=str;
//     // char* end=str;
//     // while(*end != '\0')
//     // {
//     //     *end++;
//     // }
//     // // 指针-指针  计算数组元素个数
//     // return end - start;
// }
// int main(void)
// {
//     // int value[5];
//     // int* p;
//     // // 判断指针地址在有效地址范围内
//     // //标准规定
//     // //允许指向数组元素的指针与指向数组最后一个元素后面的那个内存未知的指针比较
//     // //但是不允许与指向第一个元素之前的那个指针进行比较
//     // for(p =&value[0];p<&value[5];)
//     // for(p =&value[5];p>&value[0];)
//     // {
//     //     *p++ = 0;
//     // }
//     char arr[]="bitgged";
//     int len =my_strlen(arr);
//     // 1.计算数组个数‘计数器’
//     printf("%d",strlen(arr));
//     printf("%d",len);
//     system("pause");
//     return 0;
// }

// //指针差，两指针相减:
// //1.指针进行加减法运算的整数也有确定且苛刻的要求
// //   -可以指向数组元素，可以指向数组最后一个元素之后第一个元素
// //   -但绝对不可以指向数组之前的元素（即a-1是不可以的）
// //2.两个指针的减法也是有前提条件:
// //   -两个指针必须是指向同一数组元素或者指向数组元素最后一个元素之后的第一个元素
// int main(void)
// {
//  int ar[6] = {1,5,8,7,6,8};
//  int *p1,*p2;
//  p1 = ar;//指向ar数组首元素地址
//  p2 = &ar[4];
//  for(int i=0; i<5; i++)
//     printf("%d - %p - %d\n",i,p2=&ar[i],ar[i]); 
//  printf("%p,%p,%d,%p,%d,%d\n",p1,p2,p2-p1,p2-2,p2,*p2);
//  printf("%d\n",sizeof(int));
// //  p2=&ar[i]  p2=6  
// //  %d p2=(随机正值) 他指向的是指针变量的地址里的值
// //  %d *p2=6(解引用可以找到指针变量所指向地址里的值)
// //  p1 =0x22fe20   p2 =0x22fe30  4个int类型  int（4个字节）
// //  差的结果为4，意思是两个指针指向的元素差4个int类型，不是四个字节
// //  指针减指针等于中间的元素个数
// // 因为指针使得数据容易被修改，为了安全在数据前加const
// // 多个函数处理一个数据在不需要修改数据的函数形参加const
//  system("pause");
//  return 0;
// } 

// // 野指针
// // -规避野指针
// // 1.初始化指针
// // 2.小心指针越界
// // 3.指针指向空间释放即使置NULL
// // 4.指针使用之前检查有效性
// int* test()
// {
//     // a申请一个内存空间
//     // a是一个局部变量，出函数体就被销毁
//     int a=10;
//     return &a;
// }
// int main (void)
// {
//     // int arr[10]={0};
//     // // int* p;//局部变量不初始化，默认是随机值，称之为野指针
//     // // int* p=NULL; //也是初始化指针，或给指针赋值的
//     // int* p=arr;
//     // int i;
//     // for(i=0;i<12;i++)
//     // {
//     //     // 指针超出它控制范围，越界也会造成野指针的现象
//     //     *(p++)=i;
//     // }
//     // // p=NULL; //指针使用完后如果不在使用了，将指针置于NULL（空）防止野指针发生
//     // //if(p!=NULL) 判断指针是否在有效的范围
//     // //{指针有效性} 
//     // //指向一个释放的空间
//     int* p=test();//地址获取成功，但此时的a地址已经把内存空间还给了系统
//     *p=20;//所以这里的解引用也是野指针的一种
//     system("pause");
//     return 0;
// }

// // 指针类型
// int main(void)
// {
//     int a=0x11223344;
//     char c=0x22334455;
//      int* p=&a;
//      char* pa=&c;
//     // *p=0;
//     // 指针类型决定了指针进行解应用操作的时候，能够访问空间的大小
//     // int* p    *p能够访问4个字节
//     // char* p   *p能够访问1个字节
//     // double* p *p能够访问8个字节
//     printf("%p\n",p);
//     printf("%p\n",p+1);
//     printf("%p\n",pa);
//     printf("%p\n",pa+1);
//     // 指针类型决定：指针走一步走多远（指针的不长）
//     // int* p;   p+1-->4字节
//     // char* p;  p+1-->1字节
//     // double* p; p+1-->8字节
//     system("pause");
//     return 0;
// }

// // 指针是一个变量，存放内存单元的地址（编号）（存放在指针中的值都被当成地址处理）
// int main(void)
// {
//     int a=10;//在内存开放一块空间
//     int* p=&a;//这里取a地址‘&’，将地址存放在p变量中，p就是一个指针变量
//     return 0;
// }

// ------------------------------------------------------------符号

// 操作符从大到小排序优先级
// 操作符        描述                表达式             结合性         是否控制求值顺序
// ()            聚组                                  N/A               否
// ()          函数调用         rexp(rexp,...rexp)     L-R               否             
// []          下标引用            lexp[rexp]          L-R              否
// .          访问结构成员         lexp.name            L-R              否
// ->        访问结构指针成员      lexp->name           L-R              否
// ++          后缀自增           rexp++                L-R              否
// --          后缀自减           rexp--                L-R              否
// ！           逻辑反            !rexp                 R-L              否
// ~           按位取反           ~rexp                 R-L              否
// +          单目，正值          +rexp                 R-L              否
// -          单目，负值          -rexp                R-L              否
// ++          前缀自增          ++rexp                 R-L              否
// --          前缀自减          --rexp                 R-L              否
// *        解引用（间接访问）     *rexp                 R-L              否    
// &            取地址            &rexp                 R-L              否
// sizeof     取长度（字节）      sizeof (rexp)          R-L              否
// （类型）    类型转换           (类型)rexp              R-L              否
// *           乘法              lexp*rexp              L-R              否
// /           除法              lexp/rexp              L-R              否
// %         整数取余（取模）     lexp%rexp              L-R              否
// +           加法              lexp+rexp              L-R              否
// -           减法              lexp-rexp             L-R              否
// <<         左位移             lexp<<rexp             L-R              否
// >>         右位移             lexp>>rexp              L-R              否
// >           大于              lexp>rexp              L-R              否
// >=        大于等于            lexp>=rexp             L-R              否
// <           小于              lexp<rexp             L-R              否
// <=        小于等于            lexp<=rexp            L-R              否
// ==          等于              lexp==rexp             L-R              否
// !=         不等于             lexp!=rexp              L-R              否
// &          按位与             lexp&rexp              L-R              否
// ^         按位异或            lexp^rexp              L-R              否
// |          按位或             lexp|rexp             L-R              否
// &&         逻辑与             lexp&&rexp             L-R                 是
// ||         逻辑或             lexp||rexp              L-R                 是
// ?:       条件操作符         lexp?rexp:rexp           N/A                是
// =           赋值              lexp=rexp             R-L              否
// +=        以...加             lexp+=rexp             R-L              否
// -=        以...减             lexp-=rexp             R-L              否
// *=        以...乘             lexp*=rexp             R-L              否
// /=        以...除             lexp/=rexp             R-L              否
// %=        以...取模           lexp%=rexp            R-L              否
// <<=       以...左移           lexp<<=rexp            R-L              否
// >>=       以...右移           lexp>>=rexp             R-L              否
// &=        以...与             lexp&=rexp             R-L              否
// ^=        以...异或           lexp^=rexp             R-L              否
// |=        以...或             lexp|=rexp              R-L              否
// ,           逗号              rexp,rexp              L-R                是   

// 算术转换
// long double
// double
// unsigned long int 
// long int
// unsigned int 
// int 
// 如果摸个操作数的类型在上面这个列表中排名较低，那么首先要转换成另一个操作数的类型后执行运算。
// float f=3.14;
// int num=f;//先num转换float类型运算，结果截断整形类型，丢失精度

// // 隐形类型转换
// 表达式中的字符和短整型操作数在使用之前被转换为普通整形，这种转换称为整形提升
// 表达式中可能小于int长度的整形值，都必须转换为int或unsigned int，然后才能送入cpu去执行运算
// int main(void)
// {
//     char a=3;
//     // 00000000000000000000000000000011  -char整形提升 -> int 4字节 （32bti） 
//     // 00000011  -int转换char类型  截断  1字节（8bti）
//     char b=127;
//     // 00000000000000000000000001111111  -char整形提升 -> int 4字节 （32bti）
//     // 01111111  -int转换char类型  截断  1字节（8bti）
//     char c=a+b;
//     // a和b如何相加
//     // -截断char a -00000011  提升整形的时候，高位补充符号位  正数最高位0
//     // 00000000000000000000000000000011 -a
//     // -截断char b -01111111  提升整形的时候，高位补充符号位  正数最高位0
//     // 00000000000000000000000001111111 -b
//     // c=a+b
//     // 00000000000000000000000000000011
//     // 00000000000000000000000001111111
//     // 00000000000000000000000010000010 -c 
//     // 10000010 -int转换char类型  截断  1字节（8bti）
//     printf("%d\n",c);
//     // 打印%d  整形  char c 整形提升 
//     // -截断char c -10000010  提升整形的时候，高位补充符号位  最高位1 负值
//     // 11111111111111111111111110000010 -补码
//     // 11111111111111111111111110000001 -反码  反码+1得补码  ，反之补码-1得反码
//     // 10000000000000000000000001111110 -原码  符号位不变其它位按位取反
//     printf("%u\n",sizeof(a));//1
//     printf("%u\n",sizeof(+a));//4 (整形提升)
//     printf("%u\n",sizeof(!a));//1
// }

// // 创建结构体
// struct stu
// {
// // 结构体成员变量
//     char name[20];
//     int age;
//     char id[20];
// };//结构体花括号后面需要‘;’号
// int main(void)
// {
//     // 使用struct stu这个类型创建了一个学生对象s1，并初始化
//     struct stu s1={"Awake",20,"20221225"};
//     // '.'操作符用来访问结构体成员
//     struct stu* sp=&s1;//（类型）指针变量*sp &取地址s1
//     // (*sp)解引用操作符 ，取地址sp指针变量s1引用结构体，.访问结构体成员
//     printf("%s\n",(*sp).name);
//     // sp->  和 (*sp).  是等价的操作关系
//     printf("%s\n",sp->name);
//     // 结构体指针->成员名
//     // printf("%s\n",s1.name);
//     // printf("%d\n",s1.age);
//     // printf("%s\n",s1.id);
//     // // 结构体变量.成员名
//     system("pause");
//     return 0;
// }

// //小标引用操作符‘[]’
// int main(void)
// {
//     int arr[10];//创建数组
//     arr[4]=10;//实用下标引用操作符 
// } 

// // 逗号表达式‘,’
// int main(void)
// {
//     int a=get_val();
//     count_val(a);
//     while(a>0)
//     {
//         // 执行业务
//         a=get_val();
//         count_val(a);
//     }
//     // 重复执行代码
//     while(a=get_val(),count_val(a),a>0)
//     {
//         // 执行业务
//     }
//     // int a=1;
//     // int b=2;
//     // int c=(a>b,a=b+10,b=a+1);
//     // printf("%d\n",c);
//     system("pause");
//     return 0;
// }

// //条件操作符'exp1?exp2:exp3' 
// int main(void)
// {
//     int a=0;
//     int b=3;
//     int c=0;
//     // if(a>b)
//     //   c=3;
//     // else
//     //   c=-3;
//     c=(a>b)?3:-3;
//     // (a>b)?  a大于b吗
//     // 3：-3  大于3是最终结果，否则-3是最终结果
//     printf("%d\n",c);
//     system("pause");
//     return 0;
// }

// // 逻辑与‘&&’
// int main(void)
// {
//     int i=0;
//     int a,b,c,d;
//     a=1;
//     b=2;
//     c=3;
//     d=4;
//     // i=a++ && ++b && d++;
//     //逻辑与知识点  在&&左边只要有假右边的都不进行运算
//     i=a++ || ++b || d++;
//     //逻辑或知识点  在||左边有真右边也不进行运算
//     printf("a=%d\nb=%d\nc=%d\nd=%d\n",a,b,c,d);//所以答案是1,2,3,4
//     system("pause");
//     return 0;
// }

// // 按位取反‘~’
// int main(void)
// {
//     int a=11;
//     a=a|(1 << 2);
//     printf("a=%d\n", a);
//     // a=15
//     a=a&(~(1<<2));
//     //按位取反~
//     // 1 -00000000000000000000000000001111   15
//     // 2 -11111111111111111111111111111011   ~(1<<2) 按位取反
//     // 00000000000000000000000000000100   1<<2  4
//     // 00000000000000000000000000000001   1
//     // 3 -00000000000000000000000000001011  1 & 2   按位与&11
//     printf("a=%d\n", a);
//     // a=11
//     system("pause");
//     return 0;
// }

// // sizeof描述
// void test2 (char ch[])//传参数组首地址 给指针ch所以是4、8
// {
//     printf("%d\n",sizeof(ch));
// }
// void test1 (int arr[])//传参数组首地址 给指针arr所以是4、8
// {
//     printf("%d\n",sizeof(arr));
// }
// int main(void)
// {
//     // short a=0;
//     // int b=10;
//     // char c=' ';
//     // printf("%d\n",sizeof(c=b+5));//sizeof(_);内的表达式不参与运算，sizeof计算的是最后赋值的变量类型大小
//     // printf("%d\n",a);
//     int arr[10]={0};
//     char ch[10]={0};
//     printf("%d\n",sizeof(arr));//40
//     printf("%d\n",sizeof(ch));//10
//     test1(arr);
//     test2(ch);
//     system("pause");
//     return 0;
// }

// int main(void)
// {
//     // // sizeof 计算的变量所占内存空间的大小，单位是字节
//     // int a=10;
//     // char c='r';
//     // int* p=&a;
//     // int arr[10]={0};
//     // char arg[10]={'c'};
//     // printf("%d\n",sizeof a);            //4
//     // printf("%d\n",sizeof(c));           //1
//     // printf("%d\n",sizeof(p));           //8 -32位系统4字节  -64位系统8字节
//     // printf("%d\n",sizeof(arr));         //40
//     // printf("%d\n",sizeof(arg));         //10
//     // printf("%d\n",sizeof(int [10]));    //40
//     // printf("%d\n",sizeof(char [10]));   //10
//     // printf("%d\n",sizeof(int));         //4  -类型必须加（）
//     // printf("%d\n",sizeof(char));        //1

//     // int a=10;
//     // int* p=&a;//&-取地址操作符  int* - 指针 p -指针变量
//     // *p=20;//解引用操作符 将20放在a的地址中
//     // printf("%d\n",a);
//     system("pause");
//     return 0;
// }

// // 计算一个整数的二进制中1的个数
// int main(void)
// {
//     int num =0;
//     int count=0;
//     scanf("%d",&num);
//     for(int i=0; i<32; i++)
//     {
//         // num >> i;   错误语句
//         if(1 == ((num >> i) & 1))
//           count++;
//     }
//     printf("%d",count);
//     system("pause");
//     return 0;
// }

// int main(void)
// {

//     // 按位异或（二进制）‘^’
//     int a =3;
//     int b =5;
//     int c =a^b;
//     // 00000000000000000000000000000011   3
//     // 00000000000000000000000000000101   5
//     // 00000000000000000000000000000110   3^5   两个二进制相同为0，相异为1
//     printf("%d",c);

//     // // 按位或（二进制）‘|’
//     // int a =3;
//     // int b =5;
//     // int c =a|b;
//     // // 00000000000000000000000000000011   3
//     // // 00000000000000000000000000000101   5
//     // // 00000000000000000000000000000111   3|5 (两个二进制有一位是1结果为1，两位都是0结果才为0) 
//     // printf("%d",c);

//     // // 按二进制位与'&' 
//     // int a =3;
//     // int b =5;
//     // int c =a&b;
//     // // 00000000000000000000000000000011   3
//     // // 00000000000000000000000000000101   5
//     // // 00000000000000000000000000000001   3&5(两个二进制位有一个为0结果为0，两个都为1结果才为1)
//     // // 如果是负数要进行换算成补码在和另一个二进制进行（按位与）运算
//     // printf("%d",c);

// //     //右移运算符'>>'  运算符不能单独使用需要赋值（除判断语句）
// //     // 1.算术右移  二进制位（补码）右移，右边丢弃，左边补符号位；（一般都是算术）
// //     // 2.逻辑右移  二进制位（补码）右移，右边丢弃，左边补0；
// //     // 10000000000000000000000000000001  原码  -1
// //     // 11111111111111111111111111111110  反码  符号位不变其它位按位去反0>1 , 1>0
// //     // 11111111111111111111111111111111  补码  反码加1得到补码
// //     // 11111111111111111111111111111111  -1 >> 1 = -1
    // int a = -1;
    // int b = a >> 4;
// //     // 左移运算符'<<'
// //     // 左边丢弃，右边补0；
// //     // 00000000000000000000000000000101   5
// //     // 00000000000000000000000000001010   5 << 1 = 10
// //     int a=5;
// //     int b = a << 1; 
//     printf("%d",b);
//     system("pause");
//     return 0;
// }

// // 逻辑非‘！’
// int main(void)
// {
//     int i=1;
//     int j=0;
//     // 非1  即0  // 非0  即1
//     printf("%d\n",!i);
//     printf("%d\n",!j);
//     system("pause");
//     return 0;
// }

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