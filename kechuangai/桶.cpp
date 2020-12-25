#include <stdio.h>
//void Quicksort(int*a,int begin,int end)
//{
//    int i = begin, j = end;
//    int temp;
//    if(i < j)
//	{
//        temp = a[i];
//        while (i != j)
//        {
//            while(j > i && a[j] > temp)
//			-- j;
//	            a[i] = a[j];
//            while(i < j && a[i] < temp)
//			++ i;
//	        	a[j] = a[i];	
//        }
//        a[i] = temp;
//        Quicksort(a, begin, i - 1);
//        Quicksort(a, i + 1, end);
//    }
//}

//获得未排序数组中最大的一个元素值
int GetMaxVal(int* arr, int len)
{
    
    int maxVal = arr[0]; //假设最大为arr[0]
    
    for(int i = 1; i < len; i++)  //遍历比较，找到大的就赋值给maxVal
    {
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }
    
    return maxVal;  //返回最大值
}
 
//桶排序   参数：数组及其长度
void BucketSort(int* arr , int len)
{
    int tmpArrLen = GetMaxVal(arr , len) + 1;
    int tmpArr[tmpArrLen];  //获得空桶大小
    int i, j;
    
    for( i = 0; i < tmpArrLen; i++)  //空桶初始化
        tmpArr[i] = 0;
    
    for(i = 0; i < len; i++)   //寻访序列，并且把项目一个一个放到对应的桶子去。
        tmpArr[ arr[i] ]++;
    
    for(i = 0, j = 0; i < tmpArrLen; i ++)
    {
        while( tmpArr[ i ] != 0) //对每个不是空的桶子进行排序。
        {
            arr[j ] = i;  //从不是空的桶子里把项目再放回原来的序列中。
            j++;
            tmpArr[i]--;
        }
    }
}

