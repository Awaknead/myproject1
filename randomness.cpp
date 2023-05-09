#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<windows.h>
#include<time.h>
//随机号码--单色号
int main()
{
    int stret1,stret2,stret3;
    // srand(time(NULL));//生成随机值
    // stret1=rand()%30+1;//输出随机值
    for(int j=0;j<=10;j++)
    {
        for(int i=0;i<=5;)//循环5个值
        {
            srand(time(NULL));//生成随机值
            stret1=rand()%30+2;//输出随机值
            if(stret1 != stret2)//防止重复出现
            {
                stret2=stret1;//没有重复-》赋值并输出
                printf("--%d",stret2);
                i++;  //输出5个值
            }
        }
        Sleep(1678);
        srand(time(NULL));//生成随机值
        stret3=rand()%30;
        printf("    %d\n",stret3);
        Sleep(1119);
    }
    system("pause");
    return 0;
}