#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<windows.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
// 函数指针数组 - 模拟计算器
//分隔符函数
#define SEP 40 //分隔符长度
#define LIST "calc" //输入需要的标题
#define ONE "1.Add   2.Sud"            //输入接口选项
#define TWO "3.Mul   4.Div"
#define THREE "5.Xor   0.eixt"            

//计算函数
int Add(int x,int y)
{   return x + y; }//加
int Sub(int x,int y)
{   return x - y; }//减
int Mul(int x,int y)
{   return x * y; }//乘
int Div(int x,int y)
{   return x / y; }//除
int Xor(int x,int y)
{   return x ^ y; }//异或
void separator (void)
{
    int i;
    for(i=0;i<SEP;i++)
       putchar('*');
    putchar('\n');
}
// 居中函数
void center (int i)
{
    int sum;
    int x;
    //（边框总长-字符数）/2  获得居中值
    sum=(SEP-i)/2;
    //输出空格
    for(x=0;x<sum;x++)
       putchar(' ');
}
// 目录函数
void list (void)
{
    //分端口输入值
    int input;
    int x;
    int y;
    int ret;
    int (*pfArr[])(int ,int )={0,Add,Sub,Mul,Div,Xor};//函数指针数组
    int sz=sizeof(pfArr)/sizeof(pfArr[0]);//函数指针数组元素个数
    do
    {
        separator();//分隔符
        center(strlen(LIST));
        printf("%s\n",LIST);
        center(strlen(ONE));
        printf("%s\n",ONE);
        center(strlen(TWO));
        printf("%s\n",TWO);
        center(strlen(THREE));
        printf("%s\n",THREE);
        separator();
        // 添加选项值
        // center(strlen(***));
        // printf("%s\n",***);
        printf("please enter value:>");//输入目录选项
        scanf("%d",&input);
        if(input >=1 && input <=sz-1)
        {
            printf("Enter two values to compare:>");//输入两个对比的值
            scanf("%d%d",&x,&y);
            ret=(*pfArr[input])(x,y);//函数指针数组调用并将结果赋值给ret
            printf("%d\n",ret);
        }
        else if(input == 0)
        {
            printf("exit.\n");//退出
        }
        else
        {
            printf("input error.\n");//输入错误
        }
        // system("cls");

    }while(input);
}

int main()
{
    list();
    system("pause");
    return 0;
}