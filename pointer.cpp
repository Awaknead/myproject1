#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<windows.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
int main()
{
    //数组名是首元素地址
    //1.sizeof(数组名) - 数组名表示整个数组
    //2.&数组名 - 数组名表示整个数组
    //3.除此之外所有的数组名都表示受首元素的地址
    int a[]={1,2,3,4,5};//5*4=20  
    printf("%d\n",sizeof(a));   //20-sizeof(数组名)-计算数组总大小
    printf("%d\n",sizeof(a+0)); //4/8-数组名表示首元素-a+0还是首元素地址，地址大小4/8
    printf("%d\n",sizeof(*a));  //4-数组名表示首元素地址-*a就是首元素
    printf("%d\n",sizeof(a+1)); //4/8-数组名表示首元素地址-a+1就是第二个元素地址-地址大小4/8
    printf("%d\n",sizeof(a[1]));//4-表示第二个元素大小
    printf("%d\n",sizeof(&a));  //4/8-&a取出的是数组的地址，那也是地址，地址的大小4/8
    printf("%d\n",sizeof(*&a)); //20-&a数组的地址，数组的地址解引用访问数组，sizeof计算数组的大小
    printf("%d\n",sizeof(&a+1));//4/8-&a数组的地址，&a+1跳过了整个数组的地址，后面的那个地址的大小4/8
    printf("%d\n",sizeof(&a[0]));//4/8-第一个元素的地址
    printf("%d\n",sizeof(&a[0]+1));//4/8-第二个元素的的地址
    putchar('\n');
    char arr[]={'a', 'b', 'c', 'd', 'e', 'f'};//机器储存 "a,b,c,d,e,f"
    printf("%d\n",sizeof(arr));    //6 计算数组的大小
    printf("%d\n",sizeof(arr+0));  //4、8 首元素地址
    printf("%d\n",sizeof(*arr));   //1 首元素地址解引用 首元素
    printf("%d\n",sizeof(arr[1])); //1 第二个元素
    printf("%d\n",sizeof(&arr));   //4.8 数组的地址
    printf("%d\n",sizeof(&arr+1));//4.8  数组的地址+1 跳过一个数组后的地址
    printf("%d\n",sizeof(&arr[0]+1));//4.8 数组的第二个元素地址 
    putchar('\n');
    // strlen  计算字符串长度 -'\0'
    printf("%d\n",strlen(arr));       //随机值
    printf("%d\n",strlen(arr+0));     //随机值
    // printf("%d\n",strlen(*arr));   //error
    // printf("%d\n",strlen(arr[1])); //error
    // printf("%d\n",strlen(&arr));   //随机值
    // printf("%d\n",strlen(&arr+1)); //随机值-6
    printf("%d\n",strlen(&arr[0]+1)); //随机值-1

    putchar('\n');
    char arr1[]={"abcdef"};   //机器储存的时"abcdef\0"
    printf("%d\n",sizeof(arr1));    // 7 -数组的大小
    printf("%d\n",sizeof(arr1+0));  // 4.8 -首元素的地址+0  还是地址
    printf("%d\n",sizeof(*arr1));   // 1 -首元素地址解引用  首元素
    printf("%d\n",sizeof(arr1[1])); // 1 -数组第二个元素
    printf("%d\n",sizeof(&arr1));   // 4.8 -取数组的地址
    printf("%d\n",sizeof(&arr1+1)); // 4.8 -取数组的地址后+1 还是地址
    printf("%d\n",sizeof(&arr1[0]+1)); // 4.8 -取数组第二元素地址 还是地址

    putchar('\n');
    printf("%d\n",strlen(arr1));    //6 -数组大小
    printf("%d\n",strlen(arr1+0));  //6 -首元素地址 往后寻找'\0'
    // printf("%d\n",strlen(*arr1));  //error -非法访问内存
    // printf("%d\n",strlen(arr1[1])); //error -非法访问内存
    // printf("%d\n",strlen(&arr1));   //&arr -数组的地址-使用数组指针 char(*p)[7] =&arr1;
    // printf("%d\n",strlen(&arr1+1));  //&arr -数组的地址+1 -跳过一个数组-使用数组指针 char(*p)[7] =&arr1;
    printf("%d\n",strlen(&arr1[0]+1));  //5 -第二个元素的地址往后寻找'\0'

    putchar('\n');
    const char* p="abcdef";  //机器储存 "abcdef\0" 常量字符串  指针存放的时a字符的地址不是存放abcdef
    printf("%d\n",sizeof(p));//4/8  计算指针变量p地址的大小
    printf("%d\n",sizeof(p+1));//4/8 p+1得到的时字符b的地址
    printf("%d\n",sizeof(*p));//1  解引用p -得到字符串第一个字符
    printf("%d\n",sizeof(p[0]));//1 得到的时字符串第一个字符p[0] == *(p+0)
    printf("%d\n",sizeof(&p));//4/8 地址
    printf("%d\n",sizeof(&p+1));//4/8 地址
    printf("%d\n",sizeof(&p[0]+1));//4/8  地址
    putchar('\n');

    printf("%d\n",strlen(p)); //6 
    printf("%d\n",strlen(p+1)); //5
    // printf("%d\n",strlen(*p));//err
    // printf("%d\n",strlen(p[0]));//err
    // printf("%d\n",strlen(&p));// 随机值 取地址p  和字符串地址没有直接联系
    // printf("%d\n",strlen(&p+1));//随机值 取地址p+1 时跳过p的地址后面一个地址
    printf("%d\n",strlen(&p[0]+1));//5 取地址p[0]->指向字符串第一个字符+1第二个字符 计算
    putchar('\n');
    
    int a2[3][4]={0}; //二维数组  由三个一维数组a[0],a[1],a[2]每个一维数组都有4个元素组成
    printf("%d\n",sizeof(a2));// 48 -3个一维数组*4每个一维数组4个元素*4一个元素4个字节 3*4*4
    // printf("%d\n",sizeof(a[0][0]));// 4 一维数组a[0] 第[0]个元素
    printf("%d\n",sizeof(a2[0]));  //16  sizeof(数组名-a[0]) 计算整个数组4*4
    printf("%d\n",sizeof(a2[0]+1)); //4.8 a[0]此时是首元素地址+1 a[0]一维数组的第二个元素的地址
    // printf("%d\n",sizeof(*(a[0]+1)));//4 第一行第二个元素地址 解引用
    printf("%d\n",sizeof(a2+1));//4.8 a此时是二维数组的首元素地址a[0]  +1就是a[1]第二行地址   
    printf("%d\n",sizeof(*(a2+1)));//16 二维数组a[1]  解引用 -整个数组
    printf("%d\n",sizeof(&a2[0]+1));//4.8 取a[0]地址是第一行整个数组 +1 -第二行a[1]地址
    printf("%d\n",sizeof(*(&a2[0]+1)));//16 计算第二行的数组大小
    printf("%d\n",sizeof(*a2));//16 a是二维数组名 a解引用-二维数组首元素a[0]
    printf("%d\n",sizeof(a2[3]));//16 sizeof(表达式不参与真实运算)a[3]不会真的访问数组  a[3][4]的类型是int和a[0][4]l类型一样
    putchar('\n');
    int a1[5]={1,2,3,4,5};
    int* ptr=(int*)(&a1+1);//&a1取的是整个a1数组  &a1+1是跳过整个数组后一位 int 是数组指针类型强制转换int*
    printf("%d.%d\n",*(a1+1),*(ptr-1));//2,5
    putchar('\n');

    char* c[]={"ENTER","NEW","POINT","FIRST"};
    char** cp[]={c+3,c+2,c+1,c};//c没有取地址&，没有单独放在sizeof中，所以是数组首元素地址
    char*** cpp=cp;//整个数组地址存放在cpp指针中
    /* 
       三级指针     二级指针     一级指针 
       cpp            cp          c
       char***-->   c + 3       ENTER
                    c + 2        NEW  
                    c + 1       POINT
                      c         FIRST
                      |   
                         0 1 2 3 4
        cp[0]   c+3  ==  F I R S T 
        cp[1]   c+2  ==  P O I N T        .
        cp[2]   c+1  ==  N E W            .
        cp[3]    c   ==  E N T E R
    */
    printf("%s\n",**++cpp); //POINT
    //++cpp优先(cpp[1])>*解引用找到一维数组(c)地址>*解引用地址>POINT 
    printf("%s\n",*--*++cpp + 3);//ER
    //++cpp(cpp[2])>解引用找到一维数组(c)地址>c地址-->*解引用地址"ENTER">+3将字符串首地址向后偏移3位>ER
    printf("%s\n",*cpp[-2]+3);//ST
    //cpp[-2]=>*(cpp+(-2))>现在cpp地址(cpp[2])=>cpp[0]>*解引用找到一维数组(c)地址>*解引用地址"FIRST">+3将字符串向后偏移3位>ST
    printf("%s\n",cpp[-1][-1]+1);//EW
    //cpp[-1]=>*(cpp+(-1))>现在cpp地址(cpp[2])=>cpp[1]>*解引用找到一维数组(c)地址c[2]>[-1]=>*(*(cpp[1])-1)c地址-1现在地址c[1]>*解引用c[1]"NEW">+1将字符串向后偏移1位>EW
    system("pause");
    return 0;
}
// ----------------------------------------------------------指针(qsort快速排序)
// ------------------------------------------------------------结构体
/*  // struct (结构体)
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
} */
/* // 结构体声明
   struct stu 
   {
    // 结构体
       char name[20];
       int age;
   };
/* 
//    int cmp_stu(const void*e1,const void*e2)
//    {
//     //   -> 访问结构体指针成员
//        return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
//    }
   int cmp_stu(const void*e1,const void*e2)
   {
    // 比较字符串
    // 不能直接使用><=来比较，应该用strcmp（字符串比较函数）函数
    return strcmp(((struct stu*)e1)->name , ((struct stu*)e2)->name);
   }
   void test1( )
   {
    // 结构体定义
      struct stu s[3]={{"zhangsan",39},{"lisi",22},{"wangwu",40}};
    //   结构体计算元素个数
      int sz=sizeof(s)/sizeof(s[0]);
    //   结构体qsort快速排序
      qsort(s,sz,sizeof(s[0]),cmp_stu);
    //   第一个参数：待排序数组的首元素地址
    // 第二个参数：待排序数组的元素个数
    // 第三个参数：待排序数组的每个元素的大小-单位字节
    // 第四个参数：是函数指针，比较两个元素的所用函数的地址-这个函数使用者自己实现
                //   函数指针的两个参数是：带比较的两个元素的地址
      for(int x=0;x<sz;x++)
      {
        printf("s[%d]  name=%s  age=%d.\n",x,s[x].name,s[x].age);
      }
   } 

// swap交换元素
void swap(char* e1,char*e2,int width)
{
    for(int x=0;x<width;x++)
    {
        int temp=*e1;
        *e1=*e2;
        *e2=temp;
        *e1++;
        *e2++;
    }
}
//    自创快速排序函数(qsort)
void test_qsort(void* base,int sz,int width,int (*cmp)(void* e1,void* e2))
{
    // 趟数
    for(int i=0;i<sz-1;i++)
    {
        // 一趟比较的对数
        for(int j=0;j<sz-1-i;j++)
        {
            //两个比较的元素
            if(cmp((char*)base+j*width,(char*)base+(j+1)*width) > 0 )
            {
                // 交换
                swap((char*)base+j*width,(char*)base+(j+1)*width,width);
            }
            
        }
    }
}
int cmp_int (void* e1,void* e2)
{
    return *((int*)e1) - *((int*)e2);
}
int cmp_stu_age(void* e1,void* e2)
{
    return (((struct stu*)e1)->age) -(((struct stu*)e2)->age);
}
void test4()
{
    //整型 
    int arr[]={9,8,7,1,2,3,4,5,6};
    int sz=sizeof(arr)/sizeof(arr[0]);
    test_qsort(arr,sz,sizeof(arr[0]),cmp_int);
    for(int x=0;x<sz;x++)
      {
         printf("arr[%d]=%d\n",x,arr[x]);
      }
}
void test5()
{
    //结构体
    struct stu s[3]={{"zhangsan",39},{"lisi",22},{"wangwu",40}};
    int sz=sizeof(s)/sizeof(s[0]); 
    test_qsort(s,sz,sizeof(s[0]),cmp_stu_age);
    for(int x=0;x<sz;x++)
      {
        printf("s[%d]  name=%s  age=%d.\n",x,s[x].name,s[x].age);
      }
}
   int main(void)
   {
      test4();
      putchar('\n');
      test5();
      system("pause");
      return 0;
   } */
/* char** fizzBuzz(int n,int *returnsize)
{
    char** answer=(char**)malloc(sizeof(char*)*n);
    //malloc分配内存空间大小char**里有n个char*
    char* arr=(char*)malloc(sizeof(char)*n*9);
    //malloc分配内存空间大小char*里有n个char类型元素个数是9个
    *returnsize=n;
    for(int j=0;j<n;j++)
    {
        answer[j]=&arr[9*j];
    }
    for(int j=0;j<=n;j++)
    {
        if(j%3 ==0 && j%5 ==0)
        {
            strcpy(answer[j-1],"FizzBuzz");
        }
        else if(j%3 ==0)
        {
            strcpy(answer[j-1],"Fizz");
        }
        else if(j%5 ==0)
        {
            strcpy(answer[j-1],"Buzz");
        }
        else
        {
            sprintf(answer[j-1],"%d",j);
        }
        printf("answer[%d]=%s",j,answer[j-1]);
    }
    return answer;
}
int main(void)
{
    char** args;//接收
    int a=3;      //输出数字
    int* size;  
    args =fizzBuzz(a,size);
    return 0;
} */

/* // 指向函数指针数组的指针
int main()
{
    int arr[10]={0};
    int(*p)[10]=&arr; //数组指针

    int (*pfarr[4])(int ,int );//函数指针数组
    int (*(*ppfarr)[4])(int ,int )=&pfarr;
    // ppfarr是一个数组指针，指针指向的数组有4 个元素
    // 指向的数组的每个元素的类型是一个函数指针int(*)(int ,int )

} */

// 回调函数  - 是一个通过函数指针调用的函数
// 查看calc_pointer.cpp

// 函数指针数组 - 计算器
// 查看calc_pointer.cpp

/* // 练习
char* my_strcpy (char* dest,const char* src);
int main()
{
    // 1.函数指针
    char*(*pf)(char*,const char*)=my_strcpy;
    // 2.函数指针数组
    char*(*pfArr[4])(char*,const char*)={my_strcpy,my_strcpy,my_strcpy,my_strcpy};
} */

/* int Add(int x,int y)
{return x+y;}
int Sud(int x,int y)
{return x-y;}
int Mul(int x,int y)
{return x*y;}
int Div(int x,int y)
{return x/y;}
//函数指针数组 -将相同类型的函数地址放在一个数组里
int main()
{
    //指针(一级指针)
    int*aa;
    //指针数组
    int* a[5];
    //数组指针
    int(*b)[5];
    //函数指针
    // 需要一个数组，这个数组可以存放n个函数的地址 - 函数指针数组
    // int(*c)(int,int)=add;//sud,mul,div
    int(*arr[4])(int,int)={Add,Sud,Mul,Div};//  arr[4]->函数指针数组  ->类型 int(*)(int ,int )
    for(int i=0;i<4;i++)
    {
        printf("%d\n",arr[i](3,4));// arr[i](3,4) 函数调用
    }
    system("pause");
    return 0;
}  */

/*
int main()
{
    int a=10;
    int b=20;
    int(*pa)(int,int)=testadd;
    // 函数指针-都可以使用
    printf("%d\n",pa(a,b));     //30
    printf("%d\n",testadd(a,b));//30
    printf("%d\n",(*pa)(a,b));  //30
    // //error  -printf("%d\n",*pa(a,b));
    // printf("%d\n",(**pa)(a,b));
    // printf("%d\n",(***pa)(a,b));
    system("pause");
    return 0;
}  */

/*// typedef void(*pfun_t)(int);   //这是定义void(*)(int)    -重新命名为 pfun_t(函数的定义写法)
// // typedef unsigned int uint; //这是定义unsigned int    -重命名为 uint
// // typedef short int sint;
// pfun_t singal(int,pfun_t);  //函数声明
 // 函数指针 -是指向函数的指针 -存放函数地址的一个指针
// 函数指针 - 
// 举例      void (*       signal(int,   void(*)(int)   )      )(int)   //不容易被读者理解
// 分解 1.   void (*                                           )(int)
// 分解 2.                 signal(int,   void (*)(int)  )
// 分解 3.                               void (*)(int)
分解 1  和  分解 3  -  都是void(*)(int)  ->  函数指针类型  -参数int -返回值void
// 简化    
// pfun_t singal(int,pfun_t);  //函数声明
// 笔试考--
// void (*signal(int,void(*)(int)))(int)
// 解释函数含义
// 1.signal是一个函数声明
// 2.signal函数的参数有两个，第一个是int类型，第二个是函数指针，该函数指针指向的函数的参数是int，返回类型是void
// 3.signal函数的返回类型也是一个函数指针：该函数指针指向的函数的参数是int，返回类型是void
// int testadd(int x,int y)
// {
//     int z=0;
//     z=x+y;
//     return z;
// }
// void testchar(const char*str)
// {
//     printf("%s\n",str);
// }
int main()
{
    // int a=10;
    // int b=20;
    // // int arr[10]={0};//数组
    // // int (*pa)[10]=&arr;//指针数组
    // // printf("%d \n",testadd(a,b));
    // //&函数名 和 函数名 都是函数的地址
    // // printf("%p\n",testadd);
    // // printf("%p\n",&testadd);
    // 整型(int)
    // int (*pg)(int,int)=testadd;//函数指针  (*pg)-指针  (int,int)-参数类型  int-返回类型
    // printf("%d\n",(*pg)(a,b)); //函数指针调用  (*pg)(int[变量名或常量],int[变量名或常量])
    // 字符(char)
    // void (*pa)(const char*)=testchar;//函数指针  (*pa)-指针   (const char*)-参数类型  void-返回类型
    // (*pa)("hello world!");//函数指针调用  (*pa)(const char*[常量字符串])
    system("pause");
    return 0;
} */

// // 指针如何传参
// void test(char** aa)
// {}
// void test1(char** aa)
// {}
// void test2(char** aa)
// {}
// int main()
// {
//     char c='w';
//     char* p=&c;
//     char** qq=&p;
//     char* arr[10];
//     test(&p);  //实参(指针地址)  - 形参(可用二级指针)
//     test1(qq); //实参(二级指针本身) -形参(可用二级指针)
//     test2(arr);//实参(指针数组名(一级指针的地址)) -形参(可用二级指针)
// }

/* // 数组和指针(二维)传参
void test (int arr[3][5])//1.和数组完全一样的写法
{}
void test1(int arr[][5])//2.二维数组只能行可以省略,但必须知道一行有多少个元素
{}
// void test2(int arr[3][])// error:二维数组只显示行，不显示列（非法代码）
// {}
// void test3(int arr[][])// error:
// {}
void test4(int(*arr)[])
{}
int main()
{
    int arr[3][5]={0};
    test(arr);//二维数组传参
    test1(arr);
    // test2(arr);
    // test3(arr);
    test4(arr);
    system("pause");
    return 0;
} */

/* // 数组和指针(一维)传参
// 数组在传参的时候可以传数组也可以是指针
// 传数组的时候要注意数组大小可以省略
// 传指针的时候要注意要使用合理的指针类型
// int arr[10]; = 使用指针 int *arr  整型数组 - 首元素整型的地址 - 放在整型指针里
// int* arr1[10]; = 使用指针 int* *arr  指针数组 -首元素指针的地址 - 可以放在二级指针里
// void test (int arr[])
// {printf("%p",arr);}
// void test(int arr[10])
// {printf("%p",arr);}
void test(int* arr)
{printf("%p",arr);}
// void test1(int* arr1[20])
// {printf("%p",arr1);}
void test1(int**arr1)
{printf("%p",arr1);}
int main(void)
{
    int arr[10]={0};
    int* arr1[20]={0};
    printf("%p",arr);
    test(arr);
    printf("\n");
    printf("%p",arr1);
    test1(arr1);
    system("pause");
    return 0;
}
 */

// int arr[5];//arr是一个有5个元素的整型数组 
// int* parr1[10];//parr1是一个数组 ，数组有10个元素，每个元素类型都是int*，parr1是指针数组
// int(*parr2)[10];//parr2是一个指针，该指针指向一个数组，数组有10个元素，每个元素类型都是int,parr2是数组指针
// int(*parr3[10])[5];//parr3是一个数组，该数组有10个元素，每个元素是一个数组指针，该数组指针指向的数组有5个元素，每个元素是int

/* // 数组指针 -是指向数组的指针
void print(int (*p)[5],int x,int y)
// 函数行参数组指针(类型 指针变量名(数组指针首元素地址) 元素个数,类型 边界，类型 边界)
// 二维数组指针在传参时
// arr[3][5]
// (*p)[5]=&arr;  //指向的首元素地址是第一个数组
// (*p)将arr[3] 分为3个一维数组每个数组里有5个int元素，所以首元素地址是第一个数组的整个地址
// 即arr[0][0~5]首元素
//   arr[1][0~5]第二个元素
{
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            // printf("%d ",*(*(p+i)+j));
            // printf("%d ",(*(p+i))[j]);
            // printf("%d ",*(p[i]+j));
            printf("%d ",p[i][j]); 
            //*(p+i) == p[i] == arr[i]
            //*(*(p+i)+j)     == *(p[i]+j)    == p[i][j]  
            // *(*(arr+i)+j)  == *(arr[i]+j)  == arr[i][j]
        }
        printf("\n");
    }
}
int main()
{
    // // // // // int a=10;
    // // // // // int* p=&a;//这是一个整型指针
    // // // // char a='a';
    // // // // char* p=&a;//这是一个字符指针
    // // // int a[10]={0};
    // // // int* p[10];//这是一个存放指针的数组  p[10]-数组  每个元素都是int*类型
    // // // int(*p)[10]=&a; //这是一个数组指针  {(*p)-指针  [10]有10个元素}-是数组-的指针
    // // // // （*p）-声明变量时这里的'*'不是解引用
    // // char* arr[5];//这是一个存放指针的数组
    // // char*(*pa)[5]=&arr;//这是一个存放指针数组的数组指针
    // // int a[10]={1,2,3,4,5,6,7,8,9,10};
    // // int(*p)[10]=&a;
    // // for(int i=0;i<10;i++)
    // // {
    // //     printf("%d ",(*p)[i]);
    // // }
    // int aee[10]={1,2,3,4,5,6,7,8,9,10};
    // int* p=aee;
    // for(int i=0;i<10;i++)
    // {
    //     // printf("%d ",*(p+i));
    //     // printf("%d ",*(aee+i));
    //     // printf("%d ",aee[i]);
    //     // printf("%d ",p[i]);//*(aee+i) == aee[i] == *(p+i) == p[i] 
    // }
    int arr[3][5]={{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};
    print(arr,3,5);//函数 数组指针实参 (数组名，边界，边界)
    system("pause");
    return 0;
} */

// // 笔试题
// int main()
// {
//     char arr1[]="abcdef";
//     char arr2[]="abcdef";
//     const char* p1="abcdef";
//     const char* p2="abcdef";
//     // if(p1 == p2) //"abcdef"都是常量字符串所以内存只分配了一个内存空间地址
//     if(arr1 == arr2) //arr1 和 arr2是两个字符串数组所以分配了两个内存空间地址
//     {
//         printf("hhehe\n");
//     }
//     else
//     {
//         printf("haha\n");
//     }
//     system("pause");
//     return 0;
// }

//字符指针
// ""在双引号内的是常量字符串无法修改
// 1.使用字符数组变量 -配合指针使用   -char* p=arr; // 字符变量char arr[]="hello";
// 2.使用常量字符串"" -配合指针使用   -char* p="hello";
// int main()
// {
//     char* p= "hello";//"hello"是一个常量字符串  因该使用const关键字
//     const char* p= "hello world";//这是正确的写法
//     // *p = 'g';//对象是const常量字符串无法修改
//     printf("%c\n",*p);//指向的是"hello"的字符串 - 首字符地址"h"的地址
//     printf("%s\n",p);//指向的是"hello"的字符串地址
//     // char arr[]="agbdg";//字符串数组
//     // char* p=arr;//字符串数组指针变量
//     // // *p = "hello world";//对象是const常量字符串无法修改
//     // // *p - 指向arr首元素地址 - 首元素地址内容就是字符串本身“agbdg”
//     // printf("%s\n",p);
//     // printf("%s\n",arr);
//     system("pause");
//     return 0;
// }

// // 指针数组 - 数组 -存放指针的数组
// // 整型数组 - 存放整型
// // 字符数组 - 存放字符
// // 指针数组 - 存放指针
// int main()
// {
//     // 指针数组的用法
//     int arr1[]={1,2,3,4,5};  //-
//     int arr2[]={2,3,4,5,6};  //-   //数组
//     int arr3[]={3,4,5,6,7};  //-
//     int* parr[]={arr1,arr2,arr3};//指针数组
//     int sz1=sizeof(parr)/sizeof(parr[0]);
//     int sz2=sizeof(arr1)/sizeof(arr1[0]);
//     // for嵌套
//     // 外for提取指针数组parr 包含的各数组首地址
//     for(int i=0;i<sz1;i++)
//     {
//         // 内for打印arr1,2,3数组首地址内的元素j下标内的值
//         for(int j=0;j<sz2;j++)
//         {
//             // parr[i] - 指针数组中的各个数组首元素地址
//             // +j - 各个数组首元素地址下标增加
//             // * - 解引用
//             // *(parr[i]+j) - 解引用指针数组各个数组首元素地址下标j位置
//             printf("%d ",*(parr[i]+j));
//         }
//         printf("\n");
//     }
//     // int a=10;
//     // int b=29;
//     // int c=40;
//     // // int arr[10]={1,2,3,4,...,9};//是一个整型数组
//     // int* arr1[3]={&a,&b,&c};//是一个存放整型指针的数组
//     // int sz=sizeof(arr1)/sizeof(arr1[0]);
//     // //访问指针数组中的值
//     // for(int i=0;i<sz;i++)
//     // {
//     //     // *(arr[i])  - 解引用arr[i] - arr[0]=&a  
//     //     printf("%d ",*(arr1[i]));
//     // }    
//     // char aa='a';
//     // char bb='b';
//     // char cc='c';   
//     // char* pp[3]={&aa,&bb,&cc};
//     // int sz1=sizeof(pp)/sizeof(pp[0]);
//     // for(int i=0;i<sz;i++)
//     // {
//     //     // *(arr[i])  - 解引用arr[i] - arr[0]=&a  
//     //     printf("%c ",*(pp[i]));
//     // }       
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
