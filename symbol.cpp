// 网络安全需要学习内容
// 1.计算机语言
//    1.1 c/c++    就可以知道如何应对计算机环境中较低级别操作的攻击
//    1.2 Python   可以帮助识别漏洞并发现如何修复他们
//    1.3 Javascript 可以了解到网站和其他应用程序如何工作的概念，以及用来抵御恶意用户的最佳设计
//    1.4 PHP      知道如何抵御网页入侵者
//    1.5 SQL      SQL注入攻击涉及利用SQL漏洞窃取或修改数据库中保存的数据
// 2.局域网组网技术
// 3.网络管理的基本原理和操作方法
// 4.网络系统的性能测试和优化技术
// 5.网站渗透
// 6.服务漏洞扫描
// 7.程序漏洞分析检测
// 8.计算机应用
// 9.漏洞利用
// 10.漏洞修复
// 11.代码审计
// 12.安全脚本编写
// 13.SRC挖洞
// 14.入侵和攻击分析追踪
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<windows.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
// --------------------------------------------------------回调函数
/* int add(int x,int y)
{
    return x + y;
}
void print(int (*pf)(int ,int ))
{
    int x,y;
    printf("enter two value:\n");
    scanf("%d%d",&x,&y);
    printf("%d\n",pf(x,y));//调用add函数将x,y作为实参
}
int main(void)
{
    print(add);//函数调用函数将add函数作为print函数的实参传递
    system("pause");
    return 0; 
} */

// ------------------------------------------------------------结构体
/* // struct (结构体)
 strct 结构体名称{
    char a;
    int b;     //结构体a,b,c  皆为结构体成员变量(结构体内容)
    double c;
} 
struct stu
{
    char name[20];
    int age;
};
// void qsort(void*base,
//            size_t num,
//            size_t width,
//            int (* cmp)(const void *e1,const void *e2)
//            );
int cmp_int(const void *a,const void *b)
{
    //两数比较
      return *(int*)a-*(int*)b;
}
int cmp_float(const void *e1, const void *e2)
{
    if(*(float*)e1  == *(float*)e2)
       return 0;
    else if(*(float*)e1 > *(float*)e2)
            return 1;
    else
        return -1;
}
void test1()
{
    int arr[]={9,8,7,1,2,3,4,5,6};
    int sz=sizeof(arr)/sizeof(arr[0]);
    qsort(arr,sz,sizeof(arr[0]),cmp_int);
    for(int i=0;i<sz;i++)
    {
        printf("%d ",arr[i]);
    }
}

void test2()
{
    float f[]={1.2,3.2,4.2,2.2,9.3,5.6,8.2,2.1,3.0};
    int sz=sizeof(f)/sizeof(f[0]);
    qsort(f,sz,sizeof(f[0]),cmp_float);
    for(int i=0;i<sz;i++)
    {
        printf("%.2f ",f[i]);
    }
}
//--------------------------------------------------------指向函数指针数组的指针
int add(int x,int y)
{
    return x+y;
}

int main(void)
{

    struct stu s[3]={{"zhangyan",18},{"jingyang",19},{"xigua",39}};
    test1();
    putchar('\n');
    test2();
    int arr[6]={0};
    int(*pf)[6]=&arr;
    int (*pd[4])(int ,int )=add;//pd 是一个函数指针的数组 
    int (*(*ppd)[4])(int ,int )=&pd;
    //ppd 是一个数组指针  指针指向的数组有4个元素
    // ppd 是一个指向函数指针 int(* (*ppd)[4])(int ,int )
    // 数组                        (*ppd)[4]
    // 的指针                      (*ppd)

    
    
    // int i=10;
    // void* c=&i;
    //void* 类型指针 可以接受任意类型的地址
    //void* 类型指针 不能进行解引用操作
    //void* 类型指针 不能进行加减运算
    // *c=0;
    system("pause");
    return 0;
} */

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
