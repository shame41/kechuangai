//
#include <stdio.h>
#include <malloc.h>
void HeapAdjust(int *a,int s,int m)//һ��ɸѡ�Ĺ���
{
    int rc,j;
    rc=a[s];
    for(j=2*s;j<=m;j=j*2)//ͨ��ѭ���ؽϴ�ĺ��ӽ������ɸѡ
    {
        if(j<m&&a[j]<a[j+1])
			j++;//jΪ�ϴ�ļ�¼���±�
        if(rc>a[j])
		 	break;
        a[s]=a[j];
		s=j;
    }
    a[s]=rc;//����
}
void HeapSort(int *a,int n)
{
    int temp,i,j;
    for(i=n/2;i>0;i--)//ͨ��ѭ����ʼ������
    {
        HeapAdjust(a,i,n);
    }
    for(i=n;i>0;i--)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;//���Ѷ���¼��δ��������һ����¼����
        HeapAdjust(a,1,i-1);//���µ���Ϊ����
    }
}

