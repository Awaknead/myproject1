#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>



// swap交换元素
void swap(char* e1,char*e2,int width)
{
    // char  类型1个字节
    // width 元素单位字节宽度
    // 逐个元素交换（单位字节）
    for(int x=0;x<width;x++)
    {
        int temp=*e1;
        *e1=*e2;
        *e2=temp;
        // 单个元素字节自递增直到单个元素宽度
        *e1++;
        *e2++;
    }
}
// void qsort       (void*base,
//                  size_t num,
//                  size_t width,
//                  int (* cmp)(const void *e1,const void *e2)
//                  );
// void test_qsort  (void* base,
//                  int sz,
//                  int width,
//                  int (*cmp)(void* e1,void* e2)
//                  );

//    自创快速排序函数(qsort)
void test_qsort(void* base,
                int sz,
                int width,
                int (*cmp)(void* e1,void* e2))
{
    // 趟数
    for(int i=0;i<sz-1;i++)
    {
        // 一趟比较的对数
        for(int j=0;j<sz-1-i;j++)
        {
            //两个比较的元素
            //第一个元素((char*)base+j*width)
            // (char*)  (强制转换)1个字节
            // base     首元素地址
            // j*width  第几对数乘以宽度（字节数）
            // 第二个元素((char*)base+(j+1)*width)
            // (char*)  (强制转换)1个字节
            // base     首元素地址
            // (j+1)*width  第几对数加1乘以宽度（字节数）
            if(cmp((char*)base+j*width,(char*)base+(j+1)*width) > 0 )
            {
                // 交换数组元素的内容(逐个字节交换)
                // 参数（第一个元素，第二个元素，宽度(字节数)）
                swap((char*)base+j*width,(char*)base+(j+1)*width,width);
            }
            
        }
    }
}