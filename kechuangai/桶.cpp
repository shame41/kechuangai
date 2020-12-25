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

//���δ��������������һ��Ԫ��ֵ
int GetMaxVal(int* arr, int len)
{
    
    int maxVal = arr[0]; //�������Ϊarr[0]
    
    for(int i = 1; i < len; i++)  //�����Ƚϣ��ҵ���ľ͸�ֵ��maxVal
    {
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }
    
    return maxVal;  //�������ֵ
}
 
//Ͱ����   ���������鼰�䳤��
void BucketSort(int* arr , int len)
{
    int tmpArrLen = GetMaxVal(arr , len) + 1;
    int tmpArr[tmpArrLen];  //��ÿ�Ͱ��С
    int i, j;
    
    for( i = 0; i < tmpArrLen; i++)  //��Ͱ��ʼ��
        tmpArr[i] = 0;
    
    for(i = 0; i < len; i++)   //Ѱ�����У����Ұ���Ŀһ��һ���ŵ���Ӧ��Ͱ��ȥ��
        tmpArr[ arr[i] ]++;
    
    for(i = 0, j = 0; i < tmpArrLen; i ++)
    {
        while( tmpArr[ i ] != 0) //��ÿ�����ǿյ�Ͱ�ӽ�������
        {
            arr[j ] = i;  //�Ӳ��ǿյ�Ͱ�������Ŀ�ٷŻ�ԭ���������С�
            j++;
            tmpArr[i]--;
        }
    }
}

