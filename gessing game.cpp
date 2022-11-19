#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<stdbool.h>
#include<math.h>
#include <time.h>
//猜数字游戏(number gessing game)
#define SEP 40 //分隔符长度
#define LIST "Number gessing game"
#define ONE "1.play"
#define TWO "2.quit"
#define JUDGE 1
// 游戏内容
void gameplay (unsigned k)
{
    unsigned i;//用户输入值
    printf("Enter the number you guessed.\n");
    while(1)
    {
        //注意
        //要先if判断大在判断小
        //如果if判断小在判断大会永远找不到要猜的数字
        if(scanf("%lu",&i) == 1)
        {
            //输入大了
            if(i>k)
              printf("You guess is worth a lot.\n");
            //输入小了
            else if(i<k)
                 printf("You guess is low.\n");
            else if(i==k)
            {
                printf("You guess bingo.\n");
                break;
            }
        }
        //读取换行符和其它字符
        else
        {
            while(getchar() != '\n')
                continue;
            continue;
        }
    }
}
// 随机函数
unsigned random(void)
{
    int k;
    //时间戳--来设置随机数起点
    srand( (unsigned)time( NULL ) );
    //模上100 随机值范围在1-99之间
    //模上1000 随机值范围在1-999之间
    k=rand()%100;
    return k;
}  
//分隔符函数
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
int list (void)
{
    separator();//分隔符
    center(strlen(LIST));
    printf("%s\n",LIST);
    center(strlen(ONE));
    printf("%s\n",ONE);
    center(strlen(TWO));
    printf("%s\n",TWO);
    separator();
    //分端口输入值
    int i;
    //判断变量
    int judge;
    //随机值
    unsigned k;
    //判断输入是否正确
    while(1)
    {
        if(scanf("%d",&i) == 1)
        {
            if(i == 1 || i == 2)
              break;
            else
              continue;
        }
        else
        {
            while(getchar() != '\n')
                continue;
            continue;
        }
    }
    // 执行分端接口
    switch(i)
    {
        //play 接口
        case 1:
            system("cls");
            k=random();
            gameplay(k);
            judge=1;
            break;
        //quit 接口
        case 2:
            system("cls");
            printf("Game over.\n");
            judge=0;
            break;
    }
    return judge;
}

int main(void)
{
    int judge;
    do
    {
        judge=list();
        system("cls");
    } while (judge == 1);
    system("pause");
    return 0;
}