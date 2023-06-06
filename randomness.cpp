#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<windows.h>
#include<time.h>
//随机号码--单色号
//元素交换
void cmp(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

//快速排序数组
void sort(int* p,int sz)
{
    for(int x=0;x<sz-2;x++)//一趟
    {
        for(int y=0;y<sz-2-x;y++)
        {
            if(p[y] > p[y+1])
            {  
                //交换元素（升序）
                cmp(&p[y],&p[y+1]);
            }
        }
    }
}
void excel ()
{
    int status1,test1;
    int arr[7]={0};
    int sz=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<6; i++)//总的打印行数 
    {
        srand(time(NULL));
        for(int j=0; j<6;)//一行有7个元素 
        {
            Sleep(rand()%1010+9);
            status1= rand()%30+3;//每个随机值赋值给数组
            for(int x=0;x<6;x++)//判断每个元素是否重复
            { 
                if(arr[x] != status1)
                {
                    test1++;//判断是否递增5次
                }
            }
            if(test1 == 6)//没有重复
            {
                arr[j] = status1;//数组赋值
                j++;
                test1 = 0;       //test1 归零
            }
            else
            {
                test1 = 0;
            }
        }
        Sleep(rand()%1060+5);
        //冒泡排序
        sort(arr,sz);//传递实参数组，元素个数
        arr[6]= rand() %10+6;//单独蓝号
        for(int y=0;y<7;y++)
        {
            printf("%d ",arr[y]);
            arr[y] = 0;
            if(y == 5)
              putchar('-');
        }
        putchar('\n');
    }
}
int main()
{
    int value;
    do
    {
        printf("****1. start ******\n");
        printf("****0. quit  ******\n");
        printf("plese>:");
        scanf("%d",&value);
        putchar('\n');
        switch (value)
        {
            case 1: excel();
                break;
    
            default:
                break;
        }
    } while (value != 0);
    system("pause");
    return 0;
}